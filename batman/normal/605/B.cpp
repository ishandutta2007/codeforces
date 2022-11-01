#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define MOD ((ll)1e9+7)

ll n,m,now=1,last[N];
pair <ll,ll> ans[N];
stack <ll> empty;
pair <ll,pair<bool,ll> > a[N];
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>a[i].first>>a[i].second.first,a[i].second.first=!a[i].second.first,a[i].second.second=i;
    sort(a,a+m);
    for(int i=0;i<m;i++)
    {
        if(i>now*(now-1)/2)return cout<<-1,0;
        if(a[i].second.first==0)
        {
            ans[a[i].second.second]={now,now+1};
            now++;  
            empty.push(now);
            last[now]=now-2;
            continue;
        }
        bool did=0;
        while(empty.size())
        {
            ll x=empty.top();
            if(last[x]>0)
            {
                ans[a[i].second.second]={x,last[x]};
                last[x]--;
                did=1;
                break;
            }
            empty.pop();
        }
        if(!did)return cout<<-1,0;
    }
    for(int i=0;i<m;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return 0;
}