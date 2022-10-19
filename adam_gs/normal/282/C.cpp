#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	string a, b;
	cin >> a >> b;
	if(a.size()!=b.size()) {
		cout << "NO\n";
		return;
	}
	if(a.size()==1) {
		cout << (a[0]==b[0]?"YES":"NO") << '\n';
		return;
	}
	int za=0, ja=0, zb=0, jb=0;
	for(auto i : a) {
		if(i=='0') ++za; else ++ja;
	}
	for(auto i : b){
		if(i=='0') ++zb; else ++jb;
	}
	if(min(ja, jb)==0 && max(ja, jb)>0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}