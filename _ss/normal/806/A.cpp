#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

ll gcd(ll a,ll b)
{
    while (b)
    {
        ll r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x,y,p,q,t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>x>>y>>p>>q;
        ll tmp=gcd(p,q);
        p/=tmp;
        q/=tmp;
        if ((p==q && x!=y) || (p==0 && x!=0)) cout<<-1<<"\n";
        else
        {
            ll l=1,r=2e9,mid,ans=2e9;
            while (l<=r)
            {
                mid=(l+r)/2;
                if (mid*p>=x && mid*q>=y && mid*q-y>=mid*p-x) ans=mid*q-y,r=mid-1;
                else l=mid+1;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}