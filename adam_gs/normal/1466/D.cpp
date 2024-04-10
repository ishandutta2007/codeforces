#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr make_pair
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7;
const ll MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		pair<ll, int>T[n];
		rep(i, n) { cin >> T[i].first; T[i].second=-1; }
		rep(i, n-1) {
			int a, b;
			cin >> a >> b; --a; --b;
			++T[a].second;
			++T[b].second;
		}
		sort(T, T+n);
		int l=n-1;
		ll ans=0;
		rep(i, n) ans+=T[i].first;
		cout << ans << " ";
		rep(i, n-2) {
			while(!T[l].second) --l;
			--T[l].second;
			ans+=T[l].first;
			cout << ans << " ";
		}
		cout << '\n';
	}
}