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
const int N=100;
ll a[N];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans;
    ans=n-1;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            ll sor=a[i]-a[j];
            ll makh=(i-j);

            ll cnt=0;
            for (int k=1;k<=n;k++){
                ll z=sor*(k-i);
                if (z%makh!=0) continue;
              //  if (i==1 && j==2) cout << z << " " << sor << " k " << a[i] << " " << z/makh << endl;
                if (a[i]+z/makh==a[k]) cnt++;
            }
            ans=min(ans,n-cnt);
        }
    }
    kill(ans);
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}