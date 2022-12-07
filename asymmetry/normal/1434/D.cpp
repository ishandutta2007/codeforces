#include <bits/stdc++.h>

using namespace std;

int n, a, b, d[2], l, comp;
int kr[1000010];
int wg[1000010];
int nr[2][500001];
int mx[2][500001];
int gle[2][500001];
int st[2][1048576][3];
vector <int> v[500001];

#define D if(1)

void push(int x, int y)
{
	if(st[y][x][2])
	{
		int l=x<<1;
		int r=l+1;
		swap(st[y][l][0], st[y][l][1]);
		swap(st[y][r][0], st[y][r][1]);
		st[y][l][2]^=1;
		st[y][r][2]^=1;
		st[y][x][2]=0;
	}
}

void update(int x, int y)
{
	st[y][x][0]=max(st[y][x*2][0], st[y][x*2+1][0]);
	st[y][x][1]=max(st[y][x*2][1], st[y][x*2+1][1]);
}

void ins(int y, int x, int l, int r, int ll, int rr)
{
	if(l>rr || r<ll)
	{
		return;
	}
	if(ll<=l && r<=rr)
	{
		swap(st[y][x][0], st[y][x][1]);
		st[y][x][2]^=1;
		return;
	}
	push(x, y);
	ins(y, x*2, l, (l+r)/2, ll, rr);
	ins(y, x*2+1, (l+r)/2+1, r, ll, rr);
	update(x, y);
}

void dia(int x, int dl, int pop)
{
	if(b<dl)
	{
		a=x;
		b=dl;
	}
	for(int i:v[x])
	{
		if(kr[i]!=pop)
		{
			dia(kr[i], dl+1, x);
		}
	}
}

void dfs_gle(int x, int y, int par, int pop)
{
	++l;
	nr[y][x]=l;
	st[y][l+comp-1][par]=gle[y][x];
	st[y][l+comp-1][par^1]=-1e9;
	for(int i:v[x])
	{
		if(kr[i]!=pop)
		{
			gle[y][kr[i]]=gle[y][x]+1;
			dfs_gle(kr[i], y, par^wg[i], x);
		}
	}
	mx[y][x]=l;
}

int main()
{
	scanf("%d", &n);
	comp=1;
	while(comp<n)
	{
		comp<<=1;
	}
	for(int i=1; i<n; ++i)
	{
		scanf("%d%d%d", &a, &b, &wg[i*2]);
		kr[i*2]=a;
		kr[i*2+1]=b;
		wg[i*2+1]=wg[i*2];
		v[a].push_back(i*2+1);
		v[b].push_back(i*2);
	}
	b=-1;
	dia(1, 0, 0);
	d[0]=a;
	b=-1;
	dia(a, 0, 0);
	d[1]=a;
	l=0;
	dfs_gle(d[0], 0, 0, 0);
	l=0;
	dfs_gle(d[1], 1, 0, 0);
	for(int i=comp-1; i; --i)
	{
		update(i, 0);
		update(i, 1);
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int x;
		scanf("%d", &x);
		int ret=0;
		a=kr[x*2];
		b=kr[x*2+1];
		if(gle[0][a]>gle[0][b])
		{
			swap(a, b);
		}
		ins(0, 1, 1, comp, nr[0][b], mx[0][b]);
		ret=max(ret, st[0][1][0]);
		if(gle[1][a]>gle[1][b])
		{
			swap(a, b);
		}
		ins(1, 1, 1, comp, nr[1][b], mx[1][b]);
		ret=max(ret, st[1][1][0]);
		printf("%d\n", ret);
	}
	return 0;
}