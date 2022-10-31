#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define SQ ((ll)120)
#define QS ((ll)N/SQ)

ll n,m,ans[N],c[N],sum[QS],prt[N],lazy[QS],v[N];
ll first[QS],last[QS];
ll now[QS];

void update(ll x)
{
	if(first[x]!=-1)
	{
		for(int i=x*SQ;i<min(n,(x+1)*SQ);i++)
			ans[i]+=abs(first[x]-c[i])+now[x],
			c[i]=last[x];
	}
	
	now[x]=0;
	first[x]=-1;
	sum[x]=0;
	
	for(int i=x*SQ;i<min(n,(x+1)*SQ);i++)
		v[i]=c[i],sum[x]+=c[i];
	sort(v+x*SQ,v+min(n,(x+1)*SQ));
	for(int i=x*SQ,j=0;i<min(n,(x+1)*SQ);i++,j++)
		prt[i]=v[i]+((i==x*SQ)?0:prt[i-1]);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)c[i]=i+1;
	for(int i=0;i<=(n-1)/SQ;i++)first[i]=-1,update(i);
	while(m--)
	{
		ll t;
		cin>>t;
		//for(int i=0;i<n;i++)cout<<ans[i]<<" ";
		//cout<<"\n";
		//cout<<lazy[0]<<" "<<lazy[1]<<"\n";
		if(t==1)
		{
			ll l,r,x;
			cin>>l>>r>>x;l--;
			ll p=l/SQ;
			update(p);
			while(l%SQ && l<r)ans[l]+=abs(c[l]-x),lazy[l/SQ]+=abs(c[l]-x),c[l]=x,l++;
			update(p);
			p=r/SQ;
			update(p);
			while(r%SQ && l<r)r--,ans[r]+=abs(c[r]-x),lazy[r/SQ]+=abs(c[r]-x),c[r]=x;
			update(p);
			//cout<<"prt "<<prt[1]<<"\n";
			for(int i=l/SQ;i<r/SQ;i++)
			{
				if(first[i]!=-1)
					lazy[i]+=(min(n,(i+1)*SQ)-i*SQ)*abs(last[i]-x),now[i]+=abs(last[i]-x),last[i]=x;
				else
				{
					ll ex=lower_bound(v+i*SQ,v+min(n,(i+1)*SQ),x)-(v+i*SQ);
					if(ex==0)lazy[i]+=sum[i]-x*(min(n,(i+1)*SQ)-i*SQ);
					else
					{
						ex--;
						//cout<<"||||  "<<x*(min(n,(i+1)*SQ)-i*SQ)<<" "<<prt[ex+i*SQ]<<"\n";
						lazy[i]+=x*(ex+1)-prt[ex+i*SQ];
						lazy[i]+=(sum[i]-prt[ex+i*SQ])-x*((min(n,(i+1)*SQ)-i*SQ)-(ex+1));
					}
					first[i]=last[i]=x;
				}
			}
		}
		if(t==2)
		{
			ll l,r,res=0;
			cin>>l>>r;l--;
			update(l/SQ);
			update(r/SQ);
			while(l%SQ && l<r)res+=ans[l++];
			while(r%SQ && l<r)res+=ans[--r];
			for(int i=l/SQ;i<r/SQ;i++)res+=lazy[i];
			cout<<res<<"\n";
		}
	}
	return 0;
}