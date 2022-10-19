#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,l=0,r=2000000001,mid,cnt;
LL res,ans;
int a[500002],b[500002];
typedef pair<int,int> P;
P p;
priority_queue<P,vector<P>,greater<P> > pq,ept;
inline bool check()
{
	pq=ept,cnt=res=0;
	for(int i=1;i<=n;++i)
	{
		pq.push(P(a[i]-mid,0)),p=pq.top();
		if((LL)b[i]+p.first<=0)pq.pop(),cnt+=(!p.second),res+=(LL)b[i]+p.first,pq.push(P(-b[i],1));
	}
	if(cnt>=k)ans=res;
	return cnt>=k;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(;l<=r;)
	{
		mid=l+((r-l)>>1);
		if(check())r=mid-1;
		else l=mid+1;
	}
	return 0&printf("%lld",ans+(LL)k*l);
}