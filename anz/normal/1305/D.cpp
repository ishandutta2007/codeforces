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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[1001];

bool isExist[1001];
set <int> st;

int cache[1001];

void DFS(int s, int len, int &mlen, int& ans)
{
	cache[s] = 1;
	if (len > mlen)
	{
		mlen = len;
		ans = s;
	}

	for (auto it : graph[s])
	{
		if (!isExist[it]) continue;
		if (cache[it]) continue;

		DFS(it, len + 1, mlen, ans);
	}
}

pii getR()
{
	int v = *st.begin();
	int ans = v;
	int len = 0;

	memset(cache, 0, sizeof cache);
	DFS(v, 0, len, ans);

	v = ans;
	len = 0;

	memset(cache, 0, sizeof cache);
	DFS(v, 0, len, ans);

	return { v, ans };
}

bool DFS2(int s, pii r)
{
	cache[s] = 1;
	if (s == r.first || s == r.second) return true;

	bool flag = false;
	for (auto it : graph[s])
	{
		if (!isExist[it]) continue;
		if (cache[it]) continue;

		if (DFS2(it, r)) return true;
	}
	return false;
}

bool DFS3(int s, int p)
{
	isExist[s] = 0;
	st.erase(s);
	for (auto it : graph[s])
	{
		if (!isExist[it]) continue;
		if (it == p) continue;

		DFS3(it, s);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) st.insert(i), isExist[i] = 1;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	while (st.size() > 1)
	{
		pii r = getR();
		cout << "? " << r.first << ' ' << r.second << endl;

		int ans; cin >> ans;

		memset(cache, 0, sizeof cache);
		cache[ans] = 1;
		for (auto it : graph[ans])
		{
			if (!isExist[it]) continue;
			if (DFS2(it, r)) DFS3(it, ans);
		}
	}

	cout << "! " << *st.begin() << endl;
}