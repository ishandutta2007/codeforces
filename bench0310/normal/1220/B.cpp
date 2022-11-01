#include <bits/stdc++.h>

using namespace std;

long long root(long long a)
{
    long long l=1,r=1000000001;
    while(l<r-1)
    {
        long long m=(l+r)/2;
        if(m*m<=a) l=m;
        else r=m;
    }
    return l;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long a[n][n];
	for(int o=0;o<n;o++) for(int i=0;i<n;i++) scanf("%I64d",&a[o][i]);
	long long x=a[0][1];
	long long y=a[0][2];
	long long z=a[1][2];
    long long res=root((x*y)/z);
    printf("%I64d ",res);
    for(int i=1;i<n;i++) printf("%I64d ",a[0][i]/res);
    printf("\n");
	return 0;
}