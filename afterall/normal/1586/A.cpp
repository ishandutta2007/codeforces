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
ll a[N];
int Main(){
    ll n;
    cin >> n ;
    ll s=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        s+=a[i];
    }
    for (int i=2;i<s;i++){
        if (s%i==0){
            cout << n << endl;
            for (int j=1;j<=n;j++){
                cout << j << " ";
            }
            cout << endl;
            return 0;
        }
    }
    ll f=0;
    for (int i=1;i<=n;i++){
        if (a[i]%2==1) f=i;
    }
    if (f==0) cout << 1/0;
    cout << n-1 << endl;
    for (int i=1;i<=n;i++){
        if (i!=f) cout << i << " ";
    }
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}