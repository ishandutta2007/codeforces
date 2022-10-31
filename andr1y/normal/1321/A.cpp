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
const ll N = 228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[N], b[N];
python solve(){
	FAST;
    ll n;
    cin >> n;
    ll uac = 0, ubc = 0, ac = 0, bc = 0;
    for(ll i =0;i<n;i++){
        cin >> a[i];
        ac+=a[i];
    }
    for(ll i =0;i<n;i++){
        cin >> b[i];
        bc+=b[i];
        if(a[i] < b[i]) ubc++;
        if(a[i] > b[i]) uac++;
    }
    if(uac == 0) cout << "-1\n";
    else{
        if(ac > bc) cout << "1\n";
        else{
            ll nd = bc-ac+1;
            ll ao = 1 + nd/uac + (nd%uac ? 1 : 0);
            cout << ao << '\n';
        }
    }
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}