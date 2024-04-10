#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
#define pir pair<int, int> 
#define all(x) (x).begin(), (x).end()
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };


const int N = 1e6 + 30;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-6;

lli bp(lli a, lli b = mod - 2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}
ostream& operator<<(ostream& c, pir a)
{
	c << a.fr << " " << a.sc;
	return c;
}




int n, m;
int a[N], b[N], c[N], col[N];
lli p[N], dp[N], t[4 * N], sm[N], sm1[N], pat;
void upd(int q, lli val, int nl = 1, int nr = n, int nd = 1)
{
	if (q > nr || q < nl) return;
	if (nl == nr)
	{
		t[nd] += val;
		return;
	}
	itn mid = (nl + nr) / 2;
	upd(q, val, nl, mid, nd * 2);
	upd(q, val, mid + 1, nr, nd * 2 + 1);
	t[nd] = t[nd * 2] + t[nd * 2 + 1];
}
lli qry(int l, int r, int nl = 1, int nr = n, int nd = 1)
{
	if (l > nr || r < nl) return 0;
	if (l == nl && r == nr) return t[nd];
	int mid = (nl + nr) / 2;
	return qry(l, min(mid, r), nl, mid, nd * 2) + qry(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1);
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> p[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i];
		col[c[i]] = i;
		dp[i] = LLONG_MAX;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > c[m])
		{
			pat += p[i];
			continue;
		}
		//if(col[a[i]]) cout << c[col[a[i]] - 1] << " ";
		if (col[a[i]]) sm[i] = qry(c[col[a[i]] - 1] + 1, a[i]);
		upd(a[i], p[i]);
		//cout << sm[i] << " ";
	}
	memset(t, 0, sizeof(t));
	for (int i = n; i > 0; i--)
	{
		if (a[i] > c[m]) continue;
		if (col[a[i]]) sm1[i] = qry(c[col[a[i]] - 1] + 1, a[i]);
		if (p[i] < 0) upd(a[i], p[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (col[a[i]] && dp[col[a[i]] - 1] != LLONG_MAX)
		{
			dp[col[a[i]]] = min(dp[col[a[i]]], dp[col[a[i]] - 1] + sm[i] + sm1[i]);
		}
	}
	if (dp[m] == LLONG_MAX) cout << "NO";
	else cout << "YES\n" << dp[m] + pat << endl;
	return 0;
}


/*


  __
*(><)*
  \/ /
  ||/
--||
  ||
  /\
 /  \
/    \
*/