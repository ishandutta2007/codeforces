#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005,M=1000000007;

int n,k,t;

bool stg(int x)
{
    while(x)
    {
        if(x%10!=4 && x%10!=7)
            return false;
        x/=10;
    }
    return true;
}

int f[N];
void pre()
{
    f[0]=1;
    for(int i=1;i<=n;++i)
    {
        f[i]=(f[i-1]*i)%M;
    }
}

int powpow(int a,int n)
{
    if(n==0)
        return 1;
    if(n%2)
    {
        int u=powpow(a,n-1);
        return (u*a)%M;
    }
    else
    {
        int u=powpow(a,n/2);
        return (u*u)%M;
    }
}

int dividi(int a,int b)
{
    return (a*powpow(b,M-2))%M;
}

int zug(int n,int k)
{
    return dividi(f[n],(f[n-k]*f[k])%M);
}

int dp[1200][1200];
int32_t main()
{
    cin>>n>>k;
    map<int,int> m;
    vector<int> v;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(stg(x))
        {
            m[x]++;
            v.push_back(x);
        }
        else
        {
            ++t;
        }
    }
    sort(v.begin(),v.end());
    vector<int> vv;
    for(int i=1;i<v.size();++i)
    {
        if(v[i]!=v[i-1])
            vv.push_back(v[i-1]);
    }
    if(!v.empty())
        vv.push_back(v.back());
    v=vv;
    pre();
    /////////////////////////////
    dp[0][0]=1;
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<v.size();++j)
        {
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=M;
            dp[i+1][j+1]+=(dp[i][j]*m[v[i]]);
            dp[i+1][j+1]%=M;
        }
    }
    int ans=0;
    for(int j=0;j<=v.size();++j)
    {
        if(k-j<0)
            break;
        ans+=(dp[v.size()][j]*zug(t,k-j))%M;
        ans%=M;
    }
    cout<<ans<<endl;
    return 0;
}