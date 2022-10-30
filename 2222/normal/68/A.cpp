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

int p[4], a, b;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	REP (i, 4) cin >> p[i];
	cin >> a >> b;
	sort(p, p + 4);
	int res = 0;
	for (int x = a; x <= b; ++x) {
		int c = 0;
		REP (k, 24) {
			int y = x % p[0] % p[1] % p[2] % p[3];
			if (x == y) ++c;
			next_permutation(p, p + 4);
		}
		if (c >= 7) ++res;
	}
	cout << res << endl;
	return 0;
}