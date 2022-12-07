#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PI;
const LL N=200005;
LL n,q;
LL a[N];
vector<PI> vec;
set<LL> s;
LL one[N],two[N];
LL L[N],R[N],sum_one[N],sum_two[N];
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++) 	{scanf("%lld",&a[u]);vec.push_back({a[u]-u,u});}
	sort(vec.begin(),vec.end());
	s.insert(n+1);s.insert(n+2);
	for (LL u=n,i=0;u>=1;u--)
	{
		while (i<n&&vec[i].first<=-u) s.insert(vec[i++].second);
		one[u]=*s.lower_bound(u);
		two[u]=*next(s.lower_bound(u));
	}
	for (LL u=1;u<=n;u++)
	{
		sum_one[u]=sum_one[u-1]+one[u];
		sum_two[u]=sum_two[u-1]+two[u];
		R[one[u]]=u;
		if (!L[one[u]]) L[one[u]]=u;
		
	}
	scanf("%lld",&q);
	LL t=(1+n)*n/2;
	while (q--)
	{
		LL p,x;
		scanf("%lld%lld",&p,&x);
		LL ans=sum_one[n]-t;
		if (a[p]>x)
		{
			LL k=p-x;
			if (k>=1&&one[k]>p)
			{
				LL l=1,r=k,xx;
				while (l<=r)
				{
					LL mid=(l+r)>>1;
					if (one[mid]>p) {r=mid-1;xx=mid;}
					else l=mid+1;
				}
				ans=ans-(sum_one[k]-sum_one[xx-1]);
				ans=ans+p*(k-xx+1);
			}
		}
		if (a[p]<x&&L[p]!=0)
		{
			LL k=max(1ll,p-x+1);
			LL l=max(L[p],k),r=R[p];
			if (l<=r)
			{
				ans=ans+(sum_two[r]-sum_two[l-1]);
				ans=ans-(sum_one[r]-sum_one[l-1]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}