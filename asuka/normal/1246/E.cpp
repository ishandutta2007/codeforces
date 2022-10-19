#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, k, a[16];
bitset<2001> f[1 << 16];
vector<int> v[444];

void gao(int s, int x, int l) {
	if (!s && !x) return;

	rep(i, 0, n - 1) {
		if (s >> i & 1 && x >= a[i]
			&& f[s ^ (1 << i)][x - a[i]]) {
			v[l].pb(a[i]);
			return gao(s ^ (1 << i), x - a[i], l);
		}
	}

	gao(s, x * k, l - 1);
}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 0, n - 1) scanf("%d", &a[i]);
	f[0][0] = 1;

	rep(s, 1, (1 << n) - 1) {
		rep(i, 0, n - 1) if (s >> i & 1)
			f[s] |= f[s ^ (1 << i)] << a[i];
		for (int i = 2000 / k; i >= 0; i--)
			if (f[s][i * k]) f[s][i] = 1;
	}

	if (!f[(1 << n) - 1][1]) return puts("NO"), 0;
	puts("YES");
	gao((1 << n) - 1, 1, 200);

	rep(l, 0, 400) {
		for (int i = 0; i + 1 < SZ(v[l]); i += 2) {
			int x = v[l][i], y = v[l][i + 1], nl = l;
			printf("%d %d\n", x, y);
			x += y;
			while (x % k == 0) x /= k, nl++;
			v[nl].pb(x);
		}
	}

	return 0;
}