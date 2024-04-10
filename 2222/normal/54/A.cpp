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

int n, m, k;
int x[400];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> k >> m;
	REP (i, m) cin >> x[i];
	x[m] = -1u/2;
	sort(x, x + m);
	int l = 0, res = 0;
	for (int i = 1, j = 0; i <= n; ++i) {
		bool ok = false;
		if (i - l >= k) ok = true;
		if (x[j] == i) ++j, ok = true;
		if (ok) {
			++res;
			l = i;
		}
	}
	cout << res << endl;
	return 0;
}