#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll x,k,f[N],sum=1;
vector <ll> ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x>>k;
    f[0]=1;
    int i;
    for(i=1;i<N;i++)
    {
        if(sum>=(ll)1e9)break;
        f[i]=sum;
        sum+=f[i];
        if(i-k>=0)sum-=f[i-k];
        //cout<<f[i]<<" ";
    }
    i--;
    for(;i>=0 && x>=0;i--)
       if(x>=f[i])ans.push_back(f[i]),x-=f[i];
    ans.push_back(0); 
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";

    return 0;
}