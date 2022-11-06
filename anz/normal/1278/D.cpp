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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <pii> seg;

int par[500001];
int sz[500001];

int getPar(int a)
{
	if (par[a] == a) return a;
	return par[a] = getPar(par[a]);
}

bool merge(int a, int b)
{
	int pa = getPar(a), pb = getPar(b);
	if (pa == pb) return false;

	if (sz[pa] > sz[pb])
		par[pb] = pa;
	else
	{
		par[pa] = pb;
		if (sz[pa] == sz[pb])
			sz[pb]++;
	}
	return true;
}

set <pii> pst;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		seg.push_back({ a,b });
	}
	sort(seg.begin(), seg.end());

	pst.insert({seg[0].second, 0 });
	for (int i = 1; i < n; i++)
	{
		int st = seg[i].first, ed = seg[i].second;
		for(auto it=pst.begin();it!=pst.end();)
		{
			int curEnd = it->first;
			if (curEnd < st)
			{
				auto jt = it;
				it++;
				pst.erase(jt);
				continue;
			}

			if (st < curEnd && curEnd < ed)
			{
				int num = it->second;
				if (!merge(num, i))
				{
					cout << "NO";
					return 0;
				}
				it++;
			}
			else break;
		}
		pst.insert({ seg[i].second, i });
	}

	int ans = getPar(0);
	for (int i = 1; i < n; i++)
	{
		if (ans != getPar(i))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}