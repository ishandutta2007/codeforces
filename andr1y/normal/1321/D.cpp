#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 2e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
vector<ll> d[N], cf[N];
ll a[N];
ll mw[N], hmw[N];
bool was[N];
python solve(){
	FAST;
    ll n, m;
    cin >> n >> m;
    for(ll a, b, i =0;i<m;i++){
        cin >> a >> b;
        d[a].pb(b);
        cf[b].pb(a);
    }
    ll k;
    cin >> k;
    for(ll i =0;i<k;i++){
        cin >> a[i];
    }
    queue<pll> q;
    q.push({a[k-1],  0});
    was[a[k-1]] = 1;
    mw[a[k-1]] = 0, hmw[a[k-1]] = 0;
    while(!q.empty()){
        pll now = q.front();
        q.pop();
        ll v = now.x, l = now.y;
        for(auto i : cf[v]){
            if(was[i]){
                if(mw[i] == l+1) hmw[i]++;
            }else{
                was[i] = 1;
                mw[i] = l+1;
                q.push({i, l+1});
            }
        }
    }
    ll minans = 0, maxans = 0;
    for(ll i =0;i<k-1;i++){
        ll l = k-i-1, v = a[i];
        assert(was[v]);
        if(d[v].size() == 1) continue;
        else{
            ll amax = 0, amin = 0;
            for(auto j : d[v]){
                if(mw[j] == mw[v]-1 && j != a[i+1]) ++amax;
                if(mw[j] == mw[v]-1 && j == a[i+1]) ++amin;
            }
            if(!amin) ++minans, maxans++;
            else if(amax) ++maxans;
            //if(mw[v] < l || (mw[v] == l && mw[a[i+1]]+1 != l)) ++minans, maxans++;
            //else if(amax) ++maxans;
        }
    }
    cout << minans << " " << maxans << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}