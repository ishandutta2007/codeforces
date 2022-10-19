 #include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<long double> point;
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
const int N=2e5+100;
ll a[N];
ll Main(){
    ll n,q;
    cin >> n >> q;
    ll t0=0,t1=0;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a[i]=x;
        if (x==1) t1++;
        else t0++;
    }
    while(q--){
        ll t;
        cin >> t;
        if (t==1){
            ll x;
            cin >> x;
            if (a[x]==0){
                a[x]=1;
                t1++;
                t0--;
            }
            else{
                a[x]=0;
                t1--;
                t0++;
            }
        }
        else{
            ll k;
            cin >> k;
            if (k<=t1) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    //cin >> t;
    while(t--) Main();
}