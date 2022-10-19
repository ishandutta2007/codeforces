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
	int ile[26];
	rep(i, 26) ile[i]=0;
	string okr="";
	for(auto i : s) {
		if(ile[i-'a']) break;
		++ile[i-'a'];
		okr+=i;
	}
	rep(i, s.size()) if(s[i]!=okr[i%okr.size()]) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}