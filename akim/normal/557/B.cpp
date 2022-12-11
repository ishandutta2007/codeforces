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

int a[3 * maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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

	int n, w;
	scanf("%d%d", &n, &w);
	double mx = (w * 1.) / (3. * n);
	for(int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
	}
	sort(&a[0], &a[2 * n]);
	for(int i = 0; i < n; i++) {
		mx = min(a[i] * 1., mx);
	}
	for(int i = 0; i < n; i++) {
		mx = min(a[n + i] * 0.5, mx);
	}
	cout.precision(10);
	cout << mx * 3. * n;
//	printf("%.10lf", mx);

	return(0);
}

// by Kim Andrey