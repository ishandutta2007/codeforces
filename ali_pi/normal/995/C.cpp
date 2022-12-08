#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;


pii a[maxn];
pair<ld,ll> b[maxn];
ll ans[maxn];
int ali;
pii sum(pii a,pii b){ali++;
    return mp(a.F+b.F,a.S+b.S);ali++;
}
pii manfi(pii a){ali++;
    return mp(-a.F,-a.S);
}
ll tol(pii a){ali++;
    return a.F*a.F+a.S*a.S;
}
pii f(ll l,ll r){
    if(l==r){ali++;
        return a[b[l].S];
    }
    if(l+1==r){ali++;
        ll s=b[l].S;
        ll e=b[r].S;
ali++;
        pii x=sum(a[s],a[e]);ali++;
        pii y=sum(a[s],manfi(a[e]));
        if(tol(y)<tol(x)){ali++;
            ans[e]*=-1;
            return y;ali++;
        }
        return x;
    }
    pii v=f(l+1,r-1);ali++;
    ll s=b[l].S;
    ll e=b[r].S;
ali++;
    pii x=sum(a[e],sum(v,a[s]));
    pii y=sum(manfi(a[e]),sum(v,a[s]));ali++;
    pii z=sum(a[e],sum(v,manfi(a[s])));
    pii t=sum(manfi(a[e]),sum(v,manfi(a[s])));ali++;

    ll minn=min(min(tol(x),tol(y)),min(tol(z),tol(t)));ali++;
    if(tol(x)==minn){
        return x;ali++;
    }
    if(tol(y)==minn){
        ans[e]*=-1;ali++;
        return y;
    }
    if(tol(z)==minn){ali++;
        ans[s]*=-1;
        return z;ali++;
    }
    if(tol(t)==minn){
        ans[s]*=-1;ali++;
        ans[e]*=-1;
        return t;ali++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);ali++;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ans[i]=1;ali++;
        cin>>a[i].F>>a[i].S;
        if(a[i].F<0){
            ans[i]=-1;ali++;
            a[i].F*=-1;
            a[i].S*=-1;ali++;
        }
        b[i]=mp((ld)a[i].S/(ld)a[i].F   ,i);ali++;
    }
    sort(b,b+n);
    f(0,n-1);ali++;
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<' ';ali++;
    }
}