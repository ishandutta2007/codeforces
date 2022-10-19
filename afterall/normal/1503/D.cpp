/// Black lives matter
#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100;
ll mx[N];
ll mn[N];
ll f[N];
vector <int> a,b;
vector <pii> baz;
set <pii> s,t;
void del(ll x){
    s.erase({-mx[x],x});
    t.erase({mn[x],x});
}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> mx[i] >> mn[i];
        if (mx[i]<mn[i]){
            f[i]=1;
            swap(mx[i],mn[i]);
        }
    }
    for (int i=1;i<=n;i++){
        s.insert({-mx[i],i});
        t.insert({mn[i],i});
    }
    while(a.size()+b.size()!=n){
        pii p=*s.begin();
        baz.pb({a.size()+1,n-b.size()});
        del(p.S);
        a.pb(p.S);
      //  cout << " a1 " << p.S << endl;
        while(t.size()){
            ll p1=0;
            pii u=*t.begin();
            if (mn[a.back()]>mn[u.S]){
                del(u.S);
                p1=1;
                b.pb(u.S);
            //    cout << " B " << u.S << endl;
            }
            if (s.size()==0 || b.size()==0) break;
            u=*s.begin();
            if (mx[u.S]>mx[b.back()]){
                p1=1;
                del(u.S);
                a.pb(u.S);
            //    cout << " A " << u.S << endl;
            }
            if (p1==0) break;
        }
    }
    vector <int> c;
    /// check -1
    for (int i=1;i<a.size();i++){
        if (mx[a[i]]>mx[a[i-1]]) kill(-1);
        if (mn[a[i]]<mn[a[i-1]]) kill(-1);
    }
    for (int i=1;i<b.size();i++){
        if (mx[b[i]]>mx[b[i-1]]) kill(-1);
        if (mn[b[i]]<mn[b[i-1]]) kill(-1);
    }
    if (a.size() && b.size()){
        if (mx[a.back()]<mn[b.back()]) kill(-1);
        if (mn[a.back()]>mx[b.back()]) kill(-1);
    }
    c.pb(0);
    for (auto u : a){
        if (f[u]==0) c.pb(1);
        else c.pb(0);
    }
    reverse(b.begin(),b.end());
    for (auto u : b){
        if (f[u]) c.pb(1);
        else c.pb(0);
    }
    ll ans=0;
    reverse(baz.begin(),baz.end());
    ll t1=0,t0=0;
    for (int i=baz[0].F;i<=baz[0].S;i++){
        if (c[i]) t1++;
        else t0++;
    }
    ans+=max(t0,t1);
    for (int i=1;i<baz.size();i++){
        ll l=baz[i].F,r=baz[i].S,L=baz[i-1].F,R=baz[i-1].S;
        ll t0=0,t1=0;
        for (int j=l;j<L;j++){
            if (c[j]==1) t1++;
            else t0++;
        }
        for (int j=R+1;j<=r;j++){
            if (c[j]==1) t1++;
            else t0++;
        }
        ans+=max(t0,t1);
    }
    kill(n-ans);
}