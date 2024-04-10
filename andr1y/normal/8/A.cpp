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

ll fip(string& a, string& wh){
	string b = wh+'#'+a;
	vector<ll> pf(b.size(), 0);
	for(ll i = 1;i<b.size();i++){
		ll cur = pf[i-1];
		while(b[i] != b[cur] && cur > 0){
			cur = pf[cur-1];
		}
		if(b[i] == b[cur]) pf[i] = cur+1;
		if(pf[i] == wh.size()) return i;
	}
	return -1;
}

bool check(string& a, string& t1, string& t2){
	ll x1 = fip(a, t1) - t1.size()-1;
	if(x1 <= -1 || x1 == a.size()-1) return 0;
	string a2 = a.substr(x1+1);
	ll x2 = fip(a2, t2);
	return x2 != -1;
}

python solve(){
	FAST;
	string s, s1, s2;
	getline(cin, s );
	getline(cin, s1);
	getline(cin, s2);
	bool a = check(s, s1, s2);
	reverse(itr(s));
	bool b = check(s, s1, s2);
	if(a && b) cout << "both\n";
	else if(a && !b) cout << "forward\n";
	else if(!a && b) cout << "backward\n";
	else cout << "fantasy\n";
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}