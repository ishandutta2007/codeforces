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
void Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[n+1]=0;
    ll ans=0;
    for (int i=2;i<n;i++){
        if (a[i]>a[i-1] && a[i]>a[i+1]){
            a[i+1]=max(a[i],a[i+2]);
            ans++;
        }
    }
    cout << ans << endl;
    for (int i=1;i<=n;i++) cout << a[i] << " ";
    cout << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}