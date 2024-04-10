#include"bits/stdc++.h"
using namespace std;
#define ll long long
vector<ll>v;
ll a[20000],b[20000],nn;
int main()
{
    //for(int i=0;i<40;i++)v.push_back(1ll<<i);
    for(ll i=3,now=2;now<=1e12+8;i++)
    {
        now=now*i;
        v.push_back(now);
        //cout<<now<<endl;
    }
    for(int i=0;i<(1<<12);i++)
    {
        for(int j=0;j<12;j++)if((1<<j)&i)
        {
            b[i]++;
            a[i]+=v[j];
        }
        //cout<<"<<"<<a[i]<<" "<<b[i]<<endl;
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int ans=1e9;
        for(int i=0;i<(1<<12);i++)
        {
            int now=b[i];
            ll nn=n-a[i];
            if(nn<0)continue;
            for(int j=0;j<40;j++)if((1ll<<j)&nn)now++;
            ans=min(ans,now);
        }
        cout<<ans<<endl;
    }
    return 0;
}