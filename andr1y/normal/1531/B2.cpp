// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
map<ll, ll> cnt1;
map<pll, ll> cnt2;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q, res=0;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a>b) swap(a, b);
        if(a!=b) res+=cnt1[a]+cnt1[b]-cnt2[{a, b}];
        else res+=cnt1[a];
        cnt1[a]++;
        if(b!=a) cnt1[b]++;
        cnt2[{a, b}]++;
    }
    cout<<res;
}