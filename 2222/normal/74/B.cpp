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

int n, m, k, d;
char dir[8];
string s;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	cin >> dir >> dir;
	d = dir[0] == 'h' ? -1 : +1;
	cin >> s;
	vector <bool> u(n + 1);
	u[m] = true;
	REP (i, sz(s)) {
		u[k] = false;
		if (u == vector<bool>(n + 1)) {
			printf("Controller %d\n", i);
			return 0;
		}
		if (s[i] == '0') {
			vector <bool> w = u;
			for (int i = 1; i <= n; ++i)
				if (u[i]) {
					if (i > 1) w[i - 1] = true;
					if (i < n) w[i + 1] = true;
				}
			u.swap(w);
			u[k] = false;
		} else {
			for (int i = 1; i <= n; ++i)
				u[i] = true;
		}
		if (u == vector<bool>(n + 1)) {
			printf("Controller %d\n", i);
			return 0;
		}
		k += d;
		if (k < 1 || k > n) {
			d = -d;
			k += 2 * d;
		}
	}
	puts("Stowaway");
	return 0;
}