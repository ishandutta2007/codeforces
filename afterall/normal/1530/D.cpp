#include <bits/stdc++.h>
/// 500 485 462 A4
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
const int N=2e5+100;
ll a[N];
ll b[N];
vector <int> in[N];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) in[i].clear();
    for (int i=1;i<=n;i++){
        cin >> a[i];
        b[i]=a[i];
        in[a[i]].pb(i);
    }
    vector <int> bad;
    for (int i=1;i<=n;i++){
        if (in[i].size()==0) bad.pb(i);
    }
    ll ans=n;
    for (int i=1;i<=n;i++){
        if (in[i].size()>1){
            for (int j=0;j<in[i].size()-1;j++){
                ans--;
                ll x=in[i][j];
                ll y=bad.back();
                a[x]=y;
                bad.pop_back();
            }
        }
    }

    vector <int> y;
    for (int i=1;i<=n;i++) if (a[i]==i) y.pb(i);
    while(y.size()>1){
        ll x=y.back();
        y.pop_back();
        ll z=y.back();
        y.pop_back();
        swap(a[x],a[z]);
    }
    if (y.size()){
        ll dd=y[0];
        a[dd]=b[dd];
        for (int i=1;i<=n;i++){
            if (i!=dd && a[i]==a[dd]){
                a[i]=dd;
            }
        }
    }

    cout << ans << endl;
    for (int i=1;i<=n;i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}