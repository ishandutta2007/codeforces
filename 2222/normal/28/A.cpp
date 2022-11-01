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

int n, m;
pii p[555];
int l[555];
bool b[555];

int dist(pii *p, int i, int j) { return abs(p[i].X - p[j].X) + abs(p[i].Y - p[j].Y); }

vi solve(pii *p) {
	CL(b, 0);
	vi res(n, -1);
	for (int i = 1; i < n; i += 2) {
		int w = dist(p, i - 1, i) + dist(p, i, i + 1);
		for (int j = 0; ; ++j) {
			if (j == m) return vi();
			if (!b[j] && l[j] == w) {
				b[j] = true;
				res[i] = j + 1;
				break;
			}
		}
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m;
	REP (i, n) cin >> p[i].X >> p[i].Y;
	p[n] = p[0];
	p[n + 1] = p[1];
	p[n + 2] = p[2];
	REP (i, m) cin >> l[i];
	vi res = solve(p);
	if (!sz(res)) {
		res = solve(p + 1);
		if (sz(res)) {
			res.insert(res.begin(), res.back());
			res.pop_back();
		}
	}
	if (sz(res)) {
		puts("YES");
		REP (i, sz(res)) {
			if (i) putchar(' ');
			printf("%d", res[i]);
		}
		puts("");
	} else puts("NO");
	return 0;
}