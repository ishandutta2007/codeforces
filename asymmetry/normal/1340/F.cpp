//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng;
int ran(int a, int b)
{
	return uniform_int_distribution<int>(a,b)(rng);
}

struct node
{
	int l, r;
	int pri, siz;
	int war;
	long long hs;
};

struct ver
{
	int cl, op;
	bool broken;
};

int n, q, a, b, com, akt, p;
long long pie=207679, mod=990404609;
vector <long long> pot;
vector <node> t;
vector <ver> st;
vector <int> wol;
vector <vector<int>> sklad;

int dajw(int x)
{
	int y=wol[p--];
	t[y]={0, 0, ran(1,1e9), 1, x, x};
	return y;
}

int dajn(int x)
{
	int y=wol[p--];
	t[y]=t[x];
	sklad[akt].push_back(y);
	return y;
}

void oddaj(int x)
{
	for(int i:sklad[x]) wol[++p]=i;
	sklad[x].clear();
}

void update(int x)
{
	t[x].siz=t[t[x].l].siz+t[t[x].r].siz+1;
	t[x].hs=(t[t[x].l].hs+pot[t[t[x].l].siz]*t[x].war+t[t[x].r].hs*pot[t[t[x].l].siz+1])%mod;
}

void split(int x, int &l, int &r, int ile)
{
	if(!x)
	{
		l=r=0;
		return;
	}
	x=dajn(x);
	if(ile<=t[t[x].l].siz)
	{
		split(t[x].l, l, t[x].l, ile);
		r=x;
	}
	else
	{
		split(t[x].r, t[x].r, r, ile-t[t[x].l].siz-1);
		l=x;
	}
	update(x);
}

void meld(int l, int r, int &x)
{
	if(!l)
	{
		x=r;
		return;
	}
	if(!r)
	{
		x=l;
		return;
	}
	if(t[l].pri<t[r].pri)
	{
		x=dajn(l);
		meld(t[x].r, r, t[x].r);
	}
	else
	{
		x=dajn(r);
		meld(l, t[x].l, t[x].l);
	}
	update(x);
}

void merge(ver &x, ver l, ver r)
{
	if(l.broken || r.broken)
	{
		x.broken=true;
		return;
	}
	if(t[l.op].siz>t[r.cl].siz)
	{
		int lf=0, rg=0;
		split(l.op, lf, rg, t[l.op].siz-t[r.cl].siz);
		if(t[rg].hs!=t[r.cl].hs)
		{
			x.broken=true;
			return;
		}
		x.cl=l.cl;
		meld(lf, r.op, x.op);
		x.broken=false;
	}
	else
	{
		int lf=0, rg=0;
		split(r.cl, lf, rg, t[r.cl].siz-t[l.op].siz);
		if(t[rg].hs!=t[l.op].hs)
		{
			x.broken=true;
			return;
		}
		x.op=r.op;
		meld(lf, l.cl, x.cl);
		x.broken=false;
	}
}

void ins(int x, int y)
{
	x+=com;
	if(y<0)
	{
		st[x]={dajw(-y), 0, 0};
	}
	else
	{
		st[x]={0, dajw(y), 0};
	}
	x>>=1;
	while(x)
	{
		oddaj(x);
		akt=x;
		merge(st[x], st[x*2], st[x*2+1]);
		x>>=1;
	}
}

bool zap(int x, int y)
{
	x+=com;
	y+=com;
	vector <int> lf, rg;
	while(x<=y)
	{
		if(x&1)
		{
			if(st[x].broken) return false;
			lf.push_back(x);
			++x;
		}
		if(!(y&1))
		{
			if(st[y].broken) return false;
			rg.push_back(y);
			--y;
		}
		x>>=1;
		y>>=1;
	}
	reverse(rg.begin(), rg.end());
	ver last={0, 0, 0};
	for(auto i:lf)
	{
		merge(last, last, st[i]);
		//~ if(last.broken) return false;
		if(last.broken || t[last.cl].siz) return false;
	}
	for(auto i:rg)
	{
		merge(last, last, st[i]);
		//~ if(last.broken) return false;
		if(last.broken || t[last.cl].siz) return false;
	}
	if(t[last.cl].siz || t[last.op].siz) return false;
	return true;
}

int main()
{
	scanf("%d%*d", &n);
	int m=max((int)1e5, n*20);
	t.resize(m);
	wol.resize(m);
	for(int i=1; i<m; ++i) wol[i]=i;
	p=m-1;
	com=1;
	while(com<n) com<<=1;
	st.resize(com<<1);
	sklad.resize(com<<1);
	pot.resize(com+1);
	pot[0]=1;
	for(int i=1; i<=com; ++i) pot[i]=pot[i-1]*pie%mod;
	--com;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &a);
		if(a<0)
		{
			st[i+com]={dajw(-a), 0, 0};
		}
		else
		{
			st[i+com]={0, dajw(a), 0};
		}
	}
	for(int i=n+1; i<=com+1; ++i) st[i+com]={0, 0, 0};
	for(int i=com; i; --i)
	{
		akt=i;
		merge(st[i], st[i*2], st[i*2+1]);
	}
	scanf("%d", &q);
	for(int i=1; i<=q; ++i)
	{
		scanf("%d", &a);
		if(a&1)
		{
			scanf("%d%d", &a, &b);
			ins(a, b);
		}
		else
		{
			scanf("%d%d", &a, &b);
			akt=0;
			if(zap(a, b)) printf("Yes\n");
			else printf("No\n");
			oddaj(0);
		}
	}
	return 0;
}