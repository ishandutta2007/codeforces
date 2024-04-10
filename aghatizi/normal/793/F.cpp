#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> ls[maxn] , query[maxn];

int n , l[maxn] , r[maxn] , res[maxn];

int mx[maxn * 4] , lazy[maxn * 4];

void put(int v , int val)
{
	mx[v] = min(mx[v] , val);
	lazy[v] = min(lazy[v] , val);
}

void shift(int s , int e , int v)
{
	if(e - s >= 2)
	{
		put(2 * v , lazy[v]);
		put(2 * v + 1 , lazy[v]);
	}

	lazy[v] = n;
}

void handle(int l , int r , int val , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
	{
		put(v , val);
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);

	int m = (s + e) / 2;
	handle(l , r , val , s , m , 2 * v);
	handle(l , r , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

int get(int l , int r , int val , int s = 0 , int e = n , int v = 1)
{
	if(r <= s || e <= l || mx[v] <= val)
		return -1;
	if(e - s < 2)
		return s;
	shift(s , e , v);

	int m = (s + e) / 2;
	int ans = get(l , r , val , s , m , 2 * v);
	if(ans == -1)
		ans = get(l , r , val , m , e , 2 * v + 1);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int l , r;
		cin >> l >> r;
		l-- , r--;

		ls[l].pb(r);
	}

	fill(mx , mx + maxn * 4 , n);
	fill(lazy , lazy + maxn * 4 , n);

	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i];
		l[i]--;

		query[l[i]].pb(i);
	}

	for(int i = n - 1; i >= 0; i--)
	{
		for(auto r : ls[i])
			handle(i , r , r);

		for(auto ind : query[i])
			res[ind] = get(i , r[ind] , r[ind] - 1);
	}

	for(int i = 0; i < q; i++)
		cout << res[i] + 1 << endl;
}