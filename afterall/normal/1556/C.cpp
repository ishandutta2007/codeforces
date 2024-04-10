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
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans=0;
    for (int i=1;i<=n;i+=2){
        ll val=a[i];
        ll mn=a[i];
        for (int j=i+1;j<=n;j++){
            if (j%2==1){
                val+=a[j];
                continue;
            }
            if (val-a[j]>=0){
                ll z=a[i]-(val-a[j]);
                if (z>0) ans+=min(max((ll)0,mn-(val-a[j])+1),min(z,a[j]));
            }
            else{
                ll z=a[j]+(val-a[j]);
                if (z>0) ans+=min(mn+1,min(a[i],z));
            }
            val-=a[j];
            mn=min(mn,val);
            if (val<0) break;
           // cout << i << " " << j << " " << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--) Main();
}