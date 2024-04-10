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
	string a, b;
	cin >> a >> b;
	int ile[26];
	rep(i, 26) ile[i]=0;
	for(auto i : a) ++ile[i-'a'];
	rep(i, ile[0]) cout << "a";
	if(b=="abc" && ile[0]) {
		rep(i, ile[2]) cout << "c";
		rep(i, ile[1]) cout << "b";
	} else {
		rep(i, ile[1]) cout << "b";
		rep(i, ile[2]) cout << "c";
	}
	for(int i=3; i<26; ++i) rep(j, ile[i]) cout << char('a'+i);
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}