#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 5e5 + 20;
const int maxb = 21;

int a[maxn] , ans[maxn] , l[maxn] , r[maxn];

vector<int> obj[maxn * 4];

void add(int ind , int s , int e , int v)
{
	if(e - s < 2)
	{
		ans[ind] = a[s];
		return;
	}
	int m = (s + e) / 2;
	if(r[ind] <= m)
		add(ind , s , m , 2 * v);
	else if(m <= l[ind])
		add(ind , m , e , 2 * v + 1);
	else
		obj[v].pb(ind);
}

array<int , maxb> val[maxn];

void Add(int k , array<int , maxb> &val)
{
	int fn = -1;
	for(int i = maxb - 1; i >= 0; i--)
		if(bit(k , i))
		{
			if(fn == -1 && val[i] == -1)
				val[i] = k , fn = i;
			else
				k ^= val[i];
		}
}

void solve(int s , int e , int v)
{
	if(e - s < 2)
		return;

	int m = (s + e) / 2;
	solve(s , m , 2 * v);
	solve(m , e , 2 * v + 1);

	for(int i = m; i < e; i++)
	{
		if(i > m)
			val[i] = val[i - 1];
		else
			val[i].fill(-1);

		Add(a[i] , val[i]);
	}

	for(int i = m - 1; i >= s; i--)
	{
		if(i < m - 1)
			val[i] = val[i + 1];
		else
			val[i].fill(-1);

		Add(a[i] , val[i]);
	}

	for(auto ind : obj[v])
	{
		r[ind]--;
		auto tmp = val[l[ind]];
		for(int i = maxb - 1; i >= 0; i--)
			if(val[r[ind]][i] != -1)
				Add(val[r[ind]][i] , tmp);

		for(int i = maxb - 1; i >= 0; i--)
			if(tmp[i] != -1 && !bit(ans[ind] , i))
				ans[ind] ^= tmp[i];
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int q;
	scanf("%d", &q);

	for(int i = 0; i < q; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		l[i]--;

		add(i , 0 , n , 1);
	}

	solve(0 , n , 1);

	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}