// Time: 21-07-14 23:21 
#include<bits/stdc++.h>

int n,q,s,d,a[1111111];
int dis[1111111],idx[1111111];
struct pii{int pos,val;};
inline pii min(const pii&x,const pii&y)
{return x.val<y.val?x:y;}
struct segt
{
	pii w[2222222];
	int minx[2222222],maxx[2222222];
	int n1[2222222],p1[2222222],sz[2222222];
	void pushu(int p)
	{
		minx[p]=std::min(minx[p<<1],minx[p<<1|1]);
		maxx[p]=std::max(maxx[p<<1],maxx[p<<1|1]);
		sz[p]=sz[p<<1]+sz[p<<1|1];
		w[p]=min(w[p<<1],w[p<<1|1]);
		w[p]=min(w[p],pii{minx[p],minx[p]+p1[p]});
		w[p]=min(w[p],pii{maxx[p],n1[p]-maxx[p]});
	}
	void init(int p=1,int pl=1,int pr=1e6)
	{
		n1[p]=p1[p]=1e9;
		minx[p]=1e9,maxx[p]=-1e9;
		if(pl==pr)
		{
			sz[p]=(idx[pl]!=0);
			w[p].pos=pl,w[p].val=1e9;
			if(sz[p])minx[p]=maxx[p]=pl;
			return;
		}
		int pm=(pl+pr)>>1;
		init(p<<1,pl,pm),init(p<<1|1,pm+1,pr);
		pushu(p);
	}
	void updn(int l,int r,int v,int p=1,int pl=1,int pr=1e6)
	{
		if(l>r||l>pr||pl>r||!sz[p])return;
		if(l<=pl&&pr<=r)
		{
			if(n1[p]>v)n1[p]=v;
			w[p]=min(w[p],pii{maxx[p],n1[p]-maxx[p]});
			return;
		}
		int pm=(pl+pr)>>1;
		updn(l,r,v,p<<1,pl,pm),updn(l,r,v,p<<1|1,pm+1,pr),
		pushu(p);
	}
	void updp(int l,int r,int v,int p=1,int pl=1,int pr=1e6)
	{
		if(l>r||l>pr||pl>r||!sz[p])return;
		if(l<=pl&&pr<=r)
		{
			if(p1[p]>v)p1[p]=v;
			w[p]=min(w[p],pii{minx[p],p1[p]+minx[p]});
			return;
		}
		int pm=(pl+pr)>>1;
		updp(l,r,v,p<<1,pl,pm),updp(l,r,v,p<<1|1,pm+1,pr),
		pushu(p);
	}
	void erase(int x,int p=1,int pl=1,int pr=1e6)
	{
		if(pl==pr)
		{
			p1[p]=n1[p]=1e9,sz[p]=0;
			minx[p]=1e9,maxx[p]=-1e9,w[p].val=1e9;
			return;
		}
		int pm=(pl+pr)>>1,dr=x>pm;
		dr?pl=pm+1:pr=pm,erase(x,p<<1|dr,pl,pr),pushu(p);
	}
}S;

void upd(int x)
{
	S.erase(x);
	S.updn(x+1,x+d,x+d);
	S.updp(x-d,x-1,d-x);
	S.updp(x+d,1e6,-x-d);
	S.updn(1,x-d,x-d);
}
int findMin()
{return S.w[1].pos;}
int valMin()
{return S.w[1].val;}
int main()
{
	scanf("%d%d%d%d",&n,&q,&s,&d);
	for(register int i=1;i<=n;i++)scanf("%d",a+i),idx[a[i]]=i;
	memset(dis,0x3f,sizeof dis),dis[a[s]]=0;
	S.init(),upd(a[s]);
	int cr=0;
	for(register int i=1;i<n;i++)
	{
		int p=findMin();dis[p]=valMin();
		//printf("%d %d\n",p,dis[p]);
		if(dis[p]<cr)dis[p]=cr;
		if(cr<dis[p])cr=dis[p];
		upd(p);
	}
	for(register int i=1;i<=q;i++)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		puts((dis[a[x]]<=k)?"YES":"NO");
	}
}