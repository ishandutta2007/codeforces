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
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll a[N];
ll par[N];
ll fen[N];
void add(ll idx,ll val){
    for (;idx<N;idx+=idx & (-idx)){
        fen[idx]+=val;
    }
}
ll get(ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)) s+=fen[idx];
    return s;
}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    ll mx=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        par[i]=par[i-1]+a[i];
        mx=max(mx,par[i]);
        if (i==n && mx>par[n]){
            cout << -1 << endl;
            return 0;
        }
    }
    vector <pii> b;
    for (int i=1;i<=n;i++) {
        b.pb({par[i],i});
        if (par[i]<0){
            cout << -1 << endl;
            return 0;
        }
    }
    sort(b.begin(),b.end());
    ll ans=0;

    for (int i=0;i<n;i++){
        //cout << b[i].S << endl;
        ans+=get(N-1)-get(b[i].S);
        add(b[i].S,1);
    }
    cout << ans << endl;
}