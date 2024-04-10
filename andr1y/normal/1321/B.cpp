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
const ll N = 4e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[N];
map<ll, ll> c;
python solve(){
	FAST;
    ll n;
    cin >> n;
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        c[a[i]-i+N]+=a[i];
    }
    ll mv = 0;
    for(auto i : c ) mv = max(mv, i.y);
    cout <<mv << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}