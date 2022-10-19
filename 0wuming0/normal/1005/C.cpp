#include"bits/stdc++.h"
using namespace std;
#define ll long long
struct _
{
    int b;
    int k;
}num[120005];
int nn;
void add(int t)
{
    num[nn].b=t;
    num[nn].k=1;
    nn++;
}
ll _2[120];
ll a[120005];
int vis[120005];
map<ll,int>mp;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",a+i);
    }
    sort(a,a+n);
    add(a[0]);
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])num[nn-1].k++;
        else add(a[i]);
    }
    _2[0]=1;
    for(int i=1;i<40;i++)
    {
        _2[i]=_2[i-1]*2;
    }
    for(int i=0;i<nn;i++)
    {
        mp[num[i].b]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<40;j++)
        {
            map<ll,int>::iterator it=mp.find(_2[j]-a[i]);
            if(it!=mp.end())
            {
                if(num[it->second].k>=2||num[it->second].b!=a[i])vis[it->second]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<nn;i++)
    {
        if(vis[i])ans+=num[i].k;
    }
    cout<<n-ans<<endl;
    return 0;
}