#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
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
	if(n==1 || s[0]<=s[1]) {
		cout << s[0] << s[0] << '\n';
		return;
	}
	string ans="";
	ans+=s[0];
	for(int i=1; i<n; ++i) {
		if(s[i]>s[i-1]) break;
		ans+=s[i];
	}
	cout << ans;
	reverse(all(ans));
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}