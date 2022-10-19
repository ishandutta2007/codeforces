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
	if(s.size()==1) {
		cout << "Bob " << s[0]-'a'+1 << '\n';
		return;
	}
	if(s.size()%2==0) {
		cout << "Alice ";
		int ans=0;
		for(auto i : s) ans+=i-'a'+1;
		cout << ans << '\n';
	} else {
		int ans=0;
		for(auto i : s) ans+=i-'a'+1;
		ans-=2*((int)min(s[0], s.back())-'a'+1);
		if(ans<0) cout << "Bob " << -ans << '\n';
		else cout << "Alice " << ans << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}