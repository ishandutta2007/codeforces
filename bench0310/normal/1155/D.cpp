#include <bits/stdc++.h>

using namespace std;
const int N=300000;

int n;
long long x;
long long a[N];

int main()
{
	scanf("%d %I64d",&n,&x);
	for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
    long long res=0;
    long long segl[n],segr[n];
    segl[0]=max(0ll,a[0]);
    for(int i=1;i<n;i++) segl[i]=max(max(segl[i-1]+a[i],a[i]),0ll);
    segr[n-1]=max(0ll,a[n-1]);
    for(int i=n-2;i>=0;i--) segr[i]=max(max(segr[i+1]+a[i],a[i]),0ll);
    for(int i=0;i<n;i++) a[i]*=x;
    long long bestl[n],bestr[n];
    bestl[0]=max(a[0],segl[0]);
    for(int i=1;i<n;i++) bestl[i]=max(bestl[i-1]+a[i],segl[i]);
    bestr[n-1]=max(a[n-1],segr[n-1]);
    for(int i=n-2;i>=0;i--) bestr[i]=max(bestr[i+1]+a[i],segr[i]);
    res=max(res,max(bestl[0],bestr[n-1]));
    for(int i=0;i<n-1;i++) res=max(res,bestl[i]+bestr[i+1]);
    printf("%I64d\n",res);
	return 0;
}