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

pair<double, int> alpha[maxn];
double x[maxn], y[maxn];
set<pair<double, double> > st;

double ansx[maxn], ansy[maxn];

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

	int n;
	scanf("%d", &n);
	double v;
	scanf("%lf", &v);
	for(int i = 0; i < n; i++) {
		scanf("%lf", &alpha[i].fs);
		alpha[i].sc = i;
	}
	sort(&alpha[0], &alpha[n]);

	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%lf%lf", &x[i], &y[i]);
		st.insert(mp(x[i], y[i]));
	}

	for(int i = 0; i < n; i++) {
		int cr = alpha[i].sc;
		bool emp = 0;
		double xx, yy;
		while(1) {
			if(st.empty()) {emp = 1; break;}
			double t = (st.begin() -> fs) / (v * cos(alpha[i].fs));
			double y = v * sin(alpha[i].fs) * t - 4.9 * sqr(t);
			if(y - eps > (st.begin() -> sc)) {
				st.erase(st.begin());
			} else {
				xx = st.begin() -> fs;
				yy = y;
				break;
			}
		}
		if(emp || yy < -eps) {
			double t = v * sin(alpha[i].fs) / 4.9;
			xx = v * cos(alpha[i].fs) * t;
			yy = 0;
		}
		ansx[cr] = xx;
		ansy[cr] = yy;
	}

	for(int i = 0; i < n; i++) {
		printf("%.10lf %.10lf\n", ansx[i], ansy[i]);
	}

	return(0);
}

// by Kim Andrey