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

ll n, k;

python solve(){
	FAST;
	string s1, s2;
	cin >> s1 >> s2;
	if(s1 < s2) cout << s1 << '\n';
	else{
		ll p = 0;
		string s12 = s1;
		sort(itr(s12));
		while(s1[p] == s12[p]) ++p;
		char xp = 'z';
		for(ll i = p+1;i<s1.length();i++){
			xp = min(xp, s1[i]);
		}
		for(ll i = s1.length()-1;i>p;i--){
			if(s1[i] == xp){
				swap(s1[p], s1[i]);
				break;
			}
		}
		if(s1 < s2) cout << s1 << '\n';
		else cout << "---\n";
	}
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}