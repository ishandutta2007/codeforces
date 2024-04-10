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
const int N=5e3+10;
ll mod=998244353;
ll a[N];
ll cnt[N];
void Main(){
    ll n;
    cin >> n;
    ll ans=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=2;i<n;i++){
        memset(cnt,0,sizeof cnt);
        for (int j=i+1;j<=n;j++){
            cnt[a[j]]++;
        }
        for (int j=1;j<=n;j++){
            cnt[j]+=cnt[j-1];
        }
        ll t=0;
        for (int j=i-1;j;j--){
            if (a[j]<a[i]){
                ans+=t;
            }
            t+=cnt[a[j]-1];
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