#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int a[N],x[N];

int m;
int b[N],y[N];

map<int,int> mp;
int main()
{
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i]>>x[i];
        if(mp.find(a[i])==mp.end())
        {
            ans+=x[i];
            mp[a[i]]=x[i];
        }
        else
        {
            ans-=mp[a[i]];
            mp[a[i]]=max(mp[a[i]],x[i]);
            ans+=mp[a[i]];
        }
    }
    cin>>m;
    for(int i=0;i<m;++i)
    {
        cin>>a[i]>>x[i];
        if(mp.find(a[i])==mp.end())
        {
            ans+=x[i];
            mp[a[i]]=x[i];
        }
        else
        {
            ans-=mp[a[i]];
            mp[a[i]]=max(mp[a[i]],x[i]);
            ans+=mp[a[i]];
        }
    }
    cout<<ans<<endl;
    return 0;
}