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
set<ll> d[26];
bool was[N], w2[N];
ll leaf = -1;
bool dfs(ll v, ll p = -1){
	if(d[v].size() > 2) return false;
	if(d[v].size() == 1) leaf = v;
	bool ok = 1;
	was[v] = 1;
	for(auto i : d[v]){
		if( i == p) continue;
		if(was[i]){
			return 0;
		}
		ok = ok & dfs(i, v);
	}
	return ok;
}
string res = "";
void d2(ll v, ll p = -1){
	res+=v+'a';
	for(auto i : d[v]){
		if(i!=p) d2(i, v);
	}
}
python solve(){
	FAST;
	for(ll i =0;i<26;i++){
		d[i].clear();
		was[i] = 0;
		w2[i] = 0;
	}
	res = "";
	leaf = -1;
	string s;
	cin >> s;
	ll n = s.length();
	if(n <= 2){
		for(ll i = 0;i<n;i++) w2[s[i]-'a'] = 1;
		res = s;
		for(ll i =0;i<26;i++) if(!w2[i]) res += i+'a';
		cout << "YES\n"<<res << '\n';
		return;
	}
	for(ll i = 1;i<n-1;i++){
		d[s[i]-'a'].insert(s[i-1]-'a');
		d[s[i]-'a'].insert(s[i+1]-'a');
		d[s[i-1]-'a'].insert(s[i]-'a');
		d[s[i+1]-'a'].insert(s[i]-'a');
		w2[s[i-1]-'a'] = 1;
		w2[s[i+1]-'a'] = 1;
		w2[s[i]-'a'] = 1;
	}
	bool ok = 0;
	for(ll i  =0;i<26;i++){
		if(w2[i]){
			bool o2 = dfs(i);
			for(ll j = 0;j<26 && o2;j++){
				if(w2[j] & !was[j]) o2 = 0;
			}
			ok = o2;
			break;
		}
	}
	ok = ok && leaf != -1;
	if(ok){
		cout << "YES\n";
		d2(leaf);
		for(ll i = 0;i<26;i++) if(!w2[i]) res += i+'a';
		cout << res << '\n';
	}else{
		cout << "NO\n";
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