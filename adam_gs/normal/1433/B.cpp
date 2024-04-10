#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=57;
int T[LIM];
void solve() {
	int n, l=LIM, r=0, sum=0;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		if(T[i]) {
			++sum;
			l=min(l, i);
			r=max(r, i);
		}
	}
	cout << r-l+1-sum << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}