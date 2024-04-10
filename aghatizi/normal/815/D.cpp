#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

int mn[maxn * 4] , mx[maxn * 4] , lazy[maxn * 4];

ll sum[maxn * 4];

int a[maxn] , b[maxn] , c[maxn] , p , q , r , P[maxn] , Q[maxn];

vector<int> pos[maxn];

inline void handle(int s , int e , int v , int val)
{
	lazy[v] += val;
	mx[v] += val;
	mn[v] += val;

	sum[v] += 1LL * (e - s) * val;
}

inline void shift(int s , int e , int v)
{
	if(e - s >= 2)
	{
		int m = (s + e) / 2;

		handle(s , m , 2 * v , lazy[v]);
		handle(m , e , 2 * v + 1 , lazy[v]);
	}

	lazy[v] = 0;
}

void update(int l , int r , int val , int s = 0 , int e = p + 1 , int v = 1)
{
	if(mn[v] >= val)
		return;

	if(l <= s && e <= r && mx[v] == mn[v])
	{
		handle(s , e , v , val - mx[v]);
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
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

ll get(int l , int r , int val , int s = 0 , int e = p + 1 , int v = 1)
{
	if(l <= s && e <= r)
	{
		if(mn[v] >= val)
			return sum[v];
		if(mx[v] < val)
			return 1LL * (e - s) * val;
	}

	if(r <= s || e <= l)
		return 0;

	shift(s , e , v);
	int m = (s + e) / 2;

	return get(l , r , val , s , m , 2 * v) + get(l , r , val , m , e , 2 * v + 1);
}

int main()
{
	int n;
	scanf("%d%d%d%d", &n, &p, &q, &r);

	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &c[i]);

		pos[c[i]].pb(i);
		P[c[i]] = max(P[c[i]] , a[i]);
		Q[c[i]] = max(Q[c[i]] , b[i]);
	}

	for(int i = r; i >= 1; i--)
		P[i] = max(P[i] , P[i + 1]) , Q[i] = max(Q[i] , Q[i + 1]);

	ll res = 0;
	for(int i = 1; i <= r; i++)
	{
		int mxP = P[i] , mxQ = Q[i];
		res += 1LL * (p - mxP) * q - get(mxP + 1 , p + 1 , mxQ);

		for(auto ind : pos[i])
			update(0 , a[ind] + 1 , b[ind]);
	}

	cout << res << endl;
}