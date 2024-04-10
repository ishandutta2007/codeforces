#include<stdio.h>
#include<bits/stdc++.h>
typedef long long ll;
typedef double db;

struct pii
{
	int a,b;
	pii():a(0),b(0){}
	pii(int aa,int bb):a(aa),b(bb){}
};

std::vector<int>d[1<<20],e[1<<20];
void init()
{
	for(int i=1;i<=200000;i++)
		for(int ii=i<<1;ii<=200000;ii+=i)
			e[ii].push_back(i);
	for(int i=1;i<=200000;i++)
		for(int ii=i<<1;ii<=200000;ii+=i)
			if(e[ii/i].size()==1)
				d[ii].push_back(i);
}

namespace __sol
{
	int n,m;
	int a[1<<20];
	struct pq
	{
		std::vector<ll>w;
		int rllen;
		void giv(int t,ll v)
		{
			int i=t+rllen-1;
			w[i]+=v;
			for(i>>=1;i;i>>=1)
			{
				ll d=std::max(w[i<<1],w[i<<1|1]);
				if(d==w[i])break;
				w[i]=d;
			}
		}
		ll top(){return w[1];}
		void clear(int l)
		{
			for(rllen=1;rllen<=l;rllen<<=1);
			w.resize(rllen<<1);
			for(int i=0;i<(rllen<<1);i++)w[i]=0;
		}
	};
	pq s[1<<20];
	std::vector<ll>v[1<<20];
	void qqq()
	{
		ll ans=0;
		for(int e:d[n])
		{
			ans=std::max(ans,s[e].top());
		}
		printf("%lld\n",ans);
	}
	void solve()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			if(n%i==0)
			{
				s[i].clear(i);
				v[i].resize(i+1);
				for(int ii=0;ii<=i;ii++)
					v[i][ii]=0;
			}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			for(int e:d[n])
			{
				//printf("? %d\n",e);
				v[e][i%e]+=a[i];
				//puts("!");
			}
		}
		for(int e:d[n])
		{
			for(int i=0;i<e;i++)
				s[e].giv(i,v[e][i]*e);
		}
		qqq();
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int det=y-a[x];
			a[x]=y;
			for(int e:d[n])
			{
				int t=x%e;
				s[e].giv(t,det*1ll*e);
			}
			qqq();
		}
	}
}

int main()
{
	int T=1;
	scanf("%d",&T);
	init();
	//printf("%d\n",d[166320].size());
	while(T--)
	{
		__sol::solve();
	}
}