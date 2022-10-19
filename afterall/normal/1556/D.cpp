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
ll askor(ll x,ll y){
    cout << "or " << x << " " << y << endl;
    ll t;
    cin >> t;
    return t;
}
ll askand(ll x,ll y){
    cout << "and " << x << " " << y << endl;
    ll t;
    cin >> t;
    return t;
}
int Main(){
    ll n,k;
    cin >> n >> k;
    ll o12=askor(1,2);
    ll o13=askor(1,3);
    ll o23=askor(2,3);
    ll and12=askand(1,2);
    ll and13=askand(1,3);
    ll and23=askand(2,3);
    a[1]=o12-(o23 & o12);
    a[1] |= and12;
    a[1] |= and13;
    a[2]=o12-(o13 & o12);
    a[2] |=and12;
    a[2] |=and23;
    a[3]=o23 -(o12 & o23);
    a[3] |= and23;
    a[3] |= and13;
    for (int i=4;i<=n;i++){
        a[i]=askor(1,i);
        a[i]-=a[1];
        a[i] |= askand(1,i);
    }
    sort(a+1,a+n+1);
    cout << "finish" << " " << a[k] << endl;

    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--) Main();
}