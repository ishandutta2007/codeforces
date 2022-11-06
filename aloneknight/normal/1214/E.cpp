#include<bits/stdc++.h>
using namespace std;
int n,b[200005];
struct st{int d,i;}a[200005];
bool cmp(st a,st b){return a.d>b.d;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].d),a[i].i=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)b[i]=a[i].i*2;
	for(int i=2;i<=n;i++)printf("%d %d\n",a[i-1].i*2,a[i].i*2);
	for(int i=1;i<=n;i++)
	{
		int t=i+a[i].d;if(!b[t])b[t]=2*a[i].i-1;
		t--;printf("%d %d\n",b[t],2*a[i].i-1);
	}
	return 0;
}