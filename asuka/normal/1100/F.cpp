#include<bits/stdc++.h>
#define ll long long
#define N 500015
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
namespace LinearBase {
	int D[20], pos[20];
	void ins(int x, int id) {
		per(i, 0, 19) {
			if(!(x >> i & 1)) continue;
			if(!D[i]) {
				D[i] = x;
				pos[i] = id;
				return;
			}
			if(pos[i] < id) swap(x, D[i]), swap(id, pos[i]);
			x ^= D[i];
		}
	}
	int query(int l) {
		int x = 0;
		per(i, 0, 19) {
			if(pos[i] >= l) x = max(x, x ^ D[i]);
		}
		return x;
	}
}
using namespace LinearBase;
vector<pii> que[N];
int n, q, c[N], ans[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &c[i]);
	scanf("%d", &q);
	rep(i, 1, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		que[r].emplace_back(l, i);
	}
	rep(i, 1, n) {
		ins(c[i], i);
		for(auto x : que[i]) ans[x.se] = query(x.fi);
	}
	rep(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}