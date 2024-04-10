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
ll a[N];
int Main(){
    ll n;
    cin >> n;
    vector <pair <pii,int> > ans;
    ll s=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        s+=a[i];
    }
    if (s%n!=0) kill(-1);
    s/=n;
    for (int i=2;i<=n;i++){
        if (a[i]%i==0){
            ans.pb({{i,1},a[i]/i});
            a[1]+=a[i];
            a[i]=0;
            continue;
        }
        ll z=a[i]%i;
        z=i-z;
        ans.pb({{1,i},z});
        a[1]-=z;
        a[i]+=z;
        ans.pb({{i,1},a[i]/i});
        a[1]+=a[i];
        a[i]=0;
    }
    for (int i=2;i<=n;i++){
        ans.pb({{1,i},s});
    }
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u.F.F << " " << u.F.S << " " << u.S << endl;
    }
}
int32_t main(){
    ll t;
    cin >> t;
    while(t--) Main();
}