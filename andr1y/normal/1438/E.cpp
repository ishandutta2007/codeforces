// ++ //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
typedef long long ll;
using namespace std;
const ll N = 2e5+228;
ll a[N];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    set<pll> ans;
    for(ll i = 0;i<n;i++){
        ll s = a[i+1];
        ll e = 0;
        while((1LL<<e)<=a[i])e++;
        e=(1ll<<(e))-1;
        for(ll j = i+2;j<n;j++){
            if(s==(a[i]^a[j])) ans.insert({i, j});
            s+=a[j];
            if(s>e) break;
        }
    }
    for(ll i = n-1;i>0;i--){
        ll s = a[i-1];
        ll e = 0;
        while((1LL<<e)<=a[i])e++;
        e=(1ll<<(e))-1;
        for(ll j = i-2;j>=0;j--){
            if(s==(a[i]^a[j])) ans.insert({j, i});
            s+=a[j];
            if(s>e) break;
        }
    }
    //for(auto i : ans) cerr<<i.x<<' '<<i.y<<'\n';
    cout<<ans.size();
}