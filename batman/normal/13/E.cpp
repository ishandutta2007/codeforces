// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((101*1000))
#define SQ (400)

ll n,q,a[N];
pair <ll,ll> b[N];

void build(ll x)
{
	ll l=x*SQ,r=min(n,(x+1)*SQ)-1;
	//cout<<l<<" "<<r<<"\n";
	for(int i=r;i>=l;i--)
	{
		if(i+a[i]>r)b[i]={1,i};
		else b[i]={b[i+a[i]].first+1,b[i+a[i]].second};
	}
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<(n+SQ-1)/SQ;i++)
		build(i);
	//for(int i=0;i<n;i++)cout<<b[i].first<<" ";
	//cout<<"\n";
	while(q--)
	{
		ll t;
		scanf("%d",&t);
		if(t==0)
		{
			ll x,y;
			scanf("%d%d",&x,&y);x--;
			a[x]=y;build(x/SQ);
		}
		else
		{
			ll x,res=0,last;
			scanf("%d",&x);x--;
			while(x<n)res+=b[x].first,last=b[x].second,x=b[x].second+a[b[x].second];
			printf("%d %d\n",last+1,res);
		}
	}
	return 0;
}