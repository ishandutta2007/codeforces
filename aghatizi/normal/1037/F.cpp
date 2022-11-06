#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int mod = 1e9 + 7;

int a[maxn] , seg[maxn * 4] , tmp[maxn] , shit[maxn];

int mx[maxn * 4] , sum[maxn * 4] , mn[maxn * 4] , lazy[maxn * 4];

vector<int> inds;

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

inline void Build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v] = a[s];
		return;
	}

	int m = (s + e) / 2;

	Build(s , m , 2 * v);
	Build(m , e , 2 * v + 1);

	seg[v] = max(seg[2 * v] , seg[2 * v + 1]);
}

inline int GetK(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return 0;

	int m = (s + e) / 2;

	return max(GetK(l , r , s , m , 2 * v) , GetK(l , r , m , e , 2 * v + 1));
}

inline void puttag(int s , int e , int v , int val)
{
	mkay(sum[v] += 1LL * (val - mn[v]) * (e - s) % mod);

	lazy[v] = val - mn[v];
	mn[v] = mx[v] = val;
}

inline void shift(int s , int e , int v)
{
	if(e - s >= 2 && lazy[v])
	{
		int m = (s + e) / 2;

		puttag(s , m , 2 * v , lazy[v]);
		puttag(m , e , 2 * v + 1 , lazy[v]);
	}

	lazy[v] = 0;
}

inline void update(int l , int r , int val , int s = 0 , int e = inds.size() , int v = 1)
{
	if(mn[v] >= val)
		return;

	if(l <= s && e <= r && mn[v] == mx[v])
	{
		puttag(s , e , v , val);

		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);

	int m = (s + e) / 2;

	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
	mkay(sum[v] = sum[2 * v] + sum[2 * v + 1]);
}

inline int get(int l , int r , int val , int s = 0 , int e = inds.size() , int v = 1)
{
	if(l <= s && e <= r)
	{
		if(mn[v] >= val)
			return sum[v];

		if(mx[v] < val)
			return 1LL * (e - s) * val % mod;
	}
	if(r <= s || e <= l)
		return 0;

	int m = (s + e) / 2;

	int ans = 0;
	mkay(ans = get(l , r , val , s , m , 2 * v) + get(l , r , val , m , e , 2 * v + 1));

	return ans;
}

int main()
{
	int n , k;
	scanf("%d%d", &n, &k);

	int res = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	Build(0 , n , 1);

	for(int i = 0; i + k - 1 <= n; i++)
		shit[i] = GetK(i , i + k - 1 , 0 , n , 1);

	for(int rem = 0; rem < k - 1; rem++)
	{
		inds.clear();

		for(int i = rem; i + k - 1 <= n; i += k - 1)
			inds.pb(i);

		for(int i = 0; i < (int)inds.size() * 4; i++)
			mx[i] = mn[i] = lazy[i] = sum[i] = 0;

		for(int i = (int)inds.size() - 1; i >= 0; i--)
		{
			int ind = inds[i];

			update(i , inds.size() , shit[ind]);

			if(ind > 0)
				mkay(res += get(i , inds.size() , a[ind - 1]));
		}
	}

	cout << res << endl;
}