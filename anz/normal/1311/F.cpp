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

const int N = 200001;
int n;
pll point[N];
vector <ll> loc;
vector <ll> spd;

ll cntSeg[N];
ll valSeg[N];

void update(ll* segTree, int x, ll v)
{
	while (x < N)
	{
		segTree[x] += v;
		x += x & -x;
	}
}

ll getVal(ll* segTree, int x)
{
	ll res = 0;
	while (x)
	{
		res += segTree[x];
		x -= x & -x;
	}
	return res;
}

int getIdx(vector <ll>& v, ll x)
{
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		point[i].first = x;
		loc.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		ll v; cin >> v;
		point[i].second = v;
		spd.push_back(v);
	}

	sort(loc.begin(), loc.end());
	loc.erase(unique(loc.begin(), loc.end()), loc.end());

	sort(spd.begin(), spd.end());
	spd.erase(unique(spd.begin(), spd.end()), spd.end());

	sort(point, point + n);

	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		int idx = getIdx(spd, point[i].second);
		ll cnt = getVal(cntSeg, idx + 1);
		ll sum = getVal(valSeg, idx + 1);

		res += point[i].first * cnt - sum;

		update(cntSeg, idx + 1, 1);
		update(valSeg, idx + 1, point[i].first);
	}

	cout << res;
}