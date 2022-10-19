#include<bits/stdc++.h>
#define ll long long
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
const int N = 100015;
int T, n, a[N], b[N], p[N], flag[N], pre[N], id[N], pos[N];
bool res[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		rep(i, 1, n) p[i] = i;
		sort(p + 1, p + n + 1, [&](int u, int v) {
			return a[u] < a[v];
		});
		rep(i, 1, n) pre[i] = max(pre[i - 1], b[p[i]]);
		int Min = inf;
		rep(i, 1, n) res[i] = 0;
		per(i, 1, n) {
			if(pre[i] > Min || i == n) {
				res[p[i]] = 1;
				Min = min(Min, b[p[i]]);
				continue;
			} else break;
		}
		rep(i, 1, n) printf("%d", res[i]);
		printf("\n");
	}
	return 0;
}