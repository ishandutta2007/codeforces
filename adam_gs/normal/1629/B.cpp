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
	int l, r, k;
	cin >> l >> r >> k;
	if(r==1) {
		cout << "NO\n";
		return;
	}
	cout << (r==l||r/2-(l-1)/2>=r-l-k+1?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}