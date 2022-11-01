#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <bitset>
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

int n, m;
bitset <770> a[770];
int a2[770][770], d[770];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	#if 1
	scanf("%d%d", &n, &m);
	REP (i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		a[x].set(y);
		a[y].set(x);
	}
	#else
	n = 700;
	REP (i, n) REP (j, n) if (i != j) a[i].set(j);
	#endif
	ll res = 0;
	REP (x, n) {
		d[x] = a[x].count();
		int *c = a2[x];
		REP (y, n) {
			c[y] = (a[x] & a[y]).count();
			if (x == y) c[y] = 0;
		}
		REP (y, n) {
			if (c[y] == 0) continue;
			REP (z, n) {
				if (c[z] == 0) continue;
				if (a[y][z]) res += c[y] * c[z];
			}
		}
	}
	ll P = 0, Q = 0;
	REP (z, n) REP (y, z) if (a[y][z]) 
		REP (x, y) if (a[x][y] && a[x][z]) {
			P += d[x] + d[y] + d[z];
			++Q;
		}
	res -= P * 6;
	res += Q * 30;
	cout << res / 10 << endl;
	return 0;
}