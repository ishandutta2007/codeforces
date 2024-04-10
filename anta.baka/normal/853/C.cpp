#include <bits/stdc++.h>

using namespace std;

int n, q, a[200000], bit[200000];
int L[200000], D[200000], R[200000], U[200000];

inline int upd(int pos)
{
	for(int i = pos; i < n; i |= i + 1)
	{
		bit[i]++;
	}
}

inline int get(int pos)
{
	int ans = 0;
	for(int i = pos; i >= 0; i &= i + 1, i--)
	{
		ans += bit[i];
	}
	return ans;
}

unordered_map<long long, int> cnt;
vector<pair<pair<int, int>, pair<int, int>>> ask[200000];

inline long long key(pair<pair<int, int>, pair<int, int>> a)
{
	return 1LL * a.first.first * n * n * n + 1LL * a.first.second * n * n + 1LL * a.second.first * n + a.second.second;
}

inline long long add(int l, int r, int d, int u)
{
	if(l > r || d > u)
	{
		return 0;
	}
	long long ret = cnt[key({{l, d}, {r, u}})];
	if(l != 0)
	{
		ret -= cnt[key({{0, d}, {l - 1, u}})];
	}
	return ret * (ret - 1) / 2;
}

inline void make_query(int l, int r, int d, int u)
{
	if(l > r || d > u)
	{
		return;
	}
	ask[r].push_back({{l, d}, {r, u}});
	if(l != 0)
	{
		ask[l - 1].push_back({{0, d}, {l - 1, u}});
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cnt.rehash(2000000);
	cin >> n >> q;
	#pragma loop count(200000)
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	#pragma loop count(200000)
	for(int i = 0; i < q; i++)
	{
		cin >> L[i] >> D[i] >> R[i] >> U[i];
		--L[i]; --D[i]; --R[i]; --U[i];
		int l, d, r, u;
		l = L[i];
		d = D[i];
		r = R[i];
		u = U[i];
		make_query(0, n - 1, 0, d - 1);
		make_query(0, n - 1, u + 1, n - 1);
		make_query(0, l - 1, 0, d - 1);
		make_query(0, l - 1, u + 1, n - 1);
		make_query(r + 1, n - 1, 0, d - 1);
		make_query(r + 1, n - 1, u + 1, n - 1);
	}
	#pragma loop count(200000)
	for(int i = 0; i < n; i++)
	{
		upd(a[i]);
		for(pair<pair<int, int>, pair<int, int>> z : ask[i])
		{
			cnt[key(z)] = get(z.second.second) - get(z.first.second - 1);
		}
	}
	#pragma loop count(200000)
	for(int i = 0; i < q; i++)
	{
		int l, d, r, u;
		l = L[i];
		d = D[i];
		r = R[i];
		u = U[i];
		long long ans = 1LL * n * (n - 1) / 2;
		ans -= 1LL * l * (l - 1) / 2;
		ans -= 1LL * (n - r - 1) * (n - r - 2) / 2;
		ans -= add(0, n - 1, 0, d - 1);
		ans -= add(0, n - 1, u + 1, n - 1);
		ans += add(0, l - 1, 0, d - 1);
		ans += add(0, l - 1, u + 1, n - 1);
		ans += add(r + 1, n - 1, 0, d - 1);
		ans += add(r + 1, n - 1, u + 1, n - 1);
		cout << ans << '\n';
	}
}