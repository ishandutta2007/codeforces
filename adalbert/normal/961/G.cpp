#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

int bpow(int u, int step)
{
    if (step==0)
        return(1);
    if (step%2)
        return(bpow(u,step-1)*u%md); else
        return(bpow(u*u%md,step/2));
}

int fact[500000],dp[500000];

int C(int a, int b)
{
    return(fact[a]*bpow(fact[b],md-2)%md*bpow(fact[a-b],md-2)%md);
}

int get(int n,int k)
{
    int ans=0;
    for (int i=0;i<=k;i++)
    {
        if ((k+i)%2)
        {
            ans-=C(k,i)*bpow(i,n)%md;
            ans+=md;
            ans%=md;
        } else
        {
            ans+=C(k,i)*bpow(i,n)%md;
            ans+=md;
            ans%=md;
        }
    }


    return(ans*bpow(fact[k],md-2)%md);
}

signed main()
{
    fast;
    int n,k;
    cin>>n>>k;

    fact[0]=1;
    for (int i=1;i<=200000;i++)
        fact[i]=fact[i-1]*i%md;


    int ans=(get(n,k)+get(n-1,k)*(n-1)%md)%md;
    int sum=0;

    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        sum+=a;
        sum%=md;
    }

    cout<<sum*ans%md;
}
/*
6
0 1
0 -1
1 1
1 -1
-1 -1
-1 1
*/