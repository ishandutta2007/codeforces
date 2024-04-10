#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef int ll;
typedef complex<long double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100,M=26e5;
vector <int> t[M];
pii e[M];
ll vis[M];
ll vi[N];
vector <pii> d[M*2];
int Main(){
    ll n;
    cin >> n ;
    vector <int> a;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        t[x].pb(i);
        if (vis[x]==0){
            a.pb(x);
        }
        else vi[i-1]=1,a.pb(x);
        vis[x]=1;
    }
    vector <int> yek;
    for (int i=0;i<M;i++){
        if (t[i].size()>1){
            yek.pb(t[i][0]);
            yek.pb(t[i][1]);
            d[i*2].pb({t[i][0],t[i][1]});
          //  cout << i*2 << endl;
        }
        if (t[i].size()>3){
            cout << "YES" << endl;
            cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << " " << t[i][3] << endl;
            return 0;
        }
        if (yek.size()==4){
            cout << "YES" << endl;
            cout << yek[0] << " " << yek[2] << " " << yek[3] << " " << yek[1] << endl;
            return 0;
        }
    }
    for (int i=0;i<a.size();i++){
        if (vi[i]) continue;
        for (int j=i+1;j<a.size();j++){
            if (vi[j]) continue;
            d[a[i]+a[j]].pb({i+1,j+1});
         //   cout << a[i] << " " << a[j] << endl;
            if (d[a[i]+a[j]].size()>1){
                cout << "YES" << endl;
                cout << d[a[i]+a[j]][0].F << " " << d[a[i]+a[j]][0].S << " " << d[a[i]+a[j]][1].F << " " << d[a[i]+a[j]][1].S << endl;
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}
int32_t main(){
    ll t;
    //cin >> t;
    t=1;
    while(t--) Main();
}