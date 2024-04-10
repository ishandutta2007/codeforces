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
const int N=1e6+100;
ll mod=998244353;
ll a[N];
void Main(){

    ll n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    ll ans=1;
    
    for (int i=n-k+1;i<=n;i++){
        if (a[i]!=-1 && a[i]!=0){
            cout << 0 << endl;
            return ;
        }
    }
    for (int i=2;i<=k;i++){
        ans*=i;
        ans%=mod;
    }
    for (int i=1;i<=n-k;i++){
        if (a[i]==0){
            ans*=(k+1);
            ans%=mod;
        }
        if (a[i]==-1){
            ans*=i+k;
            ans%=mod;
        }
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}