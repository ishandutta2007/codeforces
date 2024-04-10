#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100;
ll a[N];
vector <int> b[N];
ll zoj[N];
void Main(){
    ll n,m;
    cin >> n >> m;
    ll ans=0;
    for (int i=1;i<=n;i++){
        b[i-1].clear();
        cin >> a[i];
        zoj[i-1]=0;
        ans+=abs(a[i]);
    }
    ll g=0;
    for (int i=1;i<=m;i++){
        ll x;
        cin >> x;
        g=__gcd(g,x);
    }
    for (int i=1;i<=n;i++){
        b[i%g].pb(abs(a[i]));
        if (a[i]<0) zoj[i%g]=1-zoj[i%g];
    }
    ll p1=0,p2=0;
    for (int i=0;i<g;i++){
        sort(b[i].begin(),b[i].end());
        if (zoj[i]==0) p1+=b[i][0];
        else p2+=b[i][0];
    }
    cout << ans-2*min(p1,p2) << endl;

}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}