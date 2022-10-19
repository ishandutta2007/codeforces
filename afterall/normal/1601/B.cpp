#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e5+100;
ll nxt[N];
ll a[N];
ll b[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        cin >> b[i];
    }
    vector <int> ans;
   // ans.pb(n);
    ll now=n;
    ll mx=n;
    while(now!=0){
        if (now-a[now]==0){
          //  cout << now << " juerf " << endl;
            ans.pb(0);
            break;
        }
        if (now-a[now]>=mx) kill(-1);
        ll mn=N;
        ll id=0;
      //      cout << mx << " " << now-a[now] << " erjf " << endl;
        for (int i=mx-1;i>=now-a[now];i--){
            ll z=i+b[i];
          //  cout << z << " ejrfn " << endl;
            z-=a[z];
            if (z<mn){
                mn=z;
                id=i;
            }
        }
       // cout << id << endl;
        ans.pb(id);
        mx=now-a[now];
        now=id+b[id];
    }
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u << " ";
    }
    cout << endl;
}