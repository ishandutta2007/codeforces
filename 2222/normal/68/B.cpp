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

int n;
double k, a[11111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> k;
	k = (100 - k) / 100;
	REP (i, n) cin >> a[i];
	sort(a, a + n);
	double L = 0, R = 1000, V;
	REP (kk, 128) {
		V = (L + R) * 0.5;
		double q = 0;
		REP (i, n) 
			q += a[i] > V ? V + (a[i] - V) * k : a[i];
		q /= n;
		(q < V ? R : L) = V;
	}
	printf("%.12lf\n", (L + R) * 0.5);
	return 0;
}