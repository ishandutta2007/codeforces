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
const int maxn = 2 * 100100;

double a[maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n, t; double c;
	cin >> n >> t >> c;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	double mean = 0., sum = 0.;

	int m, f = 0;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x; x--;
		while(f <= x) {
			sum += a[f];
			if(f - t >= 0) sum -= a[f - t];
			mean = (mean + a[f] / (t + 0.)) / c;
			f++;
		}
		double real = sum / t;
		cout.precision(12);
		printf("%.12lf %.12lf %.12lf\n", real, mean, (abs(real - mean) / real));
	}

	return(0);
}

// by Kim Andrey