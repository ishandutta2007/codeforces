#include <bits/stdc++.h>

using namespace std;

int main()
{
    const long long mod=998244353;
	int n;
	scanf("%d",&n);
	vector<long long> a(n+1,0);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	vector<long long> t(n+1,1);
	for(int i=1;i<=n;i++) t[i]=(t[i-1]*2)%mod;
	long long sum=0;
	long long res=0;
	for(int i=1;i<=n;i++)
    {
        sum=(sum+a[i])%mod;
        if(i==n) res=(res+sum)%mod;
        else
        {
            res=(res+2*t[n-1-i]*sum)%mod;
            res=(res+(((n-i-1)*t[n-2-i])%mod)*sum)%mod;
        }
    }
    printf("%I64d\n",res);
	return 0;
}