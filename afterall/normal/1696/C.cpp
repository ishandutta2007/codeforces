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
const int N=2e5+100;
vector <pii> solve(vector <int> a,ll m){
    vector <pii> b;
    for (int i=0;i<a.size();i++){
        ll z=1;
        while((a[i]/z)%m==0){
            z*=m;
        }
        if (b.size()==0 || b.back().S!=a[i]/z) b.pb({z,a[i]/z});
        else{
            b.back().F+=z;
        }
    }
    return b;

}
void Main(){
    ll n,m;
    cin >> n >> m;
    vector <int> a;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    vector <pii> ans=solve(a,m);
    a.clear();
    cin >> n;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    vector <pii> jav=solve(a,m);
    
    if (jav.size()!=ans.size()){
        cout << "NO" << endl;
        return ;
    }
    for (int i=0;i<ans.size();i++){
        if (ans[i]!=jav[i]){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}