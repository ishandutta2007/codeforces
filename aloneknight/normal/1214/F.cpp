#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=400005;
int n,m,x,sum,b[N],ss,res[N],p1[N],p2[N],t1,t2;ll ans,nw,c[N*2];
struct st{int p,o,i;}a[N];
inline bool cmp(st x,st y){return x.p<y.p;}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)scanf("%d",&x),a[i]={x,1,i};
	for(int i=0;i<n;i++)scanf("%d",&x),a[i+n]={x,-1,i};
	n<<=1;sort(a,a+n,cmp);b[0]=sum=n;
	for(int i=0;i<n;i++)
	{
		if(a[i].o<0)c[b[i]]-=2ll*a[i].p,nw+=a[i].p;
		else c[b[i]+1]+=2ll*a[i].p,nw-=a[i].p;
		b[i+1]=b[i]+a[i].o;
	}
	for(int i=0;i<=n;i++)nw+=c[i];ans=nw;
	for(int i=0;i<n;i++)
	{
		if(a[i].o<0){nw-=c[sum--];c[b[i]]-=2ll*m;nw+=m;}
		else{nw+=c[++sum];c[b[i]+1]+=2ll*m;nw+=m;}
		if(ans>nw)ans=nw,ss=i+1;
	}
	for(int i=ss;i<n;i++)if(a[i].o<0)p2[t2++]=a[i].i;else p1[t1++]=a[i].i;
	for(int i=0;i<ss;i++)if(a[i].o<0)p2[t2++]=a[i].i;else p1[t1++]=a[i].i;
	for(int i=0;i<t1;i++)res[p1[i]]=p2[i];
	printf("%lld\n",ans);for(int i=0;i<t1;i++)printf("%d ",res[i]+1);
	return 0;
}