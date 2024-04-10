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
    set <int> s[2];
    set <int> d[2];
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a[i]=x%2;
        s[a[i]].insert(i);
    }
    d[1]=s[1];
    d[0]=s[0];
    ll ans=0;
    if (s[0].size()>s[1].size()+1 || s[1].size()>s[0].size()+1) kill(-1);
    if (s[0].size()>=s[1].size()){
        for (int i=1;i<=n;i++){
            ll z=*s[(i-1)%2].begin();
            ll p=*s[i%2].begin();
            if (z==i) {
                s[(i-1)%2].erase(z);
                continue;
            }
            ans+=z-p;
            s[(i-1)%2].erase(z);
            s[i%2].erase(p);
            s[i%2].insert(z);
        }
    }
    else ans=(ll)1e12;
    ll jav=0;
    s[0]=d[0];
    s[1]=d[1];
    if (s[1].size()>=s[0].size()){
        for (int i=1;i<=n;i++){
            ll z=*s[(i)%2].begin();
            ll p=*s[(i-1)%2].begin();
            if (z==i) {
                s[(i)%2].erase(z);
                continue;
            }
            jav+=z-p;
            s[(i)%2].erase(z);
            s[(i-1)%2].erase(p);
            s[(i-1)%2].insert(z);
        }
    }
    else jav=(ll)1e12;
    if (min(ans,jav)==(ll)1e12) kill(-1);
  //  cout << " ans " << ans << " " << jav << " " ;
    kill(min(ans,jav));
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}