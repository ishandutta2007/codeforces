#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double

ll n,m,ans[N];
map <ll,vector <ll> > mp;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        mp[a].push_back(i+1);
    }
    bool am=0,im=0;
    for(int i=0;i<m;i++)
    {
        ll a;
        cin>>a;
        if(mp[a].size()>1)
            am=1;
        else if(mp[a].size()==0)
            im=1;
        else
            ans[i]=mp[a][0];        
    }
    if(im)
        return cout<<"Impossible",0;
    if(am)
        return cout<<"Ambiguity",0;
    cout<<"Possible\n";
    for(int i=0;i<m;i++)cout<<ans[i]<<" ";
    return 0;
}