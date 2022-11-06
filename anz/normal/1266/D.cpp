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

int n, m;
ll curDebt[100001];

vector <pll> dPlus;
vector <pll> dMinus;

vector <pair<pii, ll> > ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	while (m--)
	{
		int a, b; ll d;
		cin >> a >> b >> d;
		curDebt[a] -= d;
		curDebt[b] += d;
	}

	for (int i = 1; i <= n; i++)
	{
		if (curDebt[i] > 0) dPlus.push_back({ i,curDebt[i] });
		if (curDebt[i] < 0) dMinus.push_back({ i,-curDebt[i] });
	}

	int plus_ptr = 0, minus_ptr = 0;

	while (plus_ptr < dPlus.size() && minus_ptr < dMinus.size())
	{
		ll mv = min(dPlus[plus_ptr].second, dMinus[minus_ptr].second);
		ans.push_back({ { dMinus[minus_ptr].first,dPlus[plus_ptr].first} , mv });

		dPlus[plus_ptr].second -= mv;
		if (dPlus[plus_ptr].second == 0) plus_ptr++;
		dMinus[minus_ptr].second -= mv;
		if (dMinus[minus_ptr].second == 0) minus_ptr++;
	}

	cout << ans.size() << '\n';
	for (auto& it : ans)
	{
		cout << it.first.first << ' ' << it.first.second << ' ' << it.second << '\n';
	}
}