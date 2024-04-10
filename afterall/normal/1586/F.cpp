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
const int N=1e3+10,M=20;
ll rang[N][N];
int32_t main(){
    sync;
    ll n,k;
    cin >> n >> k;
    ll ans=0;
    ll z=1;
    while(z<n){
        z*=k;
        ans++;
    }
   // cout << ans << endl;
    ll mx=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            ll a=i-1;
            ll b=j-1;
            ll cnt=1;
            for (int l=1;l<=ans;l++){
                if (a%k!=b%k) cnt=l;
                a/=k;
                b/=k;
            }
            rang[i][j]=cnt;
            mx=max(mx,cnt);
        }
    }
    cout << mx << endl;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            cout << rang[i][j] << " ";
        }
    }


}