#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)501*1000)
#define INF ((ll)1e9+1)
#define SQ ((ll)500)


ll n,q,a[N],lazy[N/SQ+20];
set <ll> s[N/SQ+20];

void reset(ll x,ll l,ll r,ll num)
{
	s[x].clear();
	if(lazy[x]==INF)return ;
	for(int i=x*SQ;i<min((x+1)*SQ,n);i++)
	{
		a[i]=min(a[i]+lazy[x],INF);
		if(i>=l && i<r)a[i]=min(a[i]+num,INF);
		if(a[i]==INF)continue;
		s[x].insert(a[i]);
	}
	lazy[x]=0;
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s[i/SQ].insert(a[i]);
	}
	while(q--)
	{
		ll t;
		scanf("%d",&t);
		if(t==1)
		{
			ll l,r,x;
			scanf("%d%d%d",&l,&r,&x);l--;
			reset(l/SQ,l,r,x);
			if(r/SQ!=l/SQ)reset(r/SQ,l,r,x);
			//cout<<mark[0][3]<<" "<<lft[0][3]<<" "<<rght[0][3]<<"\n";
			for(int i=l/SQ+1;i<r/SQ;i++)lazy[i]=min(lazy[i]+x,INF);
		}
		if(t==2)
		{
			ll x;
			scanf("%d",&x);
			ll mini=INF,maxi=-1;
			for(int i=0;i<=(n-1)/SQ;i++)
				if(lazy[i]!=INF)
					if(s[i].count(x-lazy[i]))
						mini=min(mini,i),
						maxi=max(maxi,i);
			if(maxi==-1){printf("-1\n");continue;}
			ll mini2,maxi2;
			for(int i=maxi*SQ;i<min(n,(maxi+1)*SQ);i++)
				if(a[i]+lazy[maxi]==x)
					maxi2=i;
			for(int i=min(n,(mini+1)*SQ)-1;i>=mini*SQ;i--)
				if(a[i]+lazy[mini]==x)
					mini2=i;			
			printf("%d\n",maxi2-mini2);
		}
	}
	
	return 0;
}