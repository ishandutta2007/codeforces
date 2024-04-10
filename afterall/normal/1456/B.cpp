#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
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
    ll ans=1e9;
    for (int i=1;i<n;i++){
        ll x=0;
        for (int j=i;j>max(0,i-70);j--){
            x ^= a[j];
            ll y=0;
            for (int k=i+1;k<=min(n,i+70);k++){
                y ^= a[k];
                if (x>y){
                    ans=min(ans,i-j+(k-i-1));
                }
            }
        }
    }
    if (ans==1e9) kill(-1);
    kill(ans);
}
int32_t main(){
    sync;
    ll t;
    t=1;
    //cin >> t;
    while(t--){
        Main();
    }
}