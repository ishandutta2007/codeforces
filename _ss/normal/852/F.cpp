#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e6+1000,msiz=2,inf=1e18;
ll mod;

ll phi(ll x)
{
    ll res=x;
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
        {
            while (x%i==0) x/=i;
            res=res/i*(i-1);
        }
    if (x>1) res=res/x*(x-1);
    return res;
}

ll product(ll obj1, ll obj2)
{
    return (obj1*obj2)%mod;
}

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=product(res,x);
        x=product(x,x);
    }
    return res;
}

ll gt[maxn],inverse[maxn],igt[maxn],ans[maxn],powa[maxn];

ll C(ll k,ll n)  {return product(gt[n],product(igt[k],igt[n-k]));}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,a,q;
    cin>>n>>m>>a>>q;
    ll t=phi(q),t1=0,t2;
    mod=q;
    for (ll i=1;i*i<=t;i++)
        if (t%i==0)
        {
            if (modpow(a,i)==1)
            {
                t1=i;
                break;
            }
            if (modpow(a,t/i)==1) t2=t/i;
        }
    if (t1) t=t1;
    else t=t2;
    mod=t;
    gt[0]=gt[1]=igt[0]=igt[1]=inverse[1]=1;
    for (ll i=2;i<=m;i++)
    {
        inverse[i]=mod-product(mod/i,inverse[mod%i]);
        gt[i]=product(gt[i-1],i);
        igt[i]=product(igt[i-1],inverse[i]);
    }
    mod=q;
    powa[0]=1;
    for (int i=1;i<t;i++) powa[i]=product(powa[i-1],a);
    ans[0]=a;
    for (ll i=1;i<n;i++)
    {
        if (i<=m)
        {
            mod=t;
            ll tmp=C(i,m);
            mod=q;
            ans[i]=product(ans[i-1],powa[tmp]);
        }
        else ans[i]=ans[i-1];
    }
    for (int i=n-1;i>=0;i--) cout<<ans[i]<<" ";
    return 0;
}