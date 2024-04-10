#include"bits/stdc++.h"
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    pair<ll,ll>t;
    t.second=0;
    vector<pair<ll,ll> >a,b;
    for(int i=0;i<n;i++)
    {
        cin>>t.first;
        a.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].second;
    }
    sort(a.begin(),a.end());
    vector<pair<ll,ll> >::iterator it,p,q;
    for(it=a.begin();it<a.end();)
    {
        if((it==a.begin()||it->first!=(it-1)->first)&&(it==a.end()-1||it->first!=(it+1)->first))
            b.push_back(*it),a.erase(it);
        else it++;
    }
    ll ans=0;
    for(p=a.begin();p<a.end();p++)
    {
        ans+=p->second;
    }
    for(p=b.begin();p<b.end();p++)
    {
        for(q=a.begin();q<a.end();q++)
            if((p->first|q->first)==q->first)
                break;
        if(q!=a.end())ans+=p->second;
    }
    cout<<ans<<endl;
    return 0;
}