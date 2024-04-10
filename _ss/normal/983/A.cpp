#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e18;

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
    ll n,p,q,b;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>p>>q>>b;
        ll t=gcd(p,q);
        q/=t;
        t=gcd(q,b);
        ll q2=q/t;
        while (q>1 && q2!=q)
        {
            q=q2;
            t=gcd(q,t);
            q2=q/t;
        }
        if (q==1) cout<<"Finite"; else cout<<"Infinite";
        cout<<endl;
    }
    return 0;
}