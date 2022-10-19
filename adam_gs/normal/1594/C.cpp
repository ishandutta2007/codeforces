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
	char x;
	string s;
	cin >> n >> x >> s;
	bool ok=true;
	for(auto i : s) if(i!=x) ok=false;
	if(ok) {
		cout << 0 << '\n';
		return;
	}
	s='#'+s;
	for(int i=1; i<=n; ++i) {
		ok=true;
		for(int j=i; j<=n; j+=i) if(s[j]!=x) ok=false;
		if(ok) {
			cout << 1 << '\n' << i << '\n';
			return;
		}
	}
	cout << 2 << '\n' << n << " " << n-1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}