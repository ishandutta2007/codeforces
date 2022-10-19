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
const int N=1e3+10,M=13;
ll b[N];
ll ans[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    vector <int> a;
    for (int i=1;i<(1<<M);i++){
        ll z=__builtin_popcount(i);
        if (z==6){
            a.pb(i);
        }
    }
    for (int i=1;i<=n;i++){
        b[i]=a[i];
    }
    for (int i=0;i<M;i++){
        vector <int> t;
        for (int j=1;j<=n;j++){
            if ((a[j] & (1<<i))){
                t.pb(j);
            }
        }
        if (t.size()==0) continue;
        cout << "? " << t.size() << " ";
        for (auto u : t) cout << u << " ";
        cout << endl;
        cout.flush();
        cin >> ans[i];
    }
    cout << "! " ;
    for (int i=1;i<=n;i++){
        ll an=0;
        for (int j=0;j<M;j++){
            if ((a[i] & (1<<j))) continue;
            an |= ans[j];
        }
        cout << an << " ";
    }
    cout << endl;
    cout.flush();

}