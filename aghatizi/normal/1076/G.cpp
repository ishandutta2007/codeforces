#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define int ll

const int maxn = 2e5 + 20;
const int maxm = 5;

struct node
{
	int sz , dp[1 << maxm][2] , lazy;

	node()
	{
		memset(dp , 0 , sizeof dp);
		sz = 0;
		lazy = 0;
	}
};

node seg[maxn * 4] , void_node;

int n , m , shit;

ll a[maxn];

node merge(node a , node b)
{
	node c;
	c.sz = a.sz + b.sz;

	for(int mask = 0; mask < (1 << m); mask++)
		for(int i = 0; i < 2; i++)
		{
			int code = b.dp[mask][i];
			c.dp[mask][i] = a.dp[code][i];
		}

	return c;
}

void build(int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
	{
		for(int mask = 0; mask < (1 << m); mask++)
			for(int i = 0; i < 2; i++)
			{
				seg[v].dp[mask][i] = (mask << 1);
				seg[v].dp[mask][i] &= shit;

				if(mask == shit)
					seg[v].dp[mask][i] |= ((a[s] + i + 1) % 2);
				else
					seg[v].dp[mask][i] |= 1;
			}
		seg[v].sz = 1;

		return;
	}
	int m = (s + e) / 2;

	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

void handle(int v)
{
	for(int mask = 0; mask < (1 << m); mask++)
		swap(seg[v].dp[mask][0] , seg[v].dp[mask][1]);
	seg[v].lazy ^= 1;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && seg[v].lazy)
	{
		handle(2 * v);
		handle(2 * v + 1);
	}

	seg[v].lazy = 0;
}

void add(int l , int r , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
	{
		handle(v);
		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;
	shift(s , e , v);

	add(l , r , s , m , 2 * v);
	add(l , r , m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

node get(int l , int r , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return void_node;

	int m = (s + e) / 2;
	shift(s , e , v);

	return merge(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> m >> q;

//	scanf("%d%d%d", &n, &m, &q);

	shit = (1 << m) - 1;

	for(int mask = 0; mask < (1 << m); mask++)
		for(int i = 0; i < 2; i++)
			void_node.dp[mask][i] = mask;

	for(int i = 0; i < n; i++)
		cin >> a[i];
//		scanf("%I64d", &a[i]);

	build(0 , n , 1);

	while(q--)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int l , r;
			ll d;
			cin >> l >> r >> d;

//			scanf("%d%d%I64d", &l, &r, &d);
			l--;

			if(d&1)
				add(l , r);
		}
		else
		{
			int l , r;
			cin >> l >> r;
			//scanf("%d%d", &l, &r);
			l--;

			int code = get(l , r).dp[shit][0];
			code &= 1;

			cout << 2 - code << endl;
//			printf("%d\n", 2 - code);
		}
	}
}