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
ll vis[N];
ll h[N];
ll last[N];
ll a[N];
map <int,int> mp;
int Main(){
    ll n,k;
    cin >> n >> k;
  //  cout << 1 << endl;

    for (int i=1;i<=n*k;i++){
        cin >> a[i];
        vis[i]=0;
        h[i]=0;
    }
   // cout << 1 << endl;
    //return 0;
    ll id=1;
    ll j=0;
    vector <pair <int,pii> > ans;
    while(id<=n){
        memset(last,-1,sizeof last);
        for (int i=1;i<=n*k;i++){
            if (h[a[i]] || vis[i]) continue;
            if (last[a[i]]==-1 || last[a[i]]<=j) last[a[i]]=i;
            else{
                id++;
                ans.pb({a[i],{last[a[i]],i}});
              //  cout << last[a[i]] << " " << i << endl;
                j=i;
                h[a[i]]=1;
                vis[i]=1;
                vis[last[a[i]]]=1;
            }
        }
        j=0;
    }
    sort(ans.begin(),ans.end());
    for (auto u : ans){
        cout << u.S.F << " " << u.S.S << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    //cin >> t;
    while(t--) Main();
}