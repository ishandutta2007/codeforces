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
const ll N = 1e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll pref[26][N], suff[26][N];
python solve(){
	FAST;
	string s;
	cin >> s;
	ll n = s.length();
	for(ll c = 0;c<26;c++){
		for(ll i = 0;i<n;i++){
			if(s[i]-'a' == c) pref[c][i] = 1;
			if(i > 0) pref[c][i] += pref[c][i-1];
		}
		for(ll i = n-1;i>=0;i--){
			if(s[i]-'a' == c) suff[c][i] = 1;
			suff[c][i] += suff[c][i+1];
		}
	}
	ll res = 0;
	for(ll c1 = 0;c1<26;c1++){
		res = max(res, suff[c1][0]);
		for(ll c2 = 0;c2<26;c2++){
			ll sum = 0;
			for(ll i =0;i<n;i++){
				if(s[i]-'a' == c1) sum += suff[c2][i+1];
			}
			res = max(res, sum);
		}
	}
	cout << res << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}