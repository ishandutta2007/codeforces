// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define x first
#define y second
const ll N = 2e5+1488;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<pll> gray;
    for(ll i = 0;i<n;i++){
        gray.push_back({i*2, 0});
    }
    vector<pll> ans;
    ans.push_back({-1, 0});
    ans.push_back({-1, -1});
    for(ll ii = 0;ii<n;ii++){
        auto i = gray[ii];
        if(ii!=0&&(ii!=n-1||(ii==n-1&&n%2==1))) ans.push_back({i.x, i.y-2});
        ans.push_back({i.x, i.y-1});
        ans.push_back({i.x, i.y});
        ans.push_back({i.x, i.y+1});
        if(ii!=n-1){
            ans.push_back({i.x, i.y+2});
            ans.push_back({i.x+1, i.y});
            ans.push_back({i.x+1, i.y+2*(ii&1?-1:1)});
        }else{
            if(n%2==0) ans.push_back({i.x, i.y+2});
        }
    }
    auto en = gray.back();
    ans.push_back({en.x+1, en.y});
    if(n&1){
        ans.push_back({en.x+1, en.y+1});
    }else{
        ans.push_back({en.x+1, en.y-1});
    }
    cout<<ans.size()<<'\n';
    for(auto i : ans) cout << i.x << ' ' << i.y << '\n';
}