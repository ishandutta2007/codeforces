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
	if(s.size()%2==1) {
		cout << "NO\n";
		return;
	}
	rep(i, s.size()/2) {
		if(s[i]!=s[i+s.size()/2]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}