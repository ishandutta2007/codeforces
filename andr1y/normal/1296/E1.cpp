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
const ll N = 228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
bool dp[N][26][26];
pair<pll, bool> p[N][26][26];
python solve(){
	FAST;
	ll n;
	string s, xs;
	cin >> n >> s;
	dp[0][0][0] = 1;
	for(ll i = 0;i<n;i++){
		ll c = s[i]-'a';
		for(ll c1 = 0;c1<26;c1++){
			for(ll c2 = 0; c2<26;c2++){
				if(!dp[i][c1][c2]) continue;
				if(c >= c1){
					dp[i+1][c][c2] =1;
					p[i+1][c][c2] = {{c1, c2}, 0};
				}
				if(c >= c2){
					dp[i+1][c1][c] = 1;
					p[i+1][c1][c] = {{c1, c2}, 1};
				}
			}
		}
	}
	ll x = -1, y = -1;
	for(ll c1 = 0;c1<26;c1++){
		for(ll c2 = 0; c2<26;c2++){
			if(dp[n][c1][c2]){
				x = c1, y = c2;
				break;
			}
		}
	}
	if(x == -1) {
		cout << "NO\n";
		return;
	}
	string ans = "";
	for(ll i = n;i>0;--i){
		ll px = p[i][x][y].x.x;
		ll py = p[i][x][y].x.y;
		if(p[i][x][y].y) ans += "1";
		else ans+="0";
		x=  px, y = py;
	}
	reverse(itr(ans));
	cout << "YES\n" << ans << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}