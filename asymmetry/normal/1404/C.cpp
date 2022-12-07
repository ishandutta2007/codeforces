#include <bits/stdc++.h>

using namespace std;

int n, q, a, b, comp;
int t[300001];
int odp[300001];
int st[1048576][2];
int st2[1048576];
vector <pair <int, int> > zp[300001];
bitset <300001> bt;

void update(int x)
{
	st[x][0]=min(st[x*2][0], st[x*2+1][0]);
}

void push(int x)
{
	int l=x*2;
	int r=l+1;
	st[l][0]+=st[x][1];
	st[l][1]+=st[x][1];
	st[r][0]+=st[x][1];
	st[r][1]+=st[x][1];
	st[x][1]=0;
}

void insinf(int x)
{
	x+=comp-1;
	st[x][0]=1e9;
	x>>=1;
	while(x)
	{
		update(x);
		x>>=1;
	}
}

void ins(int x, int l, int r, int ll, int rr, int w)
{
	if(l>rr || r<ll)
	{
		return;
	}
	if(ll<=l && r<=rr)
	{
		st[x][0]+=w;
		st[x][1]+=w;
		return;
	}
	push(x);
	ins(x*2, l, (l+r)/2, ll, rr, w);
	ins(x*2+1, (l+r)/2+1, r, ll, rr, w);
	update(x);
}

int fin(int x, int l, int r)
{
	//printf("%d %d %d %d\n", x, l, r, st[x][0]);
	if(l==r)
	{
		return l;
	}
	push(x);
	if(st[x*2][0]<0)
	{
		return fin(x*2, l, (l+r)/2);
	}
	return fin(x*2+1, (l+r)/2+1, r);
}

void ins2(int x, int w)
{
	x+=comp-1;
	while(x)
	{
		st2[x]+=w;
		x>>=1;
	}
}

int zap2(int a, int b)
{
	//printf("(%d %d) -> ", a, b);
	int k=0;
	a+=comp-1;
	b+=comp-1;
	while(a<b)
	{
		if(a&1)
		{
			k+=st2[a];
			a>>=1;
			++a;
		}
		else
		{
			a>>=1;
		}
		if(b&1)
		{
			b>>=1;
		}
		else
		{
			k+=st2[b];
			b>>=1;
			--b;
		}
	}
	if(a==b)
	{
		k+=st2[b];
	}
	//printf("%d\n", k);
	return k;
}

int main()
{
	scanf("%d%d", &n, &q);
	comp=1;
	while(comp<n)
	{
		comp<<=1;
	}
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		ins2(i, 1);
	}
	for(int i=1; i<=q; ++i)
	{
		scanf("%d%d", &a, &b);
		zp[a].push_back({b, i});
	}
	a=0;
	for(int i=1; i<=n; ++i)
	{
		if(t[i]<=i && i-a<=t[i])
		{
			st[i+comp-1][0]=t[i]-i+a;
			++a;
			bt[i]=1;
		}
		else
		{
			st[i+comp-1][0]=1e9;
			ins2(i, -1);
		}
		//printf("%d ", st[i+comp-1][0]);
	}
	//printf("\n");
	for(int i=n+comp; i<comp*2; ++i)
	{
		st[i][0]=1e9;
	}
	for(int i=comp-1; i; --i)
	{
		update(i);
	}
	b=a;
	//printf("b=%d;\n", b);
	for(auto j:zp[0])
	{
		odp[j.second]=b-zap2(n-j.first+1, n);
	}
	for(int i=1; i<=n; ++i)
	{
		//printf("((%d))\n", i);
		if(bt[i])
		{
			bt[i]=0;
			insinf(i);
			ins(1, 1, comp, i+1, n, -1);
			--b;
			ins2(i, -1);
			while(st[1][0]<0)
			{
				a=fin(1, 1, comp);
				//printf("REMOVE: %d\n", a);
				insinf(a);
				bt[a]=0;
				ins(1, 1, comp, a+1, n, -1);
				--b;
				ins2(a, -1);
			}
		}
		//printf("b=%d;\n", b);
		for(auto j:zp[i])
		{
			odp[j.second]=b-zap2(n-j.first+1, n);
		}
	}
	for(int i=1; i<=q; ++i)
	{
		printf("%d\n", odp[i]);
	}
	return 0;
}