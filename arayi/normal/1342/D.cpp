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


const int N = 4e5 + 30;
const lli mod = 1e9 + 7;
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



int n, k;
int a[N], c[N];
vector <vector<int> > ans;
int t[4 * N];
void upd(int q, int val, int nl = 1, int nr = k, int nd = 1)
{
	if (q > nr || q < nl) return;
	if (nl == nr)
	{
		t[nd] = val;
		return;
	}
	int mid = (nl + nr) / 2;
	upd(q, val, nl, mid, nd * 2);
	upd(q, val, mid + 1, nr, nd * 2 + 1);
	t[nd] = max(t[nd * 2], t[nd * 2 + 1]);
}
int qry(int l, int r, int nl = 1, int nr = k, int nd = 1)
{
	if (l > nr || r < nl) return 0;
	if (nl == l && r == nr) return t[nd];
	int mid = (nl + nr) / 2;
	return max(qry(l, min(mid, r), nl, mid, nd * 2), qry(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1));
}
int qry1(int ql, int qr, int val)
{
	if (qr == 0 || qry(ql, qr) <= val) return -1;
	int l = ql, r = qr, ans = 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (qry(mid, r) > val) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int main()
{
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if (a[i]) upd(i, c[i]);
	}
	int qn = 0;
	while (qn < n)
	{
		//cout << qn << endl;
		vector <int> pat;
		int i1 = qry1(1, k, 0);
		if (i1 == -1) break;	
		while (true)
		{
			//cout << i1 << endl;
			while (a[i1] && c[i1] > (int)pat.size())
			{
				pat.ad(i1);
				a[i1]--;
				qn++;
			}
			if (a[i1] == 0) upd(i1, 0);
			i1 = qry1(1, i1 - 1, (int)pat.size());
			if (i1 == -1) break;
		}
		ans.ad(pat);
	}
	cout << ans.size() << endl;
	for (auto p : ans)
	{
		cout << p.size() << " ";
		for (auto q : p) cout << q << " ";
		cout << "\n";
	}
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