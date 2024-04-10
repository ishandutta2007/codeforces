#include <iostream>

using namespace std;

#define ll long long

const int N=5000005;
bool prime[N];
ll pf[N];
void sieve()
{
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i*i<=N-2;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

ll dp[N];

int main()
{
    sieve();
    int T;
    scanf("%d",&T);
    for(int i=2;i<=5e6;++i)
    {
        dp[i] = dp[i-1];
        int x = i;
        while(x!=1 && !prime[x])
        {
            int k = pf[x];
            while(x%k==0)
                ++dp[i],x/=k;
        }
        dp[i] += x!=1;
    }
    while(T--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",dp[a]-dp[b]);
    }
}