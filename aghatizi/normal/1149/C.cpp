#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

struct node
{
	int val[4][4] , Add;
	node()
	{
		memset(val , 0 , sizeof val);
		Add = 0;
	}
};

node seg[maxn * 4];

int n;

const int zarib[] = {1 , -2 , 1};
int Z[4][4];

node merge(node a , node b)
{
	node c = a;
	c.Add = 0;
	for(int l = 0; l < 3; l++)
		for(int r = l + 1; r < 4; r++)
			for(int k = l; k < r; k++)
				c.val[l][r] = max(c.val[l][r] , a.val[l][k] + b.val[k][r]);
	return c;
}

void put(int v , int val)
{
	seg[v].Add += val;
	for(int l = 0; l < 3; l++)
		for(int r = l + 1; r < 4; r++)
			seg[v].val[l][r] += Z[l][r] * val;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && seg[v].Add)
	{
		put(2 * v , seg[v].Add);
		put(2 * v + 1 , seg[v].Add);
	}
	seg[v].Add = 0;
}

void add(int l , int r , int val , int s = 0 , int e = n , int v = 1)
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

	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

string s;
void handle(int i , int val)
{
	if(s[i] == '(')
		add(i + 1 , n , val);
	else
		add(i + 1 , n , -val);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int l = 0; l < 3; l++)
		for(int r = l + 1; r < 4; r++)
			Z[l][r] = Z[l][r - 1] + zarib[r - 1];

	int q;
	cin >> n >> q >> s;
	n = 2 * (n - 1) + 1;

	for(int i = 0; i < n - 1; i++)
		handle(i , 1);
	cout << seg[1].val[0][3] << endl;

	while(q--)
	{
		int x , y;
		cin >> x >> y;
		x-- , y--;

		handle(x , -1) , handle(y , -1);
		swap(s[x] , s[y]);
		handle(x , 1) , handle(y , 1);
		cout << seg[1].val[0][3] << endl;
	}
}