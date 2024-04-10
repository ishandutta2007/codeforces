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
string a[1111], r[1111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	string z = "1000";
	REP (i, n) {
		cin >> a[i];
		r[i] = "9999";
		if (a[i] >= z) r[i] = a[i];
		REP (j, 4) {
			string v = a[i];
			REP (d, 10) {
				v[j] = d + '0';
				if (v >= z && v < r[i]) r[i] = v;
			}
		}
		if (r[i] > "2011") {
			puts("No solution");
			return 0;
		}
		z = r[i];
	}
	REP (i, n) cout << r[i] << endl;
	return 0;
}