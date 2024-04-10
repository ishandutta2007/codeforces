#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int main()
{
	int n;
	scanf("%d",&n);
	long long a[n];
	long long m=0;
	long long sum=0;
	for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        m=max(m,a[i]);
        sum+=a[i];
    }
    long long z=0;
    for(int i=0;i<n;i++) z=gcd(z,m-a[i]);
    printf("%I64d %I64d\n",(n*m-sum)/z,z);
	return 0;
}