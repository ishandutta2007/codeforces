#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

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
python solve(){
	FAST;
	ll n, k;
	string s;
	cin >> n >> k>> s;
	map<ll, map<ll, ll>> cc;
	for(ll i = 0;i<n;i++){
		cc[i%k][s[i]-'a']++;
	}
	ll res = 0, d = n/k;
	for(ll i = 0;i<k/2+k%2;i++){
		ll tr = d+(i!=k/2?d:0);
		for(ll j = 0;j<26;j++){
			tr = min(tr, d+(i!=k/2?d-cc[k-i-1][j]:0)-cc[i][j]);
		}
		res += tr;
	}
	cout << res << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}