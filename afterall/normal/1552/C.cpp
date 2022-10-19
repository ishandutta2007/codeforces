#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
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
using namespace std;
const int N=210;
ll vis[N];
int Main(){
    ll n,k;
    cin >> n >> k;
    n*=2;
    memset(vis,0,sizeof vis);
    vector <pii> a;
    for (int i=1;i<=k;i++){
        ll x,y;
        cin >> x >> y;
        if (x>y) swap(x,y);
        a.pb({x,y});
        vis[x]=1;
        vis[y]=1;
    }
    ll ans=0;
    for (int i=0;i<k;i++){
        ll p1=0;
        for (int j=a[i].F+1;j<=a[i].S;j++){
            if (vis[j]==0) p1++;
        }
        ll p2=0;
        for (int j=a[i].S;j<=n+a[i].F;j++){
            ll x=j;
            if (x>n) x-=n;
            if (vis[x]==0) p2++;
        }
        ans+=min(p1,p2);
        for (int j=0;j<k;j++){
            if (i==j) continue;
            if (a[i].F>a[j].F && a[i].S>a[j].S && a[i].F<a[j].S) ans++;
        }
    }
    ll d=n-2*k;
    d/=2;
    ans+=d*(d-1)/2;
    kill(ans);
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}