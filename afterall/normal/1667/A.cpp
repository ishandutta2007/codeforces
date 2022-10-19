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
#define kill(x) cout << x << endl;return;
using namespace std;

const int N=2e5+100;

void Main(){
    ll n;
    cin >> n ;

    vector <int> a;
    ll ans=(ll)1e18;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    if (n==1){
        cout << 0 << endl;
        return ;
    }
    for (int i=0;i<n;i++){
        int cnt=0;
        int jav=0;
        for (int j=i-1;j>-1;j--){
            ll z=-cnt/a[j];
            z++;
            cnt=-z*a[j];
            jav+=z;
        }
        cnt=0;
        for (int j=i+1;j<n;j++){
            ll z=cnt/a[j];
            z++;
            cnt=z*a[j];
            jav+=z;
        }
        ans=min(ans,jav);
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    //cin >> t;
    while(t--) Main();
}