#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define rep(i, a, b) for (register int i = a, end = b; i <= end; ++i)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; --i)
#define INf (1<<30)

inline int read() {
	int w = 0, f = 1; char c;
	while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
	return w * f;
}

const int maxn = 300000 + 5;
const int MOD1 = 998244353, MOD2 = 1000000007, SIZE = 1949101;
vector<pair<pii, int> > Hash[SIZE];

int T, N, a[maxn];
int st[maxn], top, Hash1[maxn], Hash2[maxn], Hash3[maxn];

void insert(int h1, int h2, int h3) {
	for (register int i = 0; i < (int)Hash[h3].size(); ++i)
		if (Hash[h3][i].first == mp(h1, h2)) {
			Hash[h3][i].second++;
			return;
		}
	Hash[h3].push_back(mp(mp(h1, h2), 1));
}

int getcnt(int h1, int h2, int h3) {
	for (register int i = 0; i < (int)Hash[h3].size(); ++i)
		if (Hash[h3][i].first == mp(h1, h2))
			return Hash[h3][i].second;
	return 0;
}

ll divide(int l, int r) {
	if (l >= r) return 0;
	vector<int> pos;
	int mid = l+r>>1;
	ll ans = 0;
	top = 0;
	repd(i, mid, l) {
		if (top && st[top] == a[i]) {
			top--;
			insert(Hash1[top], Hash2[top], Hash3[top]);
		} else {
			st[++top] = a[i];
			insert(Hash1[top] = (1ll*Hash1[top-1]*N+a[i])%MOD1, Hash2[top] = (1ll*Hash2[top-1]*N+a[i])%MOD2, Hash3[top] = (1ll*Hash3[top-1]*N+a[i])%SIZE);
		}
		pos.push_back(Hash3[top]);
	}
	top = 0;
	rep(i, mid+1, r) {
		if (top && st[top] == a[i]) {
			top--;
			ans += getcnt(Hash1[top], Hash2[top], Hash3[top]);
		} else {
			st[++top] = a[i];
			ans += getcnt(Hash1[top] = (1ll*Hash1[top-1]*N+a[i])%MOD1, Hash2[top] = (1ll*Hash2[top-1]*N+a[i])%MOD2, Hash3[top] = (1ll*Hash3[top-1]*N+a[i])%SIZE);
		}
	}
	for (register int i = 0; i < (int)pos.size(); ++i) Hash[pos[i]].clear();
	return ans + divide(l, mid) + divide(mid+1, r);
}

int main() {
	T = read();
	while (T--) {
		N = read();
		rep(i, 1, N) a[i] = read();
		printf("%lld\n", divide(1, N));
	}

	return 0;
}