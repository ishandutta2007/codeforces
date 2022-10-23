#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int index(ll x,ll h)
{
    while (h)
    {
        x/=10;
        h--;
    }
    return x%10;
}

int fib(ll x)
{
    ll sl=9,siz=1,bl=0;
    while (x)
    {
        if (sl*siz<x) x-=sl*siz;
        else break;
        bl+=sl;
        sl*=10;
        siz++;
    }
    return index((x-1)/siz+1+bl,siz-((x-1)%siz+1));
}

int solve(ll x)
{
    ll sl=9,bo=0,siz=1,bl=0;
    while (x)
    {
        if (siz*sl*(sl+1)/2+sl*bo<x) x-=siz*sl*(sl+1)/2+sl*bo;
        else
        {
            ll l=0,r=sl-1,mid,ans;
            while (l<=r)
            {
                mid=(l+r)/2;
                if (siz*mid*(mid+1)/2+mid*bo<x) l=mid+1,ans=mid;
                else r=mid-1;
            }
            x-=siz*ans*(ans+1)/2+ans*bo;
            break;
        }
        bo+=sl*siz;
        bl+=sl;
        sl*=10;
        siz++;
    }
    return fib(x);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll q,k;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>k;
        cout<<solve(k)<<endl;
    }
    return 0;
}