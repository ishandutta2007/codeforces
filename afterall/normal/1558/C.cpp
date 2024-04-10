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
const int N=2040;
ll a[N];
ll b[N];
ll Main(){
    ll n;
    cin >> n;
    ll p1=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]%2!=i%2) p1=1;
    }
    if (p1) kill(-1);
    vector <int> ans;
    for (int i=n;i>1;i-=2){
        ll id=-1;
        for (int j=1;j<=n;j++){
            if (a[j]==i) id=j;
        }
        ans.pb(id);
        reverse(a+1,a+id+1);
        id=-1;
        for (int j=1;j<=n;j++){
            if (a[j]==i-1) id=j;
        }
        id--;
        ans.pb(id);
        reverse(a+1,a+id+1);
        id+=2;
        ans.pb(id);
        reverse(a+1,a+id+1);
        ans.pb(3);
        reverse(a+1,a+3+1);
        ans.pb(i);
        reverse(a+1,a+i+1);
    }
    cout << ans.size() << endl;
    for (auto u : ans) cout << u << " ";
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}