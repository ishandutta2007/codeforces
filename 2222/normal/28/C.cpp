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

int n, m, a[55];

double F[55][55][55], G[55][2][55][55];

double f(int n, int k, int m) {
	if (n == 0) return k == 0;
	if (k < 0) return 0;
	double &res = F[m][n][k];
	if (res < -1) res = (f(n - 1, k - 1, m) + f(n - 1, k, m) * (m - 1)) / m;
	return res;
}

double g(int n, int i, int max, bool used) {
	if (n < 0) return 0;
	if (i == m) return used;
	double &res = G[max][used][n][i];
	if (res < -1) {
		res = 0;
		REP (j, n + 1) {
			int k = (j + a[i] - 1) / a[i];
			if (k <= max) res += f(n, j, m - i) * g(n - j, i + 1, max, used || k == max);
		}
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	CL(F, -2), CL(G, -2);
	cin >> n >> m;
	double res = 0;
	REP (i, m) cin >> a[i];
	REP (k, n + 1) res += k * g(n, 0, k, 0);
	printf("%.16lf\n", res);
	return 0;
}