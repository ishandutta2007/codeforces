# include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
# define fi first
# define se second
const int MAXN = 16;
const int MAXK = 2005;
const int MAXA = 4005;
int n, k;
int a[21];
bitset<MAXA> f[1 << 16];
int xs[21];
void dfs(int s, int nv, int nk){
	// cerr << "dfs "<< bitset<16>(s) << ' ' << nv << ' ' << nk << ' ' << f[0][0] << '\n';
	assert(f[s][nv]);
	if (s == 0) return;
	if (nv * k < MAXA && f[s][nv * k]){
		dfs(s, nv * k, nk + 1);
		return;
	}
	for (int i = 0; i < n; i++){
		if (!((s >> i) & 1) || nv < a[i + 1]) continue;
		// if (s == (1 << 12)){
		// 	cerr << "??? " << i << ' ' << (s ^ (1 << i)) << ' ' << nv - a[i + 1] << ' ' << f[s ^ (1 << i)][nv - a[i + 1]] << '\n';
		// 	cerr << "f00 " << f[0][0] << '\n';
		// }
		if (f[s ^ (1 << i)][nv - a[i + 1]]){
			xs[i + 1] = nk;
			dfs(s ^ (1 << i), nv - a[i + 1], nk);
			return;
		}
	}
}
priority_queue <pii> pq;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[0][0] = 1;
	for (int s = 0; s < (1 << n); s++){
		for (int i = (MAXA - 1) / k; i >= 1; i--) f[s][i] = f[s][i] || f[s][i * k];
		// if (s == 1024 || s == 32 || s == 1056) cerr << "f " << s << ' ' << f[s] << '\n';
		for (int i = 0; i < n; i++){
			if ((s >> i) & 1) continue;
			f[s | (1 << i)] |= f[s] << a[i + 1];
		}
	}
	if (!f[(1 << n) - 1][1]) cout << "NO\n";
	else {
		cout << "YES\n";
		dfs((1 << n) - 1, 1, 0);
		for (int i = 1; i <= n; i++){
			pq.push(pii(xs[i], a[i]));
			// cerr << "xs " << xs[i] << ' ' << a[i] << '\n';
		}
		for (int i = 1; i <= n - 1; i++){
			pii n1 = pq.top(); pq.pop();
			pii n2 = pq.top(); pq.pop();
			// cerr << "n12 "  << n1.fi << ' ' << n2.fi << '\n';
			cout << n1.se << ' ' << n2.se << '\n';
			pii nxn = pii(n1.fi, n1.se + n2.se);
			while (nxn.se % k == 0){
				nxn.se /= k;
				nxn.fi--;
			}
			pq.push(nxn);
		}
	}
	return 0;
}