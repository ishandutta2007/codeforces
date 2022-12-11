#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

double x[1100];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n, l;
	double ans = 0.;
	scanf("%d%d", &n, &l);
	for(int i = 0; i < n; i++) {
		scanf("%lf", &x[i]);
	}
	sort(x, x + n);
	ans = max(x[0], l - x[n - 1]);
	for(int i = 0; i < n - 1; i++) {
		ans = max(ans, (x[i + 1] - x[i]) / 2);
	}
	printf("%.9lf", ans);

	return(0);
}

// by Kim Andrey