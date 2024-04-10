#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n];
	if(n%2==0) {
		for(int i=n-2; i; --i) cout << i << " ";
		cout << n-1 << " " << n << '\n';
	} else {
		cout << n-1 << " ";
		for(int i=n-3; i>1; --i) cout << i << " ";
		cout << 1 << " " << n-2 << " " << n << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}