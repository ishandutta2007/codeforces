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

	double a, v;
	cin >> a >> v;
	double l, d, w;
	cin >> l >> d >> w;

	double tw = w / a;
	double sw = a * sqr(tw) / 2.;
	double tf = v / a;
	double sf = a * sqr(tf) / 2.;

	if(w > v) {
		double sa = min(sf, l);
		double t = sqrt(2. * sa / a) + (l - sa) / v;
		cerr << 1 << endl;
		printf("%.10lf", t);
		return(0);
	}

	if(sw > d) {
		double sa = min(sf, l);
		double t = sqrt(2. * sa / a) + (l - sa) / v;
		cerr << 2 << endl;
		printf("%.10lf", t);
		return(0);
	}

	double ss = d + sw;
	double t1, t2;
	if(ss < 2 * sf) {
		ss /= 2.;
		double v0 = sqrt(a * 2. * ss);
		a = -a;
		double dis = sqr(v0) - 2 * a * (-(d - ss));
		double td = (-v0 + sqrt(dis)) / (a);
		a = -a;
		t1 = sqrt(2. * ss / a) + td;
		cerr << 3 << " " << 1 << endl;
	} else {
		ss -= sf;
		double v0 = v;
		a = -a;
		double dis = sqr(v0) - 2 * a * (-(d - ss));
		double td = (-v0 + sqrt(dis)) / (a);
		a = -a;
		t1 = tf + (ss - sf) / v + td;
		cerr << 3 << " " << 2 << endl;
	}

	if(l - d >= sf - sw) {
		t2 = (tf - tw) + (l - (sf - sw + d)) / v;
		cerr << 3 << " " << 3 << endl;
	} else {
		double v0 = w;
		double dis = sqr(v0) - 2 * a * (-(l - d));
		double td = (-v0 + sqrt(dis)) / (a);
		t2 = td;
		cerr << 3 << " " << 4 << endl;
	}

//	cout << t1 << " " << t2 << endl;

	printf("%.10lf", t1 + t2);

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