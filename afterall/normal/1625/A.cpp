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
ll cnt[N];
void Main(){
    ll n,l;
    cin >> n >> l;
    memset(cnt,0,sizeof cnt);
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        for (int j=0;j<l;j++){
            if ((x & (1<<j))) cnt[j]++;
        }
    }
    ll ans=0;
    for (int i=0;i<l;i++){
        if (cnt[i]*2>n) ans |= (1<<i);
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}