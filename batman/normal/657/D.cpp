#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)151*1000)

ll n,p[N],t[N],id[N],min_t[N],max_t[N],all_t;

bool cmp(ll x,ll y){return p[x]*t[y]>p[y]*t[x];}

bool cmp2(ll x,ll y){return p[x]<p[y];}

bool check(ld c)
{
	ld prt_best=p[id[0]]*((ld)1-c*min_t[id[0]]/all_t);
	ld best=0;
	for(int i=1;i<n;i++)
	{
		if(p[id[i]]!=p[id[i-1]])best=max(best,prt_best),prt_best=0;
		ld now=(ld)p[id[i]]*((ld)1-c*max_t[id[i]]/all_t);
		if(now<best)return 0;
		prt_best=max(prt_best,(ld)p[id[i]]*((ld)1-c*min_t[id[i]]/all_t));
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n;i++)cin>>t[i],id[i]=i,all_t+=t[i];
	sort(id,id+n,cmp);
	ll sum=0,now=0,j=0;
	for(int i=0;i<n;i++)
	{
		if(i && p[id[i]]*t[id[i-1]]!=p[id[i-1]]*t[id[i]])
		{
			sum+=now;now=0;
			while(j<i)max_t[id[j]]=sum,j++;
		}
		now+=t[id[i]];
		min_t[id[i]]=sum+t[id[i]];
	}
	sum+=now;
	while(j<n)max_t[id[j]]=sum,j++;
	sort(id,id+n,cmp2);
	ld l=0,r=1;
	for(int i=0;i<50;i++)
	{
		ld mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(16)<<l<<"\n";
	return 0;
}