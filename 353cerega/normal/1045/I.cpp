#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
#include <cmath>
#include <ctime>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

const int size1 = 1e3;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const double eps = 1e-5;
typedef long long ll;
typedef double ld;

template <typename T1, typename T2>
inline ostream& operator<<(ostream& out, const pair<T1, T2>& v) { return out << v.first << ' ' << v.second; }
template <typename T>
inline ostream& operator<<(ostream& out, const vector<T>& v) { for (const T& x : v) out << x << ' '; return out; }
template <typename T1, typename T2>
inline istream& operator>>(istream& in, pair<T1, T2>& v) { return in >> v.first >> v.second; }
template <typename T>
inline istream& operator>>(istream& in, vector<T>& v) { for (T& x : v) in >> x; return in; };

/*int n, m;

int get(int x, int y)
{
	return (x - 1) * n + y;
}

bool correct(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

vector < vector < int > > graph(size1);

static bool used[size1], mark[size1];
static int par[size1];

bool dfs(int v)
{
	if (used[v])
	{
		return false;
	}
	used[v] = true;
	for (int u : graph[v])
	{
		if (par[u] == -1 || dfs(par[u]))
		{
			mark[v] = true;
			par[u] = v;
			return true;
		}
	}
	return false;
}
*/

void solve()
{
	int n;
	cin >> n;
	map < ll, ll > map1;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		ll cnt = 0;
		for (int j = 0; j < s.size(); j++)
		{
			cnt ^= (1LL << (s[j] - 'a'));
		}
		map1[cnt]++;
	}
	ll ans = 0;
	ll ans1 = 0;
	for (auto p: map1)
	{
		ans += p.second * (p.second - 1) / 2;
		for (int j = 0; j < 26; j++)
		{
			if (map1.count(p.first ^ (1LL << j)))
			{
				ans1 += p.second * map1[p.first ^ (1LL << j)];
			}
		}
	}
	cout << ans + ans1 / 2;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}