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
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=1e5+100;
set <int> s,t;
ll a[N];
void del(ll x){
    s.erase(x);
    t.erase(x);
    if (s.size()<t.size()){
        cout << "KIR" << endl;
        exit(0);
    }
    if (t.size()){
        auto u=t.lower_bound(x);
        auto v=s.lower_bound(x);
        if (u==t.end()) u=t.begin();
        if (v==s.end()) v=s.begin();
        if (*u==*v){
            t.erase(*u);
        }
    }
    if (s.size()){
        if (s.size()==1){
            ll u=*s.begin();
            if (a[u]==1){
                t.insert(u);
            }
            return ;
        }
        auto u=s.lower_bound(x);
        if (u==s.end()) u=s.begin();
        auto v=u;
        if (v==s.begin()){
            v=s.end();
        }
        v--;
        if (__gcd(a[*u],a[*v])==1) t.insert(*u);
    }
}
ll Main(){
    ll n;
    cin >> n;
    s.clear();
    t.clear();
    for (int i=1;i<=n;i++){
        cin >> a[i];
        s.insert(i);
    }
    if (n==1){
        if (a[1]!=1) kill(0);
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    a[0]=a[n];
    for (int i=1;i<=n;i++){
        if (__gcd(a[i],a[i-1])==1) t.insert(i);
    }
    ll ja=2;
    vector <int> ans;
    while(t.size()){
        auto u=t.lower_bound(ja);
        if (u==t.end()) {
            ja=0;
            u=t.lower_bound(ja);
        }
        ans.pb(*u);
        ja=*u;
        del(*u);
        if (s.size()==0) break;
        u=s.lower_bound(ja);
        if (u==s.end()) u=s.begin();
        ja=*u;
        u=s.upper_bound(ja);
        if (u==s.end()) u=s.begin();
        ja=*u;
    }
    cout << ans.size() << " " ;
    for (auto u : ans) cout << u << " ";
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll tt;
    cin >> tt;
    while(tt--) Main();
}