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
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 5e5 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 74e-9;

lli bp(lli a, lli b = -2LL)
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


int t, n;
int l[N], r[N], pr[N];
bool col[N], cl[N];
map <int, int> mp;
map <int, int> mp1;
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		int pat = 0, ans = 0;
		cin >> n;
		vector <int> a;
		a.push_back(INT_MIN);
		//a.push_back(INT_MAX);
		for (int i = 0; i < n; i++)
		{
			cin >> l[i] >> r[i];
			mp[l[i]]++;
			mp[r[i]]--;
			if (mp1[l[i]] == 0) a.push_back(l[i]);
			if (l[i] != r[i] && mp1[r[i]] == 0) a.push_back(r[i]);
			mp1[r[i]]++;
			mp1[l[i]]++;
		}
		sort(all(a));
		//if (t == 0)cout << a.size() << endl;
		int sm = 0;
		for (int i = 0; i < a.size(); i++)
		{
			sm += mp[a[i]];
			if (sm == 0) col[i] = true, pat++;
			if (sm == 1) cl[i] = true, pr[i]++;
			if (i > 0) pr[i] += pr[i - 1];
		}
		//if (t == 0) cout << pr[4] << endl;
		for (int i = 0; i < n; i++)
		{
			int i1 = upper_bound(all(a), l[i]) - a.begin() - 1;
			int i2 = upper_bound(all(a), r[i]) - a.begin() - 1;
			if (l[i] == r[i])
			{
				if (col[i1 - 1] && col[i1] && mp1[l[i]] == 2) ans = max(ans, pat - 2);
				else ans = max(ans, pat - 1);
				//if (t == 0) cout << ans << endl;
				continue;
			}
			//if (t == 0)cout << i1 << " " << i2 << endl;
			int ss = pr[i2 - 1] - pr[i1 - 1];
			//cout << ss << endl;
			//cout << mp1[l[i]] << " " << mp1[r[i]] << endl;
			if (col[i1 - 1] && mp1[l[i]] == 1)ss--;
			if (mp1[r[i]] == 1 && col[i2])ss--;
			ans = max(ans, ss + pat - 1);
			//if (t == 0)cout << ss + pat - 1 << endl;
		}
		cout << ans << endl;
		for (int i = 0; i <= 2 * n; i++)
		{
			mp[l[i]] = mp[r[i]] = mp1[l[i]] = mp1[r[i]] = 0;
			col[i] = cl[i] = false;
			pr[i] = 0;
		}
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