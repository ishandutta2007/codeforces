#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 300005;

int a[maxn],b[maxn],c[maxn];
LL  A[maxn],B[maxn],C[maxn];
int n,w,o,p,q;LL ans;
bool comp(int a,int b){return a>b;}
LL calc(int i,int j)
{
	LL v=A[w-3*i-2*j]+B[j]+C[i];
	ans=max(ans,v);return v;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("souvenirs.in","r",stdin);
		freopen("souvenirs.out","w",stdout);
	#endif
	scanf("%d %d",&n,&w);
	for (int w,v,i=1;i<=n;i++)
	{
		scanf("%d %d",&w,&v);
		if (w==1) a[++o]=v;
		if (w==2) b[++p]=v;
		if (w==3) c[++q]=v;
	}
	sort(a+1,a+o+1,comp);
	sort(b+1,b+p+1,comp);
	sort(c+1,c+q+1,comp);
	
	for (int i=1;i<=w;i++) A[i]=A[i-1]+a[i];
	for (int i=1;i<=w;i++) B[i]=B[i-1]+b[i];
	for (int i=1;i<=w;i++) C[i]=C[i-1]+c[i];
	
	for (int i=0;i*3<=w;i++)
	{
		int lb=0,rb=(w-i*3)/2;
		while (rb-lb>10)
		{
			int mid1=(lb*2+rb)/3;
			int mid2=(lb+rb*2)/3;
			calc(i,mid1)>calc(i,mid2)?rb=mid2:lb=mid1;
		}
		for (int j=lb;j<=rb;j++) calc(i,j);
	}
	printf("%lld",ans);
	return 0;
}