#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, m, a[100010], ans;
map<ll, ll> ma;
int main()
{
	scanf("%I64d%I64d%I64d", &n, &k, &m);
	for (ll i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		ma[a[i]]++;
	}
	stack<pair<ll, ll> > s;
	for (ll i = 0; i < n; i++)
	{
		if (!s.empty() && s.top().first == a[i] && s.top().second == k-1)
		{
			for (ll i = 1; i < k; i++) s.pop();
			ma[a[i]]-=k;
			if (ma[a[i]] == 0) ma.erase(a[i]);
			ans+=k*m;
		}
		else if (!s.empty() && s.top().first == a[i])
		{
			s.push(make_pair(a[i], s.top().second+1));
		}
		else s.push(make_pair(a[i], 1));
	}
	stack<pair<ll, ll> > f = s;
	stack<pair<ll, ll> > b;
	while (!s.empty())
	{
		ll ai = s.top().first;
		s.pop();
		if (!b.empty() && b.top().first == ai && b.top().second == k-1)
		{
			for (ll i = 1; i < k; i++) b.pop();

			ans+=k*m;
			ma[ai]-=k;
			if (ma[ai] == 0) ma.erase(ai);
		}
		else if (!b.empty() && b.top().first == ai)
		{
			b.push(make_pair(ai, b.top().second+1));
		}
		else b.push(make_pair(ai, 1));
	}

	while (f.size() && b.size() && f.top().first == b.top().first && f.top().second+b.top().second >= k && ma.size() > 1 && ma[f.top().first] >= k)
	{
		ll doing = f.top().first;
		ll fnum = f.top().second;
		ll bnum = k-fnum;
		for (ll i = 0; i < fnum; i++) f.pop();
		for (ll i = 0; i < bnum; i++) b.pop();
		ma[doing]-=k;
		ans+=k*(m-1);
		if (ma[doing] == 0) ma.erase(doing);

	}
	if (ma.size() == 1)
	{
		ll doing = (ma.begin())->first;
		ll am = ma[doing]*(m-2);
		while (f.size() && f.top().first == doing) { f.pop(); am++; }
		while (b.size() && b.top().first == doing) { b.pop(); am++; }
		ans+=(am/k)*k;
		if (am % k)
		{
			printf("%I64d\n", n*m - ans);
			return 0;
		}
	}
	while (f.size() && b.size() && f.top().first == b.top().first && f.top().second+b.top().second >= k)
	{
		ll doing = f.top().first;
		ll fnum = f.top().second;
		ll bnum = k-fnum;
		for (ll i = 0; i < fnum; i++) f.pop();
		for (ll i = 0; i < bnum; i++) b.pop();
		ans+=k;
	}
	printf("%I64d\n", n*m - ans);
	return 0;









}