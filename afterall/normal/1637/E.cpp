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
const int N=3e5+100;

vector <int> ja[N];
ll a[N];
map <int,int> mp;
map <pii,int> bad;
ll vis[N];
ll vazn(ll i,ll j,ll x,ll y){
    return -(ll)(ja[i][x]+ja[j][y])*(ll)(i+j);
}
ll solve(ll i,ll j){
    set <pair <int,pii> > s;
    s.insert({vazn(i,j,0,0),{0,0}});
    ll ans=0;
    while(s.size()){
        ll x=s.begin()->S.F;
        ll y=s.begin()->S.S;
        s.erase(s.begin());
        if (x>=ja[i].size() || y>=ja[j].size()) continue;
       // cout << ja[i][x] << " kerjfkjn " << ja[j][y] << endl;
        if (!bad[{ja[i][x],ja[j][y]}] && ja[i][x]!=ja[j][y]){
            ans=max(ans,-vazn(i,j,x,y));
            return ans;
        }
        s.insert({vazn(i,j,x+1,y),{x+1,y}});
        s.insert({vazn(i,j,x,y+1),{x,y+1}});
    }
    return ans;
}
int Main(){
    mp.clear();
    bad.clear();
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) ja[i].clear(),vis[i]=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i=0;i<m;i++){
        ll x,y;
        cin >> x >> y;
        bad[{x,y}]=1;
        bad[{y,x}]=1;
    }
    vector <int> q;
    for (int i=1;i<=n;i++){
        ja[mp[a[i]]].pb(a[i]);
    }
    for (int i=1;i<=n;i++){
        sort(ja[i].begin(),ja[i].end());
        ja[i].resize(unique(ja[i].begin(),ja[i].end())-ja[i].begin());
        reverse(ja[i].begin(),ja[i].end());
        if (ja[i].size()==0) continue;
        q.pb(i);
    }
    ll ans=0;
    for (int i=0;i<q.size();i++){
        for (int j=0;j<q.size();j++){
            ll z=solve(q[i],q[j]);
         //   cout << q[i] << " " << q[j] << " " << z << endl;
            ans=max(ans,solve(q[i],q[j]));
        }
    }
   // cout << ja[1].size() << endl;
   cout << ans << endl;
    return 0;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc --) Main();
    return 0;
}