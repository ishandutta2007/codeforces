#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,k,p,t;
LL l=0,r=0,mid,w;
LL h[100002],a[100002],b[100002];
vector<int> vec[5002];
inline bool ins(int x,int y)
{
	if(b[y]<a[y])
	{
		w=(a[y]-b[y]+p-1)/p,b[y]+=w*p;
		if((t-=w)<0)return 0;
	}
	if(x+b[y]/a[y]<m)vec[x+b[y]/a[y]].push_back(y),b[y]%=a[y];
	else b[y]-=a[y]*(m-x);
	return 1;
}
inline bool check(LL x)
{
	t=0;
	for(int i=0;i<m;++i)vec[i].clear();
	for(int i=1;i<=n;++i)vec[0].push_back(i),b[i]=x;
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<vec[i].size();++j)if(!ins(i,vec[i][j]))return 0;
		t+=k;
	}
	for(int i=1;i<=n;++i)if(b[i]<h[i] && (t-=(h[i]-b[i]+p-1)/p)<0)return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&h[i],&a[i]),r=max(r,h[i]+a[i]*m*k);
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	return 0&printf("%lld",l);
}