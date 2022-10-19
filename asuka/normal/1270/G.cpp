#include<bits/stdc++.h>
#define ll long long
#define N 1000015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, a[N], to[N];
bool vis[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]), to[i] = i - a[i];
		rep(i, 1, n) vis[i] = 0;
		VI stk, vec;
		int u = 1;
		while(!vis[u]) {
			stk.pb(u);
			vis[u] = 1;
			u = to[u];
		}
		per(i, 0, SZ(stk) - 1) {
			vec.pb(stk[i]);
			if(stk[i] == u) break;
		}
		printf("%d\n", SZ(vec));
		for(auto x : vec) printf("%d ", x);
		printf("\n");
	}
	return 0;
}