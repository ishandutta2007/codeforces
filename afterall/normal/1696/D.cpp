#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=3e5+100;
ll dp[N];
ll s[N];
ll b[N];
ll a[N];
pii segmi[N*4];
pii segma[N*4];
void build(ll nod,ll l,ll r){
    if (r-l==1){
        segmi[nod]={a[l],l};
        segma[nod]={a[l],l};
        return ;
    }
    ll mid=(r+l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid,r);
    segmi[nod].F=min(segmi[nod*2].F,segmi[nod*2+1].F);
    if (segmi[nod].F==segmi[nod*2].F) segmi[nod]=segmi[nod*2];
    else segmi[nod]=segmi[nod*2+1];

    segma[nod].F=max(segma[nod*2].F,segma[nod*2+1].F);
    if (segma[nod].F==segma[nod*2].F) segma[nod]=segma[nod*2];
    else segma[nod]=segma[nod*2+1];
}
pii getmi(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return {1000000000,N};
    if (l>=L && r<=R) return segmi[nod];
    ll mid=(r+l)/2;
    pii x=getmi(nod*2,l,mid,L,R);
    pii y=getmi(nod*2+1,mid,r,L,R);
    if (x.F<y.F) return x;
    return y;
}

pii getma(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return {0,N};
    if (l>=L && r<=R) return segma[nod];
    ll mid=(r+l)/2;
    pii x=getma(nod*2,l,mid,L,R);
    pii y=getma(nod*2+1,mid,r,L,R);
    if (x.F>y.F) return x;
    return y;
}
void Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n+1);
    vector <pii> agh;
    agh.pb({0,N});
    for (int i=1;i<=n;i++){
        while(agh.back().S<a[i]){
            agh.pop_back();
        }
        b[i]=agh.back().F;
        agh.pb({i,a[i]});
    }
    agh.clear();
    agh.pb({0,0});
    for (int i=1;i<=n;i++){
        while(agh.back().S>a[i]){
            agh.pop_back();
        }
        s[i]=agh.back().F;
        agh.pb({i,a[i]});
    }
    for (int i=2;i<=n;i++){
        ll z=getmi(1,1,n+1,b[i]+1,i+1).S;
        if (z==i) z=i-1;
        ll t=getma(1,1,n+1,s[i]+1,i+1).S;
        if (t==i) t--;
        dp[i]=min(dp[z],dp[t])+1;
      //  cout << i << " " << z << " " << t << " " << dp[i] << endl;
    }
    cout << dp[n] << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}