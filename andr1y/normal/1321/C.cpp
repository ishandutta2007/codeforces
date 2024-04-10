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
bool ban[N];
python solve(){
	FAST;
    ll n, ans = 0;
    string s;
    cin >> n >> s;
    for(char c = 'z';c>'a';c--){
        for(ll Q = 0;Q<n;Q++){
            for(ll i = 0;i<n;i++){
                if(ban[i] || s[i] != c) continue;
                ll l = i-1, r = i+1;
                while(l >= 0 && ban[l]) --l;
                while(r < n && ban[r]) ++r;
                if((l >= 0 && s[l]==c-1) || (r < n && s[r] == c-1)){
                    ++ans;
                    ban[i] = 1;
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}