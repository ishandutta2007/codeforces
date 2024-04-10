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
	if(n%2==0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	rep(i, n) cout << 2*i+1+(i%2) << " ";
	rep(i, n) cout << 2*i+1+((i+1)%2) << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}