#include<bits/stdc++.h>
typedef long long ll;
const int maxn=1<<20;
int n,m,k;
char s[1<<20];
int a[1<<20];
int b[1<<20];
int c[1<<20];
inline int fraceil(ll x,int y)
{return(x+y-1)/y;}
const int R=1e5+5;
struct segt
{
	int s[1<<20],mind[1<<20];
	void upd(int l,int r,int d,int p=1,int pl=1,int pr=R)
	{
		/*
		if(p==1)
		{
			//printf("[%d %d]\n",l,d);
		}*/
		if(l>pr||pl>r)return;
		if(l<=pl&&pr<=r){s[p]+=d,mind[p]+=d;return;}
		int pm=(pl+pr)>>1;
		upd(l,r,d,p<<1,pl,pm);
		upd(l,r,d,p<<1|1,pm+1,pr);
		mind[p]=std::min(mind[p<<1],mind[p<<1|1])+s[p];
	}
}T;
struct GROUPS
{
	std::vector<int>w;
	ll S;
	void read()
	{
		w.clear(),S=0;
		int d,z;
		scanf("%d",&d);
		while(d--)
		{
			scanf("%d",&z);
			S+=z,w.push_back(z);
		}
	}
	void reflect(int d)
	{
		T.upd(1,fraceil(S,w.size()),-d);
	}
	void execute()
	{
		reflect(-1);
		for(int t:w)
		{
			int kt=fraceil(S-t,w.size()-1);
			T.upd(1,kt,-1);
			putchar(T.mind[1]>=0?'1':'0');
			T.upd(1,kt,1);
		}
		reflect(1);
	} 
}G[1<<20];
void exec()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		T.upd(1,a[i],1);
	}
	for(int i=1;i<=m;i++)
		G[i].read();
	for(int i=1;i<=m;i++)
		G[i].reflect(1);
	for(int i=1;i<=m;i++)
		G[i].execute();
	for(int i=1;i<=m;i++)
		G[i].reflect(-1);
	for(int i=1;i<=n;i++)
		T.upd(1,a[i],-1);
	puts("");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}