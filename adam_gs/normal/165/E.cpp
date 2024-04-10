#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=1e6+7;
int T[LIM], dp[1<<22];
void solve() {
	int n;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		dp[T[i]]=T[i];
	}
	rep(i, 1<<22) {
		if(dp[i]) {
			rep(j, 22) if(!(i&(1<<j))) {
				dp[i+(1<<j)]=dp[i];
			}
		} else {
			dp[i]=-1;
		}
	}
	rep(i, n) cout << dp[(1<<22)-T[i]-1] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}