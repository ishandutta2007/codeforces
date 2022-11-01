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

char a[111111], b[111111], c[111111];
int f[26][26];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%s%s", a, b);
	int n;
	cin >> n;
	REP (i, 26) REP (j, 26) f[i][j] = -1u/4;
	REP (i, 26) f[i][i] = 0;
	REP (i, n) {
		char x[3], y[3];
		int w;
		cin >> x >> y >> w;
		f[*x - 'a'][*y - 'a'] = min(f[*x - 'a'][*y - 'a'], w);
	}
	REP (k, 26) REP (i, 26) REP (j, 26) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	ll res = 0;
	int na = strlen(a), nb = strlen(b);
	if (na != nb) res = -1ull/2;
	else 
		REP (i, na) {
			int g = -1u/4;
			int x = a[i] - 'a', y = b[i] - 'a';
			REP (k, 26) if (f[x][k] + f[y][k] < g) {
				g = f[x][k] + f[y][k];
				c[i] = k + 'a';
			}
			res += g;
		}
	if (res < -1u/4) {
		cout << res << endl;
		puts(c);
	} else cout << -1 << endl;
	return 0;
}