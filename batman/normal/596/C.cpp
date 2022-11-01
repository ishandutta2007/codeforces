#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,x,y;
map <ll,pair<vector <pair<ll,ll> >,ll> > mp;
pair <ll,ll> ans[N];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        mp[y-x].first.push_back({x,y});
        mp[y-x].second=0;
    }
    for(map <ll,pair<vector <pair <ll,ll> >,ll> >::iterator it=mp.begin();it!=mp.end();it++)
        sort(it->second.first.begin(),it->second.first.end());
    pair <ll,ll> last;
    last={-1,-1};   
    for(int i=0;i<n;i++)
    {
        ll w;
        cin>>w;
        if(mp[w].first.size()<=mp[w].second)
            return cout<<"NO",0;
        if(mp[w].first[mp[w].second].first<=last.first && mp[w].first[mp[w].second].second<=last.second)
            return cout<<"NO",0;    
        ans[i]=mp[w].first[mp[w].second++]; 
        if(ans[i].first>=last.first && ans[i].second>=last.second)
            last=ans[i];    
    }   
    cout<<"YES\n";
    for(int i=0;i<n;i++)
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    
    return 0;
}