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

int n, m, k;

double F(int n, int k) {
	double res = 1;
	for (int i = 0; i < k; ++i)
		res *= n - i;
	return res;
}

double C(int k, int n) {
	double res = 1;
	for (int i = 0; i < k; ++i)
		res *= n - i,
		res /= i + 1;
	return res;
}

double f() {
	if (n + k < m) return 0;
	return 1 - F(m, k + 1) / F(n + k + 1, k + 1);
	return 1 - C(m - k - 1, n + m) / C(n, n + m);
}

double f(int n, int m, int k) {
	if (k < 0) return 0;
	if (n < 0) return 0;
	if (m < 0) return 0;
	if (m == 0) return 1;
	return f(n - 1, m, k + 1) + f(n, m - 1, k - 1);
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
//	for (int i = 2; i <= k; i += 2)
	//	res -= f(i, i) * f(n + k - i, m);
	printf("%.18lf\n", f());
//	printf("%.18lf\n", f(n, m, k) / C(n, n + m));
	return 0;
}