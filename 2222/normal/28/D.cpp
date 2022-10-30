#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define N	111111

int n, v[N], c[N], l[N], r[N];
pii p[N], f[N + N];

int setmax(int i, pii v) {
	for (i += n; i && f[i] < v; i /= 2)
		f[i] = v;
}

pii getmax(int i, int j) {
	pii res(-2000000000,0);
	for (i += n, j += n; i <= j; i = (i + 1) / 2, j = (j - 1) / 2)
		res = max(res, max(f[i], f[j]));
	return res;
}

int prev[N];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", v + i, c + i, l + i, r + i);
		p[i] = pii(l[i] + c[i], r[i]);
	}
	sort(p, p + n);
	fill(f, f + (n + n), pii(-2000000000, 0));
	pii res(-2000000000, 0);
	for (int i = 0; i < n; ++i) {
		int k = lower_bound(p, p + n, pii(l[i] + c[i], r[i])) - p;
		if (l[i] == 0)
			setmax(k, pii(v[i], i)), prev[i] = -1;
		else {
			pair <pii*, pii*> t = equal_range(p, p + n, pii(l[i], r[i] + c[i]));
			pii u = getmax(t.X - p, t.Y - p - 1);
			u.X += v[i];
			if (u > f[k + n]) {
				prev[i] = u.Y;
				u.Y = i;
				setmax(k, u);
			}
		}
		if (r[i] == 0) res = max(res, f[k + n]);
	}
	if (res.X < 0) {
		puts("0");
		puts("");
		return 0;
	}
	vector <int> s;
	for (; ~res.Y; res.Y = prev[res.Y])
		s.pb(res.Y + 1);
	reverse(all(s));
	cout << s.size() << endl;
	REP (i, sz(s)) {
		if (i) putchar(' ');
		printf("%d", s[i]);
	}
	cout << endl;
	return 0;
}