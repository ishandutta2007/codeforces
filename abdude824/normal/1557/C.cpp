#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int mpow(int exp, int base);
int modInverse(int n)
{
    return mpow(n,mod-2);
}
int findCombinations(int n)
{
    int t=n;
    int fac[n+1];
    fac[0]=1;

    for(int i=1;i<=n;i++)
    {
        fac[i]=((fac[i-1]%mod)*(i%mod))%mod;
        fac[i]%=mod;
    }

    int ans=0;
    for(int i=0;i<n;i+=2)
    {
        ans+=(fac[n]*modInverse(fac[i])%mod * modInverse(fac[n-i]%mod)%mod);
        ans%=mod;
    }
    return ans;
}

int32_t main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        int dp[k+1];
        dp[0]=1;

        int x=findCombinations(n);
        int y=findCombinations(n);


        for(int i=1;i<=k;i++)
        {
            if(n%2)
            {
                dp[i]=(y+1)*dp[i-1];
                dp[i]%=mod;
            }
            else{
                int a=mpow(2,i-1);
                a%=mod;
                a=mpow(a,n);
                a%=mod;
                dp[i]=a+x*dp[i-1];
                dp[i]%=mod;

            }
        }
        cout<<dp[k]<<endl;
    }
    
    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}