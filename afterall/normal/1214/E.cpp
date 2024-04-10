#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
int32_t Main(){
    ll n;
    cin >> n;
    vector <pii> a;
    vector <pii> yal;
    for (int i=1;i<=n;i++){
        ll d;
        cin >> d;
        d--;
        a.pb({d,i});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    vector <int> ras;
    vector <int> p;
    for (int i=0;i<a.size();i++){
        ras.pb(a[i].S*2-1);
        if (i){
            yal.pb({ras[i-1],ras[i]});
        }
    }
    ll last=0;
    for (int i=0;i<n;i++){
        if (i>=a[i].F){
            ll z=i-a[i].F;
            yal.pb({ras[z],a[i].S*2});
            continue;
        }
        if (p.size()==0){
            ll z=i+a[i].F;
            last=z;
            yal.pb({ras[z],a[i].S*2});
            p.pb(a[i].S*2);
        }
        else{
            ll r=a[i-1].F-a[i].F;
            if (last<i) r+=2;
            if (p.size()<=r){
                p.clear();
                ll z=i+a[i].F;
                last=z;
                yal.pb({ras[z],a[i].S*2});
                p.pb(a[i].S*2);
            }
            else{
                for (int j=1;j<=r;j++) p.pop_back();
                yal.pb({p.back(),a[i].S*2});
                p.pb(a[i].S*2);
            }
        }
    }
    for (auto u : yal){
        cout << u.F << " " << u.S << endl;
    }
}
int32_t main(){
    ll t;
  //  cin >> t;
  t=1;
    while(t--) Main();
}