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
map <int,int> mp;
vector <int> ans;
vector <pii> add;
vector <int> solve(vector <int> a){
    ll id=-1;
    for (int i=0;i<a.size();i++){
        if (a[i]==a.back()){
            id=i;
            break;
        }
    }
    ll z=id;
    for (int i=a.size()-2;i>id;i--){
        add.pb({a[i],z});
        z++;
    }
    ans.pb(a.size()-id-1);
    a.pop_back();
    vector <int> b;
    for (int i=0;i<id;i++){
        b.pb(a[i]);
    }
    vector <int> c;
    for (int i=id+1;i<a.size();i++){
        c.pb(a[i]);
    }
    reverse(c.begin(),c.end());
    for (auto u : c) b.pb(u);
    return b;
}
void Main(){
    mp.clear();
    ans.clear();
    add.clear();
    ll n;
    cin >> n;
    vector <int> a;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
        mp[x]++;
    }
    for (auto U : mp) {
        if (U.S%2==1) {
            cout << -1 << endl;
            return ;
        }
    }
    while(a.size()){
        a=solve(a);
    }
    reverse(ans.begin(),ans.end());
    cout << add.size() << endl;
    for (auto u : add){
        cout << u.S << " " << u.F << endl;
    }
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u*2 << " ";
    }
    cout << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}