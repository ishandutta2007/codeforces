#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=3e5+100;
vector <int> a[N];
ll t[N];
ll ans[N];
ll Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=max(n,m)+10;i++){
        t[i]=0;
        a[i].clear();
        ans[i]=0;
    }
    for (int i=1;i<=m;i++){
        ll k;
        cin >> k;
        for (int j=0;j<k;j++){
            ll x;
            cin >> x;
            a[i].pb(x);
        }
        t[a[i][0]]++;
        ans[i]=a[i][0];
    }
    ll id=-1;
    ll z=(m+1)/2;
    for (int i=1;i<=n;i++){
        if (t[i]>z) id=i;
    }
    for (int i=1;i<=m;i++){
        if (a[i][0]==id){
            if (t[a[i][0]]>z && a[i].size()>1){
                t[a[i][0]]--;
                t[a[i][1]]++;
                ans[i]=a[i][1];
            }
        }
    }
    if (id!=-1 && t[id]>z) kill("NO");
    cout << "YES" << endl;
    for (int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
int32_t main(){
    ll tt;
    cin >> tt;
    while(tt--) Main();
}