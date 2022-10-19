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
	int n, lst;
	cin >> n >> lst; --n;
	bool ok=true;
	rep(i, n) {
		int a;
		cin >> a;
		if(a>=lst) ok=false;
		lst=a;
	}
	cout << (ok?"NO":"YES") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}