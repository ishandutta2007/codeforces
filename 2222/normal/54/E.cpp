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

ll det(ll a, ll b, ll c, ll d) { return a * d - b * c; }
ll dot(ll a, ll b, ll c, ll d) { return a * c + b * d; }

pii p[44444 * 2];
ll ar[44444 * 2];
int n;

void orient() {
	p[n] = p[0];
	ll s = 0;
	REP (i, n) s += det(p[i].X, p[i].Y, p[i + 1].X, p[i + 1].Y);
	if (s < 0) reverse(p, p + n);
}

double F(pii a, pii b, pii c) {
	double a1 = a.X - b.X, b1 = a.Y - b.Y, c1 = c.X * a1 + c.Y * b1;
	double a2 = b1, b2 = -a1, c2 = b.X * a2 + b.Y * b2;
	return	(a1 * b.X + b1 * b.Y - c1) * 
			(a2 * c.X + b2 * c.Y - c2) /
			(
			sqrt(a1 * a1 + b1 * b1) *
			sqrt(a2 * a2 + b2 * b2) 
			);
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) scanf("%d%d", &p[i].X, &p[i].Y);
	orient();
	REP (i, n + 1) p[i + n] = p[i];
	#ifdef LocalHost
	REP (i, n) cout << p[i].X << ' ' << p[i].Y << endl;
	cout << endl;
	#endif
	REP (i, n + n + 1) 
		ar[i + 1] = ar[i] + det(p[i].X, p[i].Y, p[i + 1].X, p[i + 1].Y);
	for (int i = 1; i <= n; ++i) {
		if (dot(p[i + 1].X - p[i].X, p[i + 1].Y - p[i].Y, p[i - 1].X - p[i].X, p[i - 1].Y - p[i].Y) >= 0) {
			puts("0.0");
			return 0;
		}
	}
	double res = 1e20;
	REP (rr, 2) {
		int j = 0;
		REP (i, n) {
			j = max(i + 1, j);
			for (; j < n + n && dot(p[i + 1].X - p[i].X, p[i + 1].Y - p[i].Y, p[j + 1].X - p[j].X, p[j + 1].Y - p[j].Y) > 0; ++j);
			if (j == n + n) break;
			ll S = ar[j] - ar[i + 1] + det(p[j].X, p[j].Y, p[i + 1].X, p[i + 1].Y);
			res = min(res, F(p[i], p[i + 1], p[j]) - S);
		}
		reverse(p + 1, p + (n + n));
		REP (i, n + n + 1) 
			p[i].X = -p[i].X;
		REP (i, n + n + 1) 
			ar[i + 1] = ar[i] + det(p[i].X, p[i].Y, p[i + 1].X, p[i + 1].Y);
	}
	printf("%.16lf\n", res * 0.5);
	return 0;
}