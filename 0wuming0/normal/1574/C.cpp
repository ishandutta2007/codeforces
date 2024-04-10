#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[200005];
int main()
{
    ll s=0;
    int n;
    cin>>n;
    multiset<ll>st;
    for(int i=0;i<n;i++)
    {
        ll k;
        scanf("%lld",&k);
        st.insert(k);
        s+=k;
    }
    int m;
    cin>>m;
    while(m--)
    {
        ll x,y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        swap(x,y);
        auto it=st.upper_bound(y);
        ll ans=2e18;
        if(st.end()!=it)
        {
            ans=min(max(y-*it,0ll)+max(x-(s-*it),0ll),ans);
        }
        it--;
        {
            ans=min(max(y-*it,0ll)+max(x-(s-*it),0ll),ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}