#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,d,a,b;
vector <pair<ll,ll> > v;
vector <ll> ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>d>>a>>b;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x*a+y*b,i+1});
    }
    sort(v.begin(),v.end());
    for(ll i=0,sum=0;i<v.size();i++)
    {
        if(sum+v[i].first>d)break;
        sum+=v[i].first;
        ans.push_back(v[i].second);
    }
    cout<<(ll)ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}