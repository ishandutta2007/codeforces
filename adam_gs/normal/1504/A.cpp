#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
	string x;
	cin >> x;
	int n=x.size()+1;
	string p='a'+x;
	bool ans=true;
	rep(i, n) {
		if(p[i]!=p[n-i-1]) ans=false;
	}
	if(!ans) {
		cout << "YES\n" << p << '\n';
		return;
	}
	p=x+'a';
	ans=true;
	rep(i, n) if(p[i]!=p[n-i-1]) {
		ans=false;
	}
	if(!ans) {
		cout << "YES\n" << p << '\n';
		return;
	}
	cout << "NO\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}