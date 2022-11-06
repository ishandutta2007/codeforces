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

pii a[maxn];
int d[maxn];
int x[maxn];
int N, M;

bool cmp(int a, int b) {
	return d[a] > d[b] || d[a] == d[b] && a < b;
}

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first || a.first == b.first && (d[a.second] > d[b.second] || d[a.second] == d[b.second] && a.second < b.second);
}

int lk[maxn];

int main() {
	N = read(), M = read();
	rep(i, 1, M) {
		int u = read(), v = read();
		if (u > v) swap(u, v);
		a[i] = mp(u, v);
		d[u]++, d[v]++;
	}
	rep(i, 0, N) x[i] = i, lk[i] = i+1;
	sort(a+1, a+M+1, comp);
	sort(x+1, x+N+1, cmp);
	for (register int l = 1, r = 1, i = 1; i <= N; l = r, i++) {
		while (a[r].first == i) r++;
		int pt = 0, last = 0;
		while ((last = pt, pt = lk[pt]) <= N) {
			int now = d[i] + d[x[pt]], _l = l;
			while (_l < r && a[_l].second == x[pt]) _l++;
			now -= _l - l;
			if (i >= x[pt]) { lk[last] = lk[pt]; continue; }
			if (now == M) { printf("YES"); return 0; }
			if (l == _l) break;
			l = _l;
		}
	}
	printf("NO");
	return 0;
}