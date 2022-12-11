#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

ll x[maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	ll n, vb, vs;
	cin >> n >> vb >> vs >> x[0];
	for(int i = 1; i < n; i++) {
		scanf("%d", &x[i]);
	}
	ll x0, y0;
	cin >> x0 >> y0;

	double ans = 1e39;
	ll idx = mod;
	ll dist = 0;

	for(int i = 1; i < n; i++) {
		dist += abs(x[i] - x[i - 1]);
		if(abs(ans - dist * 1. / vb - sqrt(sqr(x0 - x[i]) + sqr(y0)) / vs) < eps) {
			if(sqr(x0 - x[i]) + sqr(y0) < sqr(x0 - x[idx]) + sqr(y0)) {
				idx = i;
			}
		} else
		if(ans > dist * 1. / vb + sqrt(sqr(x0 - x[i]) + sqr(y0)) / vs) {
			ans = dist * 1. / vb + sqrt(sqr(x0 - x[i]) + sqr(y0)) / vs;
			idx = i;
		}
	}

	cout << idx + 1;


	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim