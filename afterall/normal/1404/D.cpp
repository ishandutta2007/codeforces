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
const int N=1e6+100;
vector <int> g[N];
ll r[N];
vector <int> p[N];
vector <int> ras;
ll o=0;
ll dfs(ll v){
    if (o==0) ras.pb(v);
    ll z=3-r[v];
   // cout << v << " j " << r[v] << endl;
    for (auto u : g[v]){
        if (r[u]==z) continue;
        r[u]=z;
        dfs(u);
    }
}
int32_t main(){
    ll n;
    cin >> n;
    if (n%2==0){
        cout << "First" << endl;
        cout.flush();
        for (int i=1;i<=2*n;i++){
            ll z=i%n;
            if (z==0) z=n;
            cout << z << " ";
        }
        cout << endl;
        cout.flush();
        ll v;
        cin >> v;
        return 0;
    }
    cout << "Second" << endl;
    cout.flush();
    for (int i=1;i<=n;i++){
        g[i].pb(i+n);
        g[i+n].pb(i);
    }
    for (int i=1;i<=2*n;i++){
        ll x;
        cin >> x;
        p[x].pb(i);
    }
    for (int i=1;i<=n;i++){
        g[p[i][0]].pb(p[i][1]);
        g[p[i][1]].pb(p[i][0]);
    }
    for (int i=1;i<=2*n;i++){
        if (r[i]==0){
            r[i]=1;
            dfs(i);
            if (ras.size()%4!=0){
                o=1;
            }
            else ras.clear();
        }
    }
    ll y=0;
    for (int i=1;i<=n*2;i++){
        if (r[i]==1) y+=i;
      //  cout << r[i] << " ";
    }

    if (y%(2*n)!=0){
        r[ras[0]]=3-r[ras[0]];
        dfs(ras[0]);
    }
    for (int i=1;i<=2*n;i++){
        if (r[i]==1) cout << i << " ";
    }
    cout << endl;
    cout.flush();
    ll d;
    cin >> d;

}