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
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
ll a[N];
void Main(){
    ll n;
    cin >> n;
    set <int> s;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (i!=n && a[i]>0) s.insert(i);
    }
    s.insert(n);
    ll ans=0;
    for (int i=1;i<n;i++){
        if (a[i]==0){
            ll x=*s.begin();
            if (x>i) continue;
            s.erase(x);
            a[i]++;
            s.insert(i);
            a[x]--;
            if (a[x]>0) s.insert(x);
            ans++;
        }
    }
    for (int i=1;i<n;i++) ans+=a[i];
        cout << ans << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while (t--) Main();
}