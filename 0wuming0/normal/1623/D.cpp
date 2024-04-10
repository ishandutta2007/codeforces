#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll pows(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
ll dev(ll n)
{
    return pows(n,mod-2);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,a,b,c,d;
        ll k;
        cin>>n>>m>>a>>b>>c>>d>>k;k=100-k;
        k=k*dev(100)%mod;//cout<<"???"<<k<<endl;
        set<pair<pair<int,int>,pair<int,int>> >st;
        int vx=1,vy=1;
        ll ans=0;
        ll p=1;
        int t=0;
        while(1)
        {//cout<<a<<" "<<b<<endl;
            if(vx==1&&a==n)vx=-1;
            if(vx==-1&&a==1)vx=1;
            if(vy==1&&b==m)vy=-1;
            if(vy==-1&&b==1)vy=1;
            if(st.find(make_pair(make_pair(a,b),make_pair(vx,vy)))!=st.end())
            {
                ans=(ans+p*t%mod)*dev(1-p+mod)%mod;
                break;
            }
            st.insert(make_pair(make_pair(a,b),make_pair(vx,vy)));
            if(a==c||b==d)
            {
                ans+=p*(1-k+mod)%mod*t%mod;
                ans%=mod;//cout<<"<<<"<<a<<" "<<b<<" "<<c<<" "<<d<<"  "<<ans<<" "<<p<<" "<<t<<endl;
                p=p*k%mod;
            }
            t++;
            a+=vx;
            b+=vy;
        }
        cout<<ans<<endl;
    }
    return 0;
}