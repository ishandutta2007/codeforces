#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & -(x))
const int P = 998244353; int N , M , arr[200003] , T[200003];
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
void add(int x , int v){while(x <= 2e5){arr[x] += v; x += lowbit(x);}}
int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M; for(int i = 1 ; i <= N ; ++i){int x; cin >> x; add(x , 1);}
	for(int i = 1 ; i <= M ; ++i) cin >> T[i];
	int ans = 0 , fac = 1; for(int i = 1 ; i <= N ; ++i) fac = 1ll * fac * i % P;
	for(int i = 1 ; i <= 2e5 ; ++i) for(int j = qry(i) - qry(i - 1) ; j ; --j) fac = 1ll * fac * poww(j , P - 2) % P;
	for(int i = 1 ; i <= min(N , M) ; ++i){
		fac = 1ll * fac * poww(N - i + 1 , P - 2) % P; ans = (ans + 1ll * fac * qry(T[i] - 1)) % P;
		if(qry(T[i]) != qry(T[i] - 1)){fac = 1ll * fac * (qry(T[i]) - qry(T[i] - 1)) % P; add(T[i] , -1);} else break;
		if(i == N) ans = (ans + (i < M)) % P;
	}
	cout << ans; return 0;
}