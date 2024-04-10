#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)
#define FNI (-1e9)
ll n,a[N];

set <pair<ll,ll> > s[3];
vector <ll> ans;


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],s[a[i]%3].insert({a[i],i+1});
    
    if(s[0].begin()->first!=0)
        return cout<<"Impossible",0;
    ans.push_back(s[0].begin()->second);      
    s[0].erase(s[0].begin());
    ll last=0;
    for(int i=1;i<n;i++)
    {
        set <pair<ll,ll> >::iterator it=s[i%3].lower_bound({last,FNI});
        if(it!=s[i%3].end() && it->first==last+1)
            ans.push_back(it->second),last++,s[i%3].erase(it);
        else if(it!=s[i%3].begin())
        {
            it--;
            last=it->first;
            ans.push_back(it->second);
            s[i%3].erase(it);
            
        }
        else return cout<<"Impossible",0;
            
    }  
    cout<<"Possible\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}