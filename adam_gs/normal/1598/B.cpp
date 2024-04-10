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
	int T[n][5];
	rep(i, n) rep(j, 5) cin >> T[i][j];
	rep(a, 5) rep(b, 5) if(a!=b) {
		int x=0, y=0, z=0;
		rep(i, n) {
			if(T[i][a]) {
				if(T[i][b]) ++z;
				else ++x;
			} else if(T[i][b]) ++y;
		}
		if(x+y+z!=n) continue;
		if(max(x, y)<=n/2) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}