#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	long long a[n];
	for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
	map<long long,int> m;
	long long sum=0;
	for(int i=n-1;i>=0;i--)
    {
        sum+=a[i];
        m[sum]=i;
    }
    sum=0;
    long long res=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(m.find(sum)!=m.end()&&m[sum]>i) res=sum;
    }
    printf("%I64d\n",res);
	return 0;
}