#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	string s;
	cin >> s;
	rep(a, 2) rep(b, 2) rep(c, 2) {
		string ans="";
		rep(i, s.size()) {
			if(s[i]=='A') {
				if(a) ans+='('; else ans+=')';
			} else if(s[i]=='B') {
				if(b) ans+='('; else ans+=')';
			} else {
				if(c) ans+='('; else ans+=')';
			}
		}
		int akt=0;
		bool ok=true;
		rep(i, ans.size()) {
			if(ans[i]=='(') ++akt;
			else --akt;
			if(akt<0) ok=false;
		}
		if(akt!=0) ok=false;
		if(ok) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}