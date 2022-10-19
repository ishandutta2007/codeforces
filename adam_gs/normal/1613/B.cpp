#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
void solve() {
	int n;
	cin >> n;
	int T[n], mi=INF;
	rep(i, n) {
		cin >> T[i];
		mi=min(mi, T[i]);
	}
	int x=n/2;
	rep(i, n) {
		if(mi!=T[i]) {
			cout << T[i] << " " << mi << '\n';
			--x;
			if(!x) return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}