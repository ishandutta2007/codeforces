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
	rep(i, 26) {
		int ile=0;
		for(auto j : b) if(j=='A'+i) ++ile;
		for(int j=a.size()-1; j>=0; --j) if(a[j]=='A'+i) {
			if(ile>0) --ile;
			else a[j]='?';
		}
		if(ile>0) {
			cout << "NO\n";
			return;
		}
	}
	string ans="";
	for(auto i : a) if(i!='?') ans+=i;
	cout << (ans==b?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}