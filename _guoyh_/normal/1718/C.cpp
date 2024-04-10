# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
# define fi first
# define se second
const int MAXN = 200051;
const int MAXD = 32;
int T, n, q;
int d[MAXN], dsz;
int a[MAXN];
ll s[MAXD][MAXN];
set<pli> st[MAXD];
ll mx[MAXD];
ll wrk(){
	ll ans = 0;
	for (int i = 1; i <= dsz; i++) ans = max(ans, mx[i] * d[i]);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n >> q;
		d[dsz = 1] = 1;
		int x = n;
		for (int i = 2; i * i <= x; i++){
			if (x % i) continue;
			d[++dsz] = n / i;
			while (x % i == 0) x /= i;
		}
		if (x != n && x != 1) d[++dsz] = n / x;
		for (int i = 1; i <= dsz; i++){
			for (int j = 0; j < d[i]; j++) s[i][j] = 0;
		}
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			for (int j = 1; j <= dsz; j++) s[j][i % d[j]] += a[i];
		}
		for (int i = 1; i <= dsz; i++){
			for (int j = 0; j < d[i]; j++){
				st[i].insert(pli(s[i][j], j));
			}
			mx[i] = (--st[i].end())->fi;
		}
		cout << wrk() << '\n';
		while (q--){
			int u;
			ll v;
			cin >> u >> v;
			for (int i = 1; i <= dsz; i++){
				st[i].erase(pli(s[i][u % d[i]], u % d[i]));
				s[i][u % d[i]] += v - a[u];
				st[i].insert(pli(s[i][u % d[i]], u % d[i]));
				mx[i] = (--st[i].end())->fi;
			}
			a[u] = v;
			cout << wrk() << '\n';
		}
		for (int i = 1; i <= dsz; i++) st[i].clear();
	}
	return 0;
}