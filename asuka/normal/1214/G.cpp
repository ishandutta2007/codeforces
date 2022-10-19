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
const int N = 2005;
bitset<N> B[N], opt[N];
int n, m, q, cnt[N];
struct rule {
	bool operator () (const int u, const int v) const {
		int vu = cnt[u], vv = cnt[v];
		return vu != vv ? vu < vv : u < v;
	}
};
set<int, rule> S;
set<pii> ans;
bool check(int u, int v) { // u is subset of v
	return (B[u] | B[v]) != B[v];
}
void ins(int o) {
	auto it = S.insert(o).fi;
	if(it != S.begin() && next(it) != S.end() && check(*prev(it), *next(it))) ans.erase(mp(*prev(it), *next(it)));
	if(it != S.begin() && check(*prev(it), *it)) ans.insert(mp(*prev(it), *it));
	if(next(it) != S.end() && check(*it, *next(it))) ans.insert(mp(*it, *next(it)));
}
void del(int o) {
	auto it = S.find(o);
	if(it != S.begin() && check(*prev(it), *it)) ans.erase(mp(*prev(it), *it));
	if(next(it) != S.end() && check(*it, *next(it))) ans.erase(mp(*it, *next(it)));
	if(it != S.begin() && next(it) != S.end() && check(*prev(it), *next(it))) ans.insert(mp(*prev(it), *next(it)));
	S.erase(it);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) S.insert(i);
	rep(i, 1, m) opt[i] = opt[i - 1], opt[i][i] = 1;
	while(q--) {
		int a, l, r;
		scanf("%d%d%d", &a, &l, &r);
		del(a);
		B[a] ^= opt[l - 1];
		B[a] ^= opt[r];
		cnt[a] = B[a].count();
		ins(a);
		if(SZ(ans) > 0) {
			int u, v; tie(u, v) = *ans.begin();
			if(u > v) swap(u, v);
			int x = (B[u] & (~B[v]))._Find_first(), y = ((~B[u]) & B[v])._Find_first();
			if(x > y) swap(x, y);
			printf("%d %d %d %d\n", u, x, v, y);
		} else printf("-1\n");
	}
	return 0;
}