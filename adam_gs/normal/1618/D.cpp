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
	int n, k;
	cin >> n >> k; k*=2;
	int T[n];
	rep(i, n) cin >> T[i];
	sort(T, T+n);
	map<int,int>mp;
	int ma=0;
	rep(i, k) {
		++mp[T[n-i-1]];
		ma=max(ma, mp[T[n-i-1]]);
	}
	int ans=0;
	rep(i, n-k) ans+=T[i];
	ans+=max((2*ma-k)/2, 0);
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}