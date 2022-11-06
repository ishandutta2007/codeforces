#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,mn=1e9+7;ll s,d;
struct st{int t,c,i;}a[1005]; 
bool operator<(st a,st b){return a.t^b.t?a.t<b.t:a.c>b.c;}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].c,&a[i].t),a[i].i=i+1,s+=a[i].c,mn=min(mn,a[i].c);
	sort(a,a+n);
	for(int i=0;i<k-1&&a[i].t==1;i++)d+=a[i].c;
	if(a[k-1].t==1)d+=mn;
	printf("%lld.%lld\n",(s*10-d*5)/10,(s*10-d*5)%10);
	for(int i=0;i<k-1;i++)printf("1 %d\n",a[i].i);
	printf("%d ",n+1-k);
	for(int i=k-1;i<n;i++)printf("%d ",a[i].i);
	return 0;
}