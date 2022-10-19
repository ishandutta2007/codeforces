#include <bits/stdc++.h>
/// this time?
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
const int N=2e3+100;
ll dis[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    cout << '?' << " " << 1 << endl;
    vector <pii> ans;
    ll p1=0,p2=0;
    for (int i=1;i<=n;i++){
        cin >> dis[i];
        if (dis[i]==1){
            ans.pb({1,i});
        }
        if (dis[i]%2==1) p1++;
        else p2++;
    }
    bool b=0;
    if (p1<p2){
        ans.clear();
        b=1;
    }
    for (int i=2;i<=n;i++){
        if (dis[i]%2==b){
            cout << '?' << " " << i << endl;
            for (int j=1;j<=n;j++){
                ll x;
                cin >> x;
                if (x==1){
                    ans.pb({i,j});
                }
            }
        }
    }
    cout << '!' << endl;
    for (auto u : ans){
        cout << u.F << " " << u.S << endl;
    }
    return 0;
}