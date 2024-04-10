#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, int m){int ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=2e5+5;
const int MOD=1e9+7;

int ans[N], bell[N], fact[N], invfact[N];

int modinv(int k)
{
    return pow(k, MOD-2, MOD);
}

void precompute()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    invfact[N-1]=modinv(fact[N-1]);
    for(int i=N-2;i>=0;i--)
    {
        invfact[i]=invfact[i+1]*(i+1);
        invfact[i]%=MOD;
    }
}

int nCr(int n, int r)
{
    int num=fact[n];
    num*=invfact[n-r];
    num%=MOD;
    num*=invfact[r];
    num%=MOD;
    return num;
}

void processbell()
{
    bell[0]=1;
    bell[1]=1;
    for(int i=2;i<=5000;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            bell[i]+=nCr(i-1, j) * bell[j];
            bell[i]%=MOD;
        }
    }
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    precompute();
    processbell();
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        ans[i]=1;
        for(int j=1;j<=i-1;j++)
        {
            ans[i]+=nCr(i,j) * bell[i-j];
            ans[i]%=MOD;
        }
    }
    cout<<ans[n];
    return 0;
}