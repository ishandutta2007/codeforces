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
const int N=100;
vector <vector <int> > ans;
ll ja[N];
ll solve(vector <int> a){
    ll p1=0;
    for (int i=0;i<a.size();i++){
        ja[a[i]]=i+1;
    }
    for (int i=1;i<a.size();i++){

        if (a[i]<a[i-1]){
            p1=1;
            break;
        }
    }
    if (p1==0) return 0;
    for (int i=1;i<a.size();i++){
        if (ja[i]>ja[i+1]){
            p1=i;
            break;
        }
    }
    ll id=ja[p1+1];
    ll kd=id-1;
    ll zz=id;
    for (int i=zz;i<a.size();i++){
        if (a[i]-a[i-1]==1) id++;
        else break;
    }
    ll zd=ja[p1]-1;
    vector <vector <int> > w;
    if (kd!=0){
        vector <int> f;
        for (int i=0;i<kd;i++){
            f.pb(a[i]);
        }
        w.pb(f);
    }
    vector <int> f;
    for (int i=kd;i<id;i++){
        f.pb(a[i]);
    }
    w.pb(f);
    f.clear();
    for (int i=id;i<=zd;i++){
        f.pb(a[i]);
    }
    w.pb(f);
    if (zd+1!=a.size()){
        f.clear();
        for (int i=zd+1;i<a.size();i++) f.pb(a[i]);
        w.pb(f);
    }
    f.clear();
    for (auto u : w) f.pb(u.size());
    ans.pb(f);
    a.clear();
    reverse(w.begin(),w.end());
    for (auto u : w){
        for (auto v : u) a.pb(v);
    }
    for (auto u : a){
   //     cout << u << " ";
    }
    //cout << endl;
    solve(a);
}
int Main(){
    ll n;
    cin >> n;
    vector <int> a;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    solve(a);
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u.size() << " ";
        for (auto v : u){
            cout << v << " ";
        }
        cout << endl;
    }

}
int32_t main(){
    sync;
    ll t;
    t=1;
    while(t--){
        Main();
    }
}