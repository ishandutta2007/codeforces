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
	int a, b;
	cin >> a >> b;
	char x='0', y='1';
	if(a<b) {
		swap(a, b);
		swap(x, y);
	}
	while(b--) {
		cout << x << y;
		--a;
	}
	while(a--) cout << x;
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}