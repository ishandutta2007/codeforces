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

int n, k, e, d[111];
double p[111], F[111][111];

double f(int i, int k) {
	if (k == 0) return 1;
	if (i == n) return 0;
	double &res = F[i][k];
	if (res < -1) res = f(i + 1, k - 1) * p[i] + f(i + 1, k) * (1 - p[i]);
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> k >> e;
	{
		int x, y, x0, y0;
		cin >> x0 >> y0;
		REP (i, n) {
			cin >> x >> y;
			x -= x0;
			y -= y0;
			d[i] = x * x + y * y;
		}
	}
	double L = 0, R = 1e4;
	REP (l00, 100) {
		double V = (L + R) * 0.5, V2 = V * V;
		REP (i, n) {
			if (V > 1e-9) p[i] = min(1.0, exp(1 - d[i] / V2));
			else p[i] = d[i] < 1e-9;
		}
		CL(F, -2);
		((1 - f(0, k)) * 1000 >= e ? L : R) = V;
	}
	printf("%.12lf\n", (max(0.0, (L + R) * 0.5)));
	return 0;
}