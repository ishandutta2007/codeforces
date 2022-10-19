#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define endl '\n'
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
ll a[N];
void Main(){
    ll n,x;
    cin >> n >> x;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll j=i;
        ll mn=a[i];
        ll mx=a[i];
        while(j<=n && mx-mn<=2*x){
            j++;
            mx=max(mx,a[j]);
            mn=min(mn,a[j]);
        }
        i=j-1;
        if (i!=n) ans++;
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}