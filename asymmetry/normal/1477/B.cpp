//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 201 * 1000

struct node
{
	int w[2], p;
};

int n, q, com;
int zp[N][2];
char wej[N];
char wyj[N];
vector <node> st;
vector <int> siz;

void update(int x)
{
	st[x]={st[x*2].w[0]+st[x*2+1].w[0], st[x*2].w[1]+st[x*2+1].w[1], -1};
}

void push(int x)
{
	if(st[x].p!=-1)
	{
		int l=x<<1;
		int r=l+1;
		int g=st[x].p;
		st[l].w[g]=siz[l];
		st[l].w[g^1]=0;
		st[l].p=g;
		st[r].w[g]=siz[r];
		st[r].w[g^1]=0;
		st[r].p=g;
		st[x].p=-1;
	}
}

void ins(int x, int l, int r, int ll, int rr, int w)
{
	if(l>rr || r<ll) return;
	if(ll<=l && r<=rr)
	{
		st[x].w[w]=siz[x];
		st[x].w[w^1]=0;
		st[x].p=w;
		return;
	}
	push(x);
	ins(x*2, l, (l+r)/2, ll, rr, w);
	ins(x*2+1, (l+r)/2+1, r, ll, rr, w);
	update(x);
}

int zap(int x, int l, int r, int ll, int rr, int w)
{
	if(l>rr || r<ll) return 0;
	if(ll<=l && r<=rr)
	{
		return st[x].w[w];
	}
	push(x);
	return zap(x*2, l, (l+r)/2, ll, rr, w)+zap(x*2+1, (l+r)/2+1, r, ll, rr, w);
}

bool chck(int x, int l, int r)
{
	if(l>n) return false;
	if(l==r)
	{
		//~ printf("(%d %d) ", st[x].w[0], st[x].w[1]);
		return st[x].w[wej[l]-'0']==0;
	}
	push(x);
	return chck(x*2, l, (l+r)/2) || chck(x*2+1, (l+r)/2+1, r);
}

void solve()
{
	scanf("%d%d", &n, &q);
	scanf("%s", wej+1);
	scanf("%s", wyj+1);
	for(int i=1; i<=q; ++i)
	{
		scanf("%d%d", &zp[i][0], &zp[i][1]);
	}
	com=1;
	while(com<n) com<<=1;
	st.resize(com<<1);
	siz.resize(com<<1);
	for(int i=com+com-1; i; --i) st[i]={0, 0, -1};
	for(int i=1; i<=n; ++i)
	{
		st[i+com-1].w[wyj[i]-'0']++;
		siz[i+com-1]=1;
	}
	for(int i=com-1; i; --i)
	{
		update(i);
		siz[i]=siz[i*2]+siz[i*2+1];
	}
	for(int i=q; i; --i)
	{
		int g=zap(1, 1, com, zp[i][0], zp[i][1], 0);
		int h=zap(1, 1, com, zp[i][0], zp[i][1], 1);
		if(g<h)
		{
			//~ printf("INS: (%d %d) %d\n", zp[i][0], zp[i][1], 1);
			ins(1, 1, com, zp[i][0], zp[i][1], 1);
		}
		else if(h<g)
		{
			//~ printf("INS: (%d %d) %d\n", zp[i][0], zp[i][1], 0);
			ins(1, 1, com, zp[i][0], zp[i][1], 0);
		}
		else
		{
			printf("NO\n");
			return;
		}
	}
	if(chck(1, 1, com)) printf("NO\n");
	else printf("YES\n");
}

int main()
{
	//~ ios_base::sync_with_stdio(false);
	//~ cin.tie(NULL);
	int qq=1;
	scanf("%d", &qq);
	while(qq--)
	{
		solve();
	}
	return 0;
}