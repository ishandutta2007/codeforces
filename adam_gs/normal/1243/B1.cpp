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
	int n, ile=0;
	string s, t;
	cin >> n >> s >> t;
	rep(i, n) if(s[i]!=t[i]) ++ile;
	if(!ile) {
		cout << "Yes\n";
		return;
	}
	if(ile!=2) {
		cout << "No\n";
		return;
	}
	rep(i, n) if(s[i]!=t[i]) {
		for(int j=i+1; j<n; ++j) if(s[j]!=t[j]) swap(s[i], t[j]);
		break;
	}
	cout << (s==t?"Yes":"No") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}