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
const int N=2e5+100,M=31;
ll a[N];
vector <int> ja[M];
ll par[N];
vector <pii> ans;
ll check(ll i,ll j){
    if (i>j) swap(i,j);
    ll sum=par[j-1]-par[i];
    if (sum==(a[i] ^ a[j])){
        ans.pb({i,j});
    }
}
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        par[i]=par[i-1]+a[i];
        for (int j=0;j<M;j++){
            if ((a[i] & ((ll)1<<j))) ja[j].pb(i);
        }
    }
    for (int bit=0;bit<M;bit++){
        ll cnt=-1;
        for (int i=1;i<=n;i++){
            if ((a[i] & ((ll)1<<bit))){
                cnt++;
                continue;
            }
            if (cnt!=-1 && cnt!=ja[bit].size()){
                ll id=ja[bit][cnt];
                check(id,i);
            }
            if (cnt-1>=0){
                check(ja[bit][cnt-1],i);
            }
            if (cnt+1<ja[bit].size()){
                check(ja[bit][cnt+1],i);
            }
            if (cnt+2<ja[bit].size()){
                check(ja[bit][cnt+2],i);
            }

        }
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    cout << ans.size() << endl;

}
int32_t main(){
    sync;
    ll t;
    t=1;
   // cin >> t;
    while(t--) Main();
}