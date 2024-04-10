#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD=1e9+7;

int n, m;

int f(int k)
{
    if(k%2)
    {
        int a=((k+1)/2) % MOD;
        int b=k%MOD;
        a*=b;
        a%=MOD;
        return a;
    }
    else
    {
        int a=(k/2) % MOD;
        int b=(k+1) % MOD;
        a*=b;
        a%=MOD;
        return a;
    }
}

int calc(int k)
{
    int left=n/(k+1) + 1;
    int right=n/k;
    right=min(right, m);
    int sum=f(right) - f(left-1) + MOD;
    if(left>right)
        sum=0;
    sum%=MOD;
    sum*=(k%MOD);
    sum%=MOD;
    return sum;
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    int ans=(n%MOD) * (m%MOD);
    ans%=MOD;
    for(int i=1;i*i<=n;i++)
    {
        ans-=calc(i);
        if(n/i != i)
            ans-=calc(n/i);
        while(ans<0)
            ans+=MOD;
    }
    cout<<ans;
    return 0;
}