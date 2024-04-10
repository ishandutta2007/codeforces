#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	vector<int>V(1001);
	int n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		V[a]=i+1;
	}
	int ans=-1;
	rep(i, 1000) rep(j, 1000) if(__gcd(i+1, j+1)==1 && V[i+1] && V[j+1]) ans=max(ans, V[i+1]+V[j+1]);
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}