#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
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
//const int maxn = 100100;

bool compare(complex<long double> a, complex<long double> b) {
	if (imag(a) == 0 && imag(b) == 0) {
		return real(a) > real(b);
	} else if (imag(a) == 0 && imag(b) != 0) {
		return true;
	} else if (imag(a) != 0 && imag(b) == 0) {
		return false;
	} else if (imag(a) != 0 && imag(b) != 0) {
		return real(a) < real(b);
	}
	return(true);
}

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

	long double ax, ay, az;
//	scanf("%Lf%Lf%Lf", &ax, &ay, &az);
	cin >> ax >> ay >> az;
	complex<long double> x(ax, 0.0L);
	complex<long double> y(ay, 0.0L);
	complex<long double> z(az, 0.0L);
	complex<long double> ansc(3, 3);
	string ans = "...";

	if(compare(z * log(y) + log(log(x)), ansc)) {
		ansc = z * log(y) + log(log(x));
		ans = "x^y^z";
	}
	if(compare(y * log(z) + log(log(x)), ansc)) {
		ansc = y * log(z) + log(log(x));
		ans = "x^z^y";
	}
	if(compare(log(y * z) + log(log(x)), ansc)) {
		ansc = log(y * z) + log(log(x));
		ans = "(x^y)^z";
	}

	if(compare(z * log(x) + log(log(y)), ansc)) {
		ansc = z * log(x) + log(log(y));
		ans = "y^x^z";
	}
	if(compare(x * log(z) + log(log(y)), ansc)) {
		ansc = x * log(z) + log(log(y));
		ans = "y^z^x";
	}
	if(compare(log(x * z) + log(log(y)), ansc)) {
		ansc = log(x * z) + log(log(y));
		ans = "(y^x)^z";
	}

	if(compare(y * log(x) + log(log(z)), ansc)) {
		ansc = y * log(x) + log(log(z));
		ans = "z^x^y";
	}
	if(compare(x * log(y) + log(log(z)), ansc)) {
		ansc = x * log(y) + log(log(z));
		ans = "z^y^x";
	}
	if(compare(log(x * y) + log(log(z)), ansc)) {
		ansc = log(x * y) + log(log(z));
		ans = "(z^x)^y";
	}

	cout << ans;

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