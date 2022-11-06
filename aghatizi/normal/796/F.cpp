#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 3e5 + 20;
const int MX = 1000 * 1000 * 1000;

struct node
{
	int mx , t , pos;

	node()
	{
		mx = pos = -1;
		t = 0;
	}
};

node seg[maxn * 4] , void_node;

int type[maxn] , l[maxn] , r[maxn] , p[maxn] , x[maxn] , mn[maxn * 4] , val[maxn];

bool is[maxn] , wt[maxn];

vector<int> shits[maxn];

node merge(node a , node b)
{
	node c;

	c.mx = max(a.mx , b.mx);
	if(c.mx == a.mx)
		c.t += a.t , c.pos = a.pos;
	if(c.mx == b.mx)
		c.t += b.t , c.pos = b.pos;

	return c;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].mx = val[s];
		seg[v].pos = s;
		seg[v].t = 1;

		return;
	}

	int m = (s + e) / 2;

	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

node Get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return void_node;

	int m = (s + e) / 2;

	return merge(Get(l , r , s , m , 2 * v) , Get(l , r , m , e , 2 * v + 1));
}

void change(int p , int val , int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].mx = val;
		seg[v].t = 1;

		return;
	}

	int m = (s + e) / 2;

	if(p < m)
		change(p , val , s , m , 2 * v);
	else
		change(p , val , m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

void update(int l , int r , int val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		mn[v] = min(mn[v] , val);

		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;

	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);
}

int get(int p , int s , int e , int v)
{
	int ans = mn[v];
	if(e - s < 2)
		return ans;

	int m = (s + e) / 2;

	if(p < m)
		return min(ans , get(p , s , m , 2 * v));
	else
		return min(ans , get(p , m , e , 2 * v + 1));
}

int main()
{
	int n , q;
	scanf("%d%d", &n, &q);

	memset(mn , 63 , sizeof mn);

	for(int i = 0; i < q; i++)
	{
		scanf("%d", &type[i]);

		if(type[i] == 1)
		{
			scanf("%d%d%d", &l[i], &r[i], &x[i]);
			l[i]--;

			update(l[i] , r[i] , x[i] , 0 , n , 1);
		}
		else
		{
			scanf("%d%d", &p[i], &x[i]);
			p[i]--;

			if(!is[p[i]])
				val[p[i]] = get(p[i] , 0 , n , 1) , is[p[i]] = 1;
		}
	}

	for(int i = 0; i < n; i++)
		if(!is[i])
			val[i] = get(i , 0 , n , 1);

	memset(is , 0 , sizeof is);
	build(0 , n , 1);

	for(int i = 0; i < q; i++)
	{
		if(type[i] == 1)
		{
			node res = Get(l[i] , r[i] , 0 , n , 1);

			if(res.mx != x[i])
				return printf("NO\n") , 0;

			if(res.t == 1 && !wt[res.pos])
				is[res.pos] = 1;
		}
		else
			change(p[i] , x[i] , 0 , n , 1) , wt[p[i]] = 1;
	}

	int T = 0;
	for(int i = 0; i < n; i++)
		if(val[i] > MX)
			T++;

	printf("YES\n");

	if(T > 1)
	{
		for(int i = 0; i < n; i++)
			if(val[i] > MX)
			{
				if(T > 1)
					val[i] = MX , T--;
				else
					val[i] = ((1 << 30) - 1) ^ (MX);
			}
	}
	else
	{
		set<int> st;

		for(int i = 0; i < n; i++)
			if(!is[i] && val[i] <= MX && val[i] > 0)
				shits[31 - __builtin_clz(val[i])].pb(i);

		for(int i = 30; i >= 0; i--)
			if((int)shits[i].size() > 1)
			{
				int k = shits[i].back();

				val[k] = (1 << i) - 1;
				break;
			}

		int Or = 0;
		for(int i = 0; i < n; i++)
			if(val[i] <= MX)
				Or |= val[i];

		for(int i = 0; i < n; i++)
			if(val[i] > MX)
			{
				val[i] = 0;
				for(int j = 30; j >= 0; j--)
					if(!bit(Or , j) && (val[i] ^ (1 << j)) <= MX)
						val[i] ^= (1 << j);
			}

	}

	for(int i = 0; i < n; i++)
		printf("%d ", val[i]);
	printf("\n");
}