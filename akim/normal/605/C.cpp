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
const int maxn = 300100;

pair<double, double> a[maxn], ch[maxn], up[maxn], dw[maxn];
int asz, chsz, upsz, dwsz;

double pl(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
	return(a.fs * (b.sc - c.sc) + b.fs * (c.sc - a.sc) + c.fs * (a.sc - b.sc));
}

void buildch() {
	if(asz == 1) {
		chsz = 1;
		ch[0] = a[0];
	}
	chsz = 0, upsz = 0, dwsz = 0;
	sort(&a[0], &a[asz]);
	pair<double, double> p1 = a[0], p2 = a[asz - 1];
	up[upsz++] = p1;
	for(int i = 1; i < asz; i++) {
		if(i == asz - 1 || pl(p1, a[i], p2) > eps) {
			while(upsz > 1 && pl(up[upsz - 2], up[upsz - 1], a[i]) <= eps) {
				upsz--;
			}
			up[upsz++] = a[i];
		}
	}
	dw[dwsz++] = p2;
	for(int i = asz - 1; i >= 0; i--) {
		if(i == 0 || pl(p2, a[i], p1) > eps) {
			while(dwsz > 1 && pl(dw[dwsz - 2], dw[dwsz - 1], a[i]) <= eps) {
				dwsz--;
			}
			dw[dwsz++] = a[i];
		}
	}
	for(int i = 0; i < upsz; i++) {
		ch[chsz++] = up[i];
	}
	for(int i = 1; i < dwsz - 1; i++) {
		ch[chsz++] = dw[i];
	}
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

	int n;
	double p, q;
	scanf("%d%lf%lf", &n, &p, &q);
	a[asz++] = mp(0, 0);
	for(int i = 0; i < n; i++) {
		scanf("%lf%lf", &a[asz].fs, &a[asz].sc);
		a[asz + 1].fs = a[asz].fs;
		a[asz + 1].sc = 0.;
		a[asz + 2].fs = 0.;
		a[asz + 2].sc = a[asz].sc;
		asz += 3;
	}

	buildch();

	ch[chsz++] = ch[0];

	double ans = 1e40;
	for(int i = 1; i < chsz - 1; i++) {
		double s1 = ch[i].fs * ch[i + 1].sc - ch[i + 1].fs * ch[i].sc;
		double s2 = (ch[i + 1].sc * p - ch[i + 1].fs * q) / s1;
		double s3 = -(ch[i].sc * p - ch[i].fs * q) / s1;
		if(s2 > -eps && s3 > -eps) {
			ans = min(ans, s2 + s3);
		}
	}

	printf("%.10lf", ans);

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