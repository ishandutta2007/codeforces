# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100051;
int T, n;
ll a[MAXN], b[MAXN];
ll b1[MAXN], sz1;
ll b0[MAXN], sz0;
ll s0[MAXN], s1[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		sz1 = sz0 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ll mi = 1e18;
		for (int i = 1; i <= n; i++){
			cin >> b[i];
			if (a[i]){
				b1[++sz1] = b[i];
			} else {
				b0[++sz0] = b[i];
			}
			mi = min(mi, b[i]);
		}
		sort(b1 + 1, b1 + sz1 + 1, [&](int u, int v){ return u > v; });
		sort(b0 + 1, b0 + sz0 + 1, [&](int u, int v){ return u > v; });
		for (int i = 1; i <= sz0; i++) s0[i] = s0[i - 1] + b0[i];
		for (int i = 1; i <= sz1; i++) s1[i] = s1[i - 1] + b1[i];
		if (sz0 == sz1) cout << 2 * (s0[sz0] + s1[sz1]) - mi << '\n';
		else if (sz0 < sz1) cout << 2 * s0[sz0] + 2 * s1[sz0] + s1[sz1] - s1[sz0] << '\n';
		else cout << 2 * s1[sz1] + 2 * s0[sz1] + s0[sz0] - s0[sz1] << '\n';
	}
	return 0;
}