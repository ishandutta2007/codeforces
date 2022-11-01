#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (111)
#define MOD ((ll)1e9+7)

struct cube{
    ll w,h,id;
    cube( ll a, ll b, ll c ): w(a), h(b), id(c) {}
};

ll n,l,dp[N*2][3100];
vector <cube> c;

int main()
{
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        c.push_back(cube(a,b,i));
        dp[c.size()-1][a]=1;
        if(a!=b)
            c.push_back(cube(b,a,i)),dp[c.size()-1][b]=1;
    }   
    for(int j=1;j<=l;j++)     
        for(int i=0;i<c.size();i++)    
           for(int p=0;p<c.size();p++)
           {
               if(c[p].id==c[i].id)continue;
               if(c[p].w==c[i].h)
                   dp[p][j+c[p].w]+=dp[i][j],dp[p][j+c[p].w]%=MOD;
           }
    ll ans=0;       
    for(int i=0;i<c.size();i++) {
        ans+=dp[i][l];
        ans%=MOD;
       }
    cout<<ans;       
    return 0;
}