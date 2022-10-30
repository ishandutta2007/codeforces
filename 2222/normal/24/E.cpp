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

typedef long double ld;

int n;
pii a[555555];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) 
		scanf("%d%d", &a[i].X, &a[i].Y);
	sort(a, a + n);
	ld L = 0, R = 10e9;
	REP (k, 70) {
		ld V = (L + R) * .5;
		bool ok = false;
		ld u = -1e20;
		REP (i, n) {
			ld t = a[i].X + V * a[i].Y;
			if (a[i].Y <= 0) {
				if (t < u) { ok = true; break; }
			}
			if (a[i].Y >= 0) {
				u = max(u, t);
			}
		}
		(ok ? R : L) = V;
	}
	double res = (L + R) / 2;
	if (res > 9e9) puts("-1");
	else printf("%.30lf\n", res);
	return 0;
}