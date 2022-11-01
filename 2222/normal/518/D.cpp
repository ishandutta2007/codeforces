#include <algorithm>
#include <iostream>
#include <assert.h>
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

double F[2222][2222];

double p;

double f(int n, int t)
{
	if (t == 0 || n == 0)
		return 0;
	double &res = F[n][t];
	if (res < -1) {
		res = p * f(n - 1, t - 1) + p + (1 - p) * f(n, t - 1);
	}
	return res;
}

int main() {
	int n, t;
	for (; cin >> n >> p >> t; ) {
		CL(F, -2);
		printf("%.8lf\n", f(n, t));
	}
    return 0;
}