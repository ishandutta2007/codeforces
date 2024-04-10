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
	string s;
	cin >> n >> s;
	rep(i, 10) {
		string ans="";
		int odw[n], lst=-1;
		rep(j, n) {
			odw[j]=2;
			if(s[j]-'0'<i) {
				odw[j]=1;
				lst=j;
				ans+=s[j];
			}
		}
		for(int j=lst+1; j<n; ++j) if(s[j]-'0'==i) {
			odw[j]=1;
			ans+=s[j];
		}
		rep(j, n) if(odw[j]==2) ans+=s[j];
		bool ok=true;
		rep(j, n-1) if(ans[j]>ans[j+1]) ok=false;
		if(ok) {
			rep(j, n) cout << odw[j];
			cout << '\n';
			return;
		}
	}
	cout << "-\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}