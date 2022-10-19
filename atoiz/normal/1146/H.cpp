/*input
10
841746 527518
595261 331297
-946901 129987
670374 -140388
-684770 309555
-302589 415564
-387435 613331
-624940 -95922
945847 -199224
24636 -565799
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define x first
#define y second

// start of code

ll nCk(int n, int k)
{
	ll ans = 1;
	FORB(i, n, n-k+1) ans *= i;
	FOR(i, 1, k) ans /= i;
	return ans;
}

const int MAXN = 305;
pll pnt[MAXN];
int cnt[MAXN][MAXN];

int ccw(pll p0, pll p1, pll p2)
{
	ll cross = (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
	if (cross < 0) return -1;
	if (cross > 0) return +1;
	return 0;
}

#define less lesss
bool less(pll l, pll r)
{
	return (l.x != r.x ? l.x < r.x : l.y > r.y);
}

int get(int i, int j, int k)
{
	if (less(pnt[j], pnt[i])) swap(i, j);
	if (less(pnt[k], pnt[j])) swap(j, k);
	if (less(pnt[j], pnt[i])) swap(i, j);

	if (ccw(pnt[i], pnt[k], pnt[j]) < 0) 
		return cnt[i][k] - cnt[i][j] - cnt[j][k] - (pnt[j].x < pnt[k].x);
	else
		return cnt[i][j] + cnt[j][k] - cnt[i][k];
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	FOR(i, 0, n-1) {
		cin >> pnt[i].x >> pnt[i].y;
	}
	sort(pnt, pnt + n);

	FOR(i, 0, n-1) FOR(j, i+1, n-1) {
		FOR(k, 0, n-1) if (k != i && k != j && pnt[i].x <= pnt[k].x && pnt[k].x < pnt[j].x && ccw(pnt[i], pnt[j], pnt[k]) < 0) ++cnt[i][j];
	}

	ll total = 0;
	FOR(i, 0, n-1) FOR(j, i+1, n-1) FOR(k, j+1, n-1) {
		ll tmp = get(i, j, k);
		// cout << i << ' ' << j << ' ' << k << ": " << tmp << endl;
		// cout << i << ' ' << j << ": " << cnt[i][j] << endl;
		// cout << j << ' ' << k << ": " << cnt[j][k] << endl;
		// cout << i << ' ' << k << ": " << cnt[i][k] << endl;
		// cout << endl;
		total += tmp * (n - 3 - tmp);
		// total -= nCk(tmp, 2) * 2;
	}

	total /= 2;
	total = nCk(n, 5) - total;

	cout << total << endl;

	return 0;
}