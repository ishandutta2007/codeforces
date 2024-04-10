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


const int N = 3e6 + 20;
lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-6;

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
ostream& operator<<(ostream& c, pir a)
{
	c << a.fr << " " << a.sc;
	return c;
}

int n, k, sum, i1;
string s;
vector <int> pat[N];
bool col[N];
int main()
{
	fastio;
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L') sum += i - i1, i1++;
	}
	if (k > sum) return cout << -1, 0;
	//cout << sum << endl;
	int k1 = k;
	stack <int> pr;
	for (int i = n - 1; i > 0; i--)
	{
		if (s[i] == 'L' && i > 0 && s[i - 1] == 'R')  pr.push(i), col[i] = true;
	}
	for (int x = 0; x < k1; x++)
	{
		k--;
		while (!pr.empty())
		{
			pat[x].ad(pr.top()), sum--;
			col[pr.top()] = false;
			pr.pop();
			if (sum == k) break;
		}
		//cout << pat[x].size() << " ";
		for (auto p : pat[x])
		{
			//cout << p << " ";
			swap(s[p], s[p - 1]);
		}
		for (int i = pat[x].size() - 1; i >= 0; i--)
		{
			auto p = pat[x][i];
			if (p < n - 1 && s[p + 1] == 'L' && !col[p + 1]) pr.push(p + 1), col[p + 1] = true;
			if (p > 1 && s[p - 2] == 'R' && !col[p - 1]) pr.push(p - 1), col[p - 1] = true;
		}

	}
	if (pr.size() > 0) return cout << -1, 0;
	for (int x = 0; x < k1; x++)
	{
		cout << pat[x].size() << " ";
		for (auto p : pat[x])
		{
			cout << p << " ";
			swap(s[p], s[p - 1]);
		}
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