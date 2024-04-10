#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;
vector <int> graph[26];
bool con[26][26];
bool cache[26];

vector <int> ans;
int c = 0;
void DFS(int s)
{
	cache[s] = 1;
	c++;
	ans.push_back(s);

	for (auto v : graph[s])
	{
		if (cache[v]) continue;
		DFS(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		c = 0;
		ans.clear();
		memset(con, 0, sizeof con);
		for (int i = 0; i < 26; i++) graph[i].clear();
		cin >> s;
		for (int i = 0; i < s.size() - 1; i++)
		{
			int a = s[i] - 'a';
			int b = s[i + 1] - 'a';
			con[a][b] = con[b][a] = 1;
		}

		int cnt = 0;
		vector <int> ones;
		bool flag = true;
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (con[i][j]) graph[i].push_back(j);
			}
			if (graph[i].size() > 2) flag = false;
			if (graph[i].size() == 1) ones.push_back(i);
			if (graph[i].size() >= 1) cnt++;
		}

		if (!flag)
		{
			cout << "NO\n";
			continue;
		}

		memset(cache, 0, sizeof cache);
		for (auto i : ones)
		{
			if (!cache[i]) DFS(i);
		}

		if (cnt > c)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		for (int i = 0; i < 26; i++)
		{
			if (!cache[i]) DFS(i);
		}

		for (auto it : ans) cout << (char)(it + 'a');
		cout << '\n';
	}
}