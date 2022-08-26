#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7 , __ = _ * 30 , P = 998244353; int ch[__][2] , sz[__] , N , X , cnt = 1;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
void ins(){int A; cin >> A; int R = 1; for(int i = 29 ; ~i ; --i){if(!ch[R][A >> i & 1]){ch[R][A >> i & 1] = ++cnt;} R = ch[R][A >> i & 1]; ++sz[R];}}
struct dat{int ans[4]; int& operator [](int x){return ans[x];} dat(){memset(ans , 0 , sizeof(ans));}};
int qans(dat x){return (0ll + x[1] + x[2] + x[3]) % P;}
dat operator +(dat p , dat q){for(int i = 0 ; i < 4 ; ++i){p[i] = (p[i] + q[i]) % P;} return p;}
dat operator *(dat p , dat q){dat r; for(int i = 0 ; i < 4 ; ++i) for(int j = 0 ; j < 4 ; ++j) r[i | j] = (r[i | j] + 1ll * p[i] * q[j]) % P; return r;}

dat makeans(int, int, int);
dat solve(int r1 , int r2 , int dep){
	dat ans; ans[0] = 1;
	if(r1 || r2)
		if(r1 == r2)
			if(dep == -1) ans[3] = poww(2 , sz[r1]) - 1;
			else if(X >> dep & 1) ans = makeans(ch[r1][0] , ch[r1][1] , dep - 1);
			else{ans[1] = qans(solve(ch[r1][0] , ch[r2][0] , dep - 1)); ans[2] = qans(solve(ch[r1][1] , ch[r2][1] , dep - 1));}
		else
			if(dep == -1){ans[1] = poww(2 , sz[r1]) - 1; ans[2] = poww(2 , sz[r2]) - 1; ans[3] = 1ll * ans[1] * ans[2] % P;}
			else if(X >> dep & 1) ans = makeans(ch[r1][0] , ch[r2][1] , dep - 1) * makeans(ch[r1][1] , ch[r2][0] , dep - 1);
			else ans = solve(ch[r1][0] , ch[r2][0] , dep - 1) + solve(ch[r1][1] , ch[r2][1] , dep - 1);
	return ans;
}
dat makeans(int x , int y , int d){dat ans; ans[0] = 1; ans[1] = poww(2 , sz[x]) - 1; ans[2] = poww(2 , sz[y]) - 1; ans[3] = solve(x , y , d)[3]; return ans;}

int main(){ios::sync_with_stdio(0); cin >> N >> X; for(int i = 1 ; i <= N ; ++i){ins();} cout << qans(solve(1 , 1 , 29)); return 0;}