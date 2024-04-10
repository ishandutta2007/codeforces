#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (111)

ll n,d,a[N],dis[N];
pair <ll,ll> c[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>d;
    for(int i=2;i<n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>c[i].first>>c[i].second;
    for(int i=2;i<=n;i++)dis[i]=INF;
    set <pair<ll,ll> > s;
    s.insert({0,1});
    while(s.size())
    {
        ll x=s.begin()->second;
        s.erase(s.begin());
        for(int i=1;i<=n;i++)
            if(i!=x && dis[i]>dis[x]+(abs(c[i].first-c[x].first)+abs(c[i].second-c[x].second))*d-a[i])
            {
                s.erase({dis[i],i});
                dis[i]=dis[x]+(abs(c[i].first-c[x].first)+abs(c[i].second-c[x].second))*d-a[i];
                s.insert({dis[i],i});
            }
    }   
    cout<<dis[n];
    return 0;
}