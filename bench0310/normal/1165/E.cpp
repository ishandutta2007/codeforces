#include <bits/stdc++.h>

using namespace std;

int main()
{
    const long long mod=998244353;
	long long n;
	scanf("%I64d",&n);
	vector<long long> a(n),b(n);
	for(long long i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        a[i]*=((i+1)*(n-i));
    }
    sort(a.begin(),a.end());
    for(long long i=0;i<n;i++) scanf("%I64d",&b[i]);
    sort(b.begin(),b.end(),greater<long long>());
    long long res=0;
    for(long long i=0;i<n;i++) res=(res+(a[i]%mod)*b[i])%mod;
    printf("%I64d\n",res);
	return 0;
}