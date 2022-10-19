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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 200015;

set<int> s[2][N];
bool ok[N << 2];
int Max[N << 2], Min[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

void upd(int p, int l, int r, int x) {
	if (l == r) {
		Max[p] = SZ(s[0][l]) ? *s[0][l].rbegin() : -inf;
		Min[p] = SZ(s[1][l]) ? *s[1][l].begin() : inf;
		ok[p] = Max[p] < Min[p];
		return ;
	}

	x <= mid ? upd(ls, l, mid, x) : upd(rs, mid + 1, r, x);
	Max[p] = max(Max[ls], Max[rs]);
	Min[p] = min(Min[ls], Min[rs]);
	ok[p] = ok[ls] && ok[rs] && Max[rs] < Min[ls];
}

int n, m, q;

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	memset(Max, -0x3f, sizeof Max);
	memset(Min,  0x3f, sizeof Min);
	fill(ok, ok + (N << 2), 1);
	scanf("%d%d%d", &n, &m, &q);
	rep(_, 1, q) {
		int x, y, o; scanf("%d%d", &x, &y);
		o = x & 1; x = (x + 1) >> 1; y = (y + 1) >> 1;

		if (s[o][x].find(y) == s[o][x].end()) s[o][x].insert(y);
		else s[o][x].erase(y);

		upd(1, 1, n, x);

		puts(ok[1] ? "YES" : "NO");
	}
	return 0;
}