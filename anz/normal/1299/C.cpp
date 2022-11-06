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

const int N = 1000001;
const ll INF = 987654321987654321;
int n;
ll a[N];
ll psum[N];
set <pair<pii, double> > st;
double res[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		st.insert(make_pair( pii(i,i), a[i] ));
		psum[i] = psum[i - 1] + a[i];
	}

	bool flag = true;
	while (flag)
	{
		flag = false;
		auto it = st.begin();
		while (next(it) != st.end())
		{
			double cur = (*it).second;
			double nxt = (*next(it)).second;

			if (cur > nxt)
			{
				flag = true;
				pii tmp = { it->first.first, next(it)->first.second };
				st.erase(next(it));
				auto jt = next(it);
				st.erase(it);
				st.insert({ tmp, (double)(psum[tmp.second] - psum[tmp.first - 1]) / (tmp.second - tmp.first + 1) });
				it = prev(jt);
			}
			else it = next(it);
		}
	}

	for (auto it : st)
	{
		for (int i = it.first.first; i <= it.first.second; i++)
			res[i] = it.second;
	}

	cout.precision(9);
	for (int i = 1; i <= n; i++)
		cout << fixed << res[i] << '\n';
}