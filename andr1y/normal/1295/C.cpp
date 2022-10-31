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
vector<ll> aa[26];
python solve(){
	FAST;
	string s1, s2;
	cin >> s1 >> s2;
	for(ll i =0;i<26;i++) aa[i].clear();
	for(ll i =0;i<s1.length();i++){
		aa[s1[i]-'a'].pb(i);
	}
	ll cursor = -1, res = 0;
	bool ok = 1;
	for(ll i = 0;i<s2.length();i++){
		vector<ll> &vv = aa[s2[i]-'a'];
		if(vv.size()==0){
			ok = 0;
			break;
		}
		if(vv.back() < cursor+1){
			cursor = vv.front();
			res++;
			continue;
		}
		ll r = upper_bound(itr(vv), cursor)-vv.begin();
		cursor = vv[r];
	}
	if(ok) cout << res+1 << '\x0a';
	else cout << "-1\x0a";
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}