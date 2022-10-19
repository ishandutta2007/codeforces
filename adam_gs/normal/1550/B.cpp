#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
	int n, a, b;
	string x;
	cin >> n >> a >> b >> x;
	if(b>=0) {
		cout << n*(a+b) << '\n';
		return;
	}
	int ile=1;
	for(int i=1; i<n; ++i) if(x[i]!=x[i-1]) ++ile;
	cout << (ile/2+1)*b+n*a << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}