#include<bits/stdc++.h>
int n;
struct pii
{
	int a,rk,ps;
}p[1111111];
int r[1111111];
bool operator<(pii x,pii y){return x.a<y.a;}
bool resum(pii x,pii y){return x.ps<y.ps;}
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return y<x?x:y;}
namespace segt
{
	struct Nod
	{
		int mx,mn,tg;
		void add(int d){tg+=d,mx-=d,mn-=d;}
	}tr[5555555];
	void pushu(int p)
	{
		tr[p].mx=min(tr[p<<1].mx,tr[p<<1|1].mx);
		tr[p].mn=max(tr[p<<1].mn,tr[p<<1|1].mn);
	}
	void pushd(int p)
	{tr[p<<1].add(tr[p].tg),tr[p<<1|1].add(tr[p].tg),tr[p].tg=0;}
	void init(int p=1,int pl=1,int pr=n+1)
	{
		if(pl==pr)
		{
			tr[p].mn=-1e9,tr[p].mx=1e9;
			return;
		}
		int md=(pl+pr)>>1;
		init(p<<1,pl,md),init(p<<1|1,md+1,pr),pushu(p);
	}
	bool updad(int L,int p=1,int pl=1,int pr=n+1)
	{
		if(L>pr)return 1;
		int md=(pl+pr)>>1;
		if(L<=pl)
		{
			if(tr[p].mx>1){tr[p].add(1);return 1;}
			if(pl==pr)
			{
				tr[p].tg++;
				if(r[pl]>tr[p].tg)tr[p].mn=-1e9,tr[p].mx=r[pl]-tr[p].tg;
				else if(r[pl]<tr[p].tg)tr[p].mn=r[pl]-tr[p].tg,tr[p].mx=1e9;
				else tr[p].mn=tr[p].mx=0;
				return 0;
			}
			pushd(p);
			bool ret=0;
			if(updad(L,p<<1,pl,md))ret=updad(L,p<<1|1,md+1,pr);
			else ret=0;
			pushu(p);
			return ret;
		}pushd(p);
		bool ret=1;
		if(updad(L,p<<1,pl,md))ret=updad(L,p<<1|1,md+1,pr);
		else ret=0;
		pushu(p);
		return ret;
	}
	bool updmi(int L,int p=1,int pl=1,int pr=n+1)
	{
		if(L>pr)return 1;
		int md=(pl+pr)>>1;
		if(L<=pl)
		{
			if(tr[p].mn<-1){tr[p].add(-1);return 1;}
			if(pl==pr)
			{
				tr[p].tg--;
				if(r[pl]>tr[p].tg)tr[p].mn=-1e9,tr[p].mx=r[pl]-tr[p].tg;
				else if(r[pl]<tr[p].tg)tr[p].mn=r[pl]-tr[p].tg,tr[p].mx=1e9;
				else tr[p].mn=tr[p].mx=0;
				return 0;
			}
			pushd(p);
			bool ret=1;
			if(updmi(L,p<<1,pl,md))ret=updmi(L,p<<1|1,md+1,pr);
			else ret=0;
			pushu(p);
			return ret;
		}pushd(p);
		bool ret=1;
		if(updmi(L,p<<1,pl,md))ret=updmi(L,p<<1|1,md+1,pr);
		else ret=0;
		pushu(p);
		return ret;
	}
	void use(int x,int p=1,int pl=1,int pr=n+1)
	{
		if(pl==pr)
		{
			if(r[pl]>tr[p].tg)tr[p].mn=-1e9,tr[p].mx=r[pl]-tr[p].tg;
			else if(r[pl]<tr[p].tg)tr[p].mn=r[pl]-tr[p].tg,tr[p].mx=1e9;
			else tr[p].mn=tr[p].mx=0;
			return;
		}pushd(p);
		int md=(pl+pr)>>1,dr=x>md;
		dr?pl=md+1:pr=md,use(x,p<<1|dr,pl,pr),pushu(p);
	}
	int qry(int x,int p=1,int pl=1,int pr=n+1)
	{
		if(pl==pr)return tr[p].tg;
		pushd(p);
		int md=(pl+pr)>>1,dr=x>md;
		return dr?pl=md+1:pr=md,qry(x,p<<1|dr,pl,pr);
	}
}
void ins(int x,int v)
{
	int qv=segt::qry(x);
	if(qv>v)segt::updmi(x+1);
	if(qv<v)segt::updad(x+1);
	segt::use(x);
}
int main()
{
	scanf("%d",&n),segt::init();
	register int i;
	for(i=1;i<=n;i++)scanf("%d",&p[i].a),p[i].ps=i;
	std::sort(p+1,p+n+1);
	for(i=1;i<=n;i++)p[i].rk=i,r[i]=p[i].a;
	std::sort(p+1,p+n+1,resum);
	for(i=1;i<=n;i++)ins(p[i].rk,p[i].a),printf("%d\n",segt::qry(n+1));
}