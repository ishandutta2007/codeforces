#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 55;

vector<int> rown[maxn], coln[maxn];
bool kek[maxn][maxn];
bool used[2][maxn];
int stk[2][maxn];
int ptr[2];
int n, m;

void fail(){
	printf("No");
	exit(0);
}

void go(int v, int tp){
	used[tp][v] = true;
	stk[tp][ptr[tp]++] = v;
	if(tp == 0){
		I(u, rown[v])if(!used[1 - tp][u])go(u, 1 - tp);
	}
	else{
		I(u, coln[v]){if(!used[1 - tp][u])go(u, 1 - tp);}
	}
}

signed main(){
	sync;
	scanf("%d%d", &n, &m);
	F(i, 0, n){
		F(j, 0, m){
			char c = getc(stdin);
			while(c != '.' && c != '#')c = getc(stdin);
			if(c == '#'){
				kek[i][j] = true;
				rown[i].pb(j); coln[j].pb(i);
			}
		}
	}
	F(i, 0, n){
		if(used[0][i])cont;
		ptr[0] = ptr[1] = 0;
		go(i, 0);
		F(j, 0, ptr[0])
			F(k, 0, ptr[1]){
				if(!kek[stk[0][j]][stk[1][k]])fail();
			}
	}
	printf("Yes");
	ret 0;
}