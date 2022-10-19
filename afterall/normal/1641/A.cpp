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
void Main(){
    ll n;
    cin >> n;
    ll e;
    cin >> e;
    vector <int> a;
    multiset <int> s;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
        s.insert(x);
    }
    ll ans=0;
    while(s.size()){
        ll z=*s.begin();
        s.erase(s.begin());
        z*=e;
        auto u = s.lower_bound(z);
        if (u==s.end() || *u!=z){
            ans++;
        }
        else s.erase(u);
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}