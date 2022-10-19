#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
void solve() {
	int n, k;
	cin >> n >> k;
	int T[n];
	rep(i, n) cin >> T[i];
	while(k--) {
		int l=0;
		while(l<n && T[l]==0) ++l;
		if(l<n) {
			--T[l];
			++T[n-1];
		}
	}
	rep(i, n) cout << T[i] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}