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
const int N=1e3+100;
vector <pii> ans;
ll kir(ll a1,ll a2,ll a3,ll a4){
    ans.pb({a1,a3});
    ans.pb({a2,a4});
    ans.pb({a1,a4});
    ans.pb({a2,a3});
}
ll to_kos(ll a1,ll a2,ll a3,ll b1,ll b2){
    ans.pb({a1,b1});
    ans.pb({a3,b2});
    ans.pb({a1,b2});
    ans.pb({a3,b1});
    ans.pb({a2,b1});
    ans.pb({b1,b2});
    ans.pb({a2,b2});
}
ll tarah(ll a1,ll a2,ll a3){
    ans.pb({a2,a3});
    ans.pb({a1,a3});
    ans.pb({a1,a2});
}
int32_t main(){
    ll n;
    cin >> n;
    if (n%4==3 || n%4==2) kill("NO");
    cout << "YES" << endl;
    if (n==1) return 0;
    if (n%4==0){
        for (int i=1;i<=n;i+=2){
            for (int j=i+2;j<=n;j+=2){
                kir(i,i+1,j,j+1);
            }
        }
        for (int i=1;i<=n;i+=2){
            ans.pb({i,i+1});
        }
    }
    else{
        for (int i=4;i<=n;i+=2){
            for (int j=i+2;j<=n;j+=2){
                kir(i,i+1,j,j+1);
            }
        }
        for (int i=4;i<=n;i+=2){
            to_kos(1,2,3,i,i+1);
        }
        tarah(1,2,3);
    }
    for (auto u : ans){
        cout << u.F << " " << u.S << endl;
    }
}