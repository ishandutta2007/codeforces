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
	int n;
	cin >> n;
	string ans="";
	rep(i, n-2) {
		string x;
		cin >> x;
		if(ans.back()!=x[0]) {
			ans+=x[0];
		}
		ans+=x[1];
	}
	if(ans.size()==n-1) ans+="a";
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}