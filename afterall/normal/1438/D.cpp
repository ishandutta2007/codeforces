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
ll a[N];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    if (n==3){
        cout << "YES" << endl << 1 << endl << 1 << " " << 2 << " " << 3 << endl;
        return 0;
    }
        vector <pair <int,pii> > ans;
    if (n%2==0){
        for (int i=2;i<=n-2;i+=2){
            ans.pb({i,{i+1,i+2}});
            ans.pb({1,{i,i+1}});
            ll z=a[i] ^ a[i+1];
            z ^=a[i+2];
            a[i+2]=z;
            a[i]=a[1];
            a[i+1]=a[1];
        }
        for (int i=2;i<=n;i++){
            if (a[i]!=a[1]) kill("NO");
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto u : ans){
            cout << u.F << " " << u.S.F << " " << u.S.S << endl;
        }
        return 0;
    }
    if (n%2==1){
        cout << "YES" << endl;
        for (int i=2;i<=n-1;i+=2){
            ans.pb({1,{i,i+1}});
            ll z=a[i] ^ a[i+1];
            z ^= a[1];
            a[1]=z;
            a[i]=z;
            a[i+1]=z;
        }
        for (int i=2;i<=n-1;i+=2){
            ans.pb({1,{i,i+1}});
            ll z=a[i] ^ a[i+1];
            z ^= a[1];
            a[1]=z;
            a[i]=z;
            a[i+1]=z;
        }
        for (int i=2;i<=n;i++){
            if (a[i]!=a[1]) cout << 1/0;
        }
        cout << ans.size() << endl;
        for (auto u : ans){
            cout << u.F << " " << u.S.F << " " << u.S.S << endl;
        }
        return 0;
    }
}
int32_t main(){
    ll t;
    t=1;
   // cin >> t;
    while(t--) Main();
}