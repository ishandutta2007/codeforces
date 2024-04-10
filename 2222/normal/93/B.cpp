#include <algorithm>
#include <iostream>
#include <assert.h>
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

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n, w, m;
	cin >> n >> w >> m;
	vector<double> a(n, w);
	vi c(n);
	vector<vector<pair<int, double>>> res;
	REP (i, m) {
		double q = double(n) * w / m;
		vector<pair<int, double>> v;
		REP (j, n) {
			double h = min(q, a[j]);
			if (h > 1e-9) {
				v.push_back({j + 1, h});
				q -= h;
				a[j] -= h;
				if (++c[j] > 2) {
					puts("NO");
					return 0;
				}
			}
		}
		res.pb(v);
	}
	puts("YES");
	for (auto t : res) {
		for (auto q : t)  
			printf("%d %.8lf ", q.X, q.Y);
		puts("");
	}
	return 0;
}