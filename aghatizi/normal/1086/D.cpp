#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 2e5 + 20;

struct node
{
	int t[3][4][4] , has;

	node()
	{
		memset(t , 0 , sizeof t);
		has = 0;
	}
};

node seg[maxn * 4];

string a;

int n;

int cd(char ch)
{
	if(ch == 'P')
		return 0;
	else if(ch == 'R')
		return 1;
	else
		return 2;
}

void merge(const node &a , const node &b , node &c)
{
	c = node();
	c.has = a.has | b.has;

	for(int i = 0; i < 3; i++)
	{
		int w = (i + 1) % 3 , l = (i + 2) % 3;

		int tmpl = (bit(a.has , w) << 1) | bit(a.has , l);
		int tmpr = (bit(b.has , w) << 1) | bit(b.has , l);

		for(int maskl = 0; maskl < 4; maskl++)
			for(int maskr = 0; maskr < 4; maskr++)
			{
				c.t[i][maskl][maskr | tmpr] += a.t[i][maskl][maskr];
				c.t[i][maskl | tmpl][maskr] += b.t[i][maskl][maskr];
			}
	}
}

void update(int p , int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
	{
		seg[v] = node();
		seg[v].has = (1 << cd(a[s]));
		seg[v].t[cd(a[s])][0][0] = 1;

		return;
	}

	int m = (s + e) / 2;
	if(p < m)
		update(p , s , m , 2 * v);
	else
		update(p , m , e , 2 * v + 1);

	merge(seg[2 * v] , seg[2 * v + 1] , seg[v]);
}

int get(node a)
{
	int res = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				if(j != 1 && k != 1)
					res += a.t[i][j][k];

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q >> a;

	for(int i = 0; i < n; i++)
		update(i);

	cout << get(seg[1]) << endl;
	while(q--)
	{
		int p;
		cin >> p;
		p--;
		cin >> a[p];

		update(p);
		cout << get(seg[1]) << endl;
	}
}