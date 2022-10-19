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


const int N = 5000 + 30;
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

int n;
int k[N];
bool col[N];
int cl[N];
lli ans;
vector <int> pr, sm[N], fp[N], av;
int main()
{
	fastio;
	for (int i = 2; i < N; i++)
	{
		if (!col[i])
		{
			pr.ad(i);
			for (int j = i * i; j < N; j += i)
			{
				col[j] = true;
			}
		}
	}
	for (int i = 1; i < N; i++)
	{
		int x = 0;
		int ss = i;
		for (auto p : pr)
		{
			x = 0;
			while (ss % p == 0) ss /= p, x++;
			sm[i].ad(x);
		}
		for (int j = 0; j < sm[i].size(); j++)
		{
			if (j >= sm[i - 1].size()) sm[i - 1].ad(0);
			sm[i][j] += sm[i - 1][j];
			for (int x = 0; x < sm[i][j]; x++)
			{
				fp[i].ad(j);
			}
		}
		reverse(all(fp[i]));
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 0) x = 1;
		k[x]++;
		ans += fp[x].size();
	}
	for (int i = 1; i <= 5000; i++)
	{
		if (k[i]) av.ad(i);
	}
	//cout << ans << endl;
	vector <int> tmp;
	for (int i = 0;; i++)
	{
		memset(cl, 0, sizeof(cl));
		for (auto p : av)
		{
			if (i >= fp[p].size()) continue;
			cl[fp[p][i]] += k[p];
		}
		bool bl = true;
		for (int j = 0; j < pr.size(); j++)
		{
			if (cl[j] + cl[j] > n)
			{
				bl = false;
				ans -= cl[j];
				ans += n - cl[j];
				tmp.clear();
				for (auto p : av) if (i < fp[p].size() && fp[p][i] == j) tmp.ad(p);
				swap(tmp, av);
				break;
			}
		}
		if (bl) break;
	}
	cout << ans << endl;
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
//MsNFhBGz