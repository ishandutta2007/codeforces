#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, INF=2e18+7;
int T[LIM];
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, sum=0;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
	}
	sort(T, T+n);
	cin >> m;
	while(m--) {
		int x, y;
		cin >> x >> y;
		int ans=INF;
		auto it=lower_bound(T, T+n, x);
		if(it<T+n) {
			int p=*it;
			ans=min(ans, max(0ll, y-sum+p));
		}
		if(it>T) {
			--it;
			int p=*it;
			ans=min(ans, max(0ll, y-sum+p)+x-p);
		}
		cout << ans << '\n';
	}
}