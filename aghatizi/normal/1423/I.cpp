#include<bits/stdc++.h>
using namespace::std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxq = 2e5 + 20;
const int N = (1 << 16) + 5;

ll l[maxq] , r[maxq] , v[maxq];

int or_all[N * 4] , and_all[N * 4] , lazy[N * 4];

int val[N + 20] , ans[N + 20];;

void put(int v , int val)
{
	or_all[v] |= val;
	and_all[v] |= val;
	lazy[v] |= val;

	return;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && lazy[v])
	{
		put(2 * v , lazy[v]);
		put(2 * v + 1 , lazy[v]);
	}

	lazy[v] = 0;
}

void set_or(int l , int r , int val , int s = 0 , int e = N , int v = 1)
{
	if(l <= s && e <= r)
	{
		or_all[v] |= val;
		and_all[v] |= val;
		lazy[v] |= val;
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);
	int m = (s + e) / 2;

	set_or(l , r , val , s , m , 2 * v);
	set_or(l , r , val , m , e , 2 * v + 1);

	or_all[v] = or_all[2 * v] | or_all[2 * v + 1];
	and_all[v] = and_all[2 * v] & and_all[2 * v + 1];
}

int get_or(int l , int r , int s = 0 , int e = N , int v = 1)
{
	if(l <= s && e <= r)
		return or_all[v];
	if(r <= s || e <= l)
		return 0;

	shift(s , e , v);
	int m = (s + e) / 2;

	return get_or(l , r , s , m , 2 * v) | get_or(l , r , m , e , 2 * v + 1);
}

int get_and(int l , int r , int s = 0 , int e = N , int v = 1)
{
	if(l <= s && e <= r)
		return and_all[v];
	if(r <= s || e <= l)
		return (1 << 18) - 1;

	shift(s , e , v);
	int m = (s + e) / 2;

	return get_and(l , r , s , m , 2 * v) & get_and(l , r , m , e , 2 * v + 1);
}

void handle(int ind , int a , int b , int v)
{
	int AND = get_and(a , b);
	int OR = get_or(a , b);

	for(int j = 0; j < 16; j++)
	{
		if(bit(v , j))
		{
			if(!bit(AND , j))
			{
				cout << "impossible" << endl;
				exit(0);
			}
		}
		else
		{
			if(bit(val[ind] , j) && bit(OR , j))
			{
				cout << "impossible" << endl;
				exit(0);
			}
		}
	}
}

int main()
{
	int k , q;
	scanf("%d%d", &k, &q);

	for(int i = 0; i < q; i++)
		scanf("%I64d%I64d%I64d", &l[i], &r[i], &v[i]);

	set<int> st;
	for(int i = 0; i < N; i++)
		st.insert(i);

	for(int i = 0; i < q; i++)
	{
		int x = l[i] >> k;
		int y = r[i] >> k;

		if(x == y)
		{
			int a = l[i] ^ (x << k);
			int b = r[i] ^ (x << k);

			val[x] |= v[i];

			set_or(a , b + 1 , v[i]);
		}
		else
		{
			if(x + 1 < y)
			{
				auto it = st.lower_bound(x + 1);
				while(it != st.end() && *it < y)
				{
					int vx = *it;
					st.erase(vx);
					val[vx] |= v[i];
					it = st.lower_bound(x + 1);
				}
			}

			int a = l[i] ^ (x << k);
			int b = r[i] ^ (y << k);

			set_or(a , (1 << k) , v[i]);
			set_or(0 , b + 1 , v[i]);

			val[x] |= v[i];
			val[y] |= v[i];
		}
	}

	for(int i = 0; i < q; i++)
	{
		int x = l[i] >> k;
		int y = r[i] >> k;

		if(x == y)
		{
			int a = l[i] ^ (x << k);
			int b = r[i] ^ (x << k);

			handle(x , a , b + 1 , v[i]);
		}
		else
		{
			if(x + 1 < y)
				handle(x + 1 , 0 , (1 << k) , v[i]);

			int a = l[i] ^ (x << k);
			int b = r[i] ^ (y << k);

			handle(x , a , (1 << k) , v[i]);
			handle(y , 0 , b + 1 , v[i]);
		}
	}


	for(int i = 0; i < (1 << k); i++)
		ans[i] = get_and(i , i + 1);

	memset(and_all , 0 , sizeof and_all);
	memset(or_all , 0 , sizeof or_all);
	memset(lazy , 0 , sizeof lazy);

	for(int i = 0; i < q; i++)
	{
		int x = l[i] >> k;
		int y = r[i] >> k;
		if(x + 1 < y)
			set_or(x + 1 , y , v[i]);
	}

	for(int i = 0; i < q; i++)
	{
		int x = l[i] >> k;
		int y = r[i] >> k;
		if(x + 1 < y)
		{
			int AND = get_and(x + 1 , y);
			int OR = get_or(x + 1 , y);
			if(AND != v[i] || OR != v[i])
				return cout << "impossible" << endl , 0;
		}
	}

	cout << "possible" << endl;

	for(int i = 0; i < (1 << k); i++)
		printf("%d\n", ans[i]);
	for(int i = 0; i < (1 << k); i++)
		printf("%d\n", val[i]);
}