#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[300 * 1000], d[300 * 1000];

const int maxN = 400;
ll tree[maxN * 4];

void change(int t, int l, int r, int i, ll v)
{
	if (l == r)
		return void(tree[t] = max(tree[t], v));
	
	int m = (l + r) / 2;
	if (i <= m)
		change(t * 2 + 1, l, m, i, v);
	else
		change(t * 2 + 2, m + 1, r, i, v);
	
	tree[t] = max(tree[t * 2 + 1], tree[t * 2 + 2]);
}

ll query(int t, int l, int r, int x, int y)
{
	if (x > r || y < l) return 0;
	
	if (l >= x && r <= y)
		return tree[t];
	
	int m = (l + r) / 2;
	return max(query(t * 2 + 1, l, m, x, y), query(t * 2 + 2, m + 1, r, x, y));
}

int cnt[400];

int main()
{
#ifdef LOCAL
	freopen("b.in", "r", stdin);
#endif
	
	ll n, t;
	scanf("%lld %lld", &n, &t);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	
	ll answer = 0;
	
	ll l = min(t, (ll)400);
	
	for (ll i = 0; i < n * l; i++)
	{
		ll d = query(0, 0, 300, 0, a[i % n]) + 1;
		change(0, 0, 300, a[i % n], d);
		
		//ll nMore = cnt[a[i]] * (ll)(t - i / n - 1);
		answer = max(answer, d);
	}
	
	ll r = max(l, t - 400);
	ll blocks = r - l;
	
	for (int i = 0; i <= 300; i++)
	{
		ll d = query(0, 0, 300, i, i);
		d += cnt[i] * blocks;
		change(0, 0, 300, i, d);
	}
	
	for (ll i = n * r; i < n * t; i++)
	{
		ll d = query(0, 0, 300, 0, a[i % n]) + 1;
		change(0, 0, 300, a[i % n], d);
		
		//ll nMore = cnt[a[i]] * (ll)(t - i / n - 1);
		answer = max(answer, d);
	}
	
	printf("%lld\n", answer);

	return 0;
}