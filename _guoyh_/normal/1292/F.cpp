# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 65;
const int P = 1000000007;
ll pwr(ll x, ll y){
	x %= P;
	y = (y % (P - 1) + (P - 1)) % (P - 1);
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int n;
int a[MAXN];
bool flag[MAXN][MAXN];
bool ind[MAXN];
bool vis[MAXN];
int as[MAXN], at[MAXN];
int sid[MAXN], tid[MAXN];
int ssz, tsz;
void dfs(int nw){
	// cerr << "dfs " << nw << '\n';
	vis[nw] = true;
	if (ind[nw]){
		at[++tsz] = nw;
		tid[nw] = tsz;
	} else {
		as[++ssz] = nw;
		sid[nw] = ssz;
	}
	for (int i = 1; i <= n; i++){
		if (!flag[nw][i] && !flag[i][nw]) continue;
		if (vis[i]) continue;
		dfs(i);
	}
}
int cs[MAXN];
int f1[1 << 15];
ll f[1 << 15][MAXN];
void upd(ll &a, ll b){
	a = (a + b) % P;
}
ll wrk(int nw){
	// cerr << "wrk " << nw << '\n';
	ssz = tsz = 0;
	dfs(nw);
	if (ssz == 1 && tsz == 0) return 1;
	// cerr << "sz " << ssz << ' ' << tsz << '\n';
	// for (int i = 1; i <= ssz; i++) cerr << a[as[i]] << ' ';
	// cerr << '\n';
	// for (int i = 1; i <= tsz; i++) cerr << a[at[i]] << ' ';
	// cerr << '\n';
	// cerr << '\n';
	memset(f1, 0, sizeof(f1));
	for (int i = 1; i <= tsz; i++){
		int nw = at[i];
		cs[i] = 0;
		for (int j = 1; j <= n; j++){
			if (!sid[j]) continue;
			if (!flag[j][nw]) continue;
			// cerr << "ji " << j << ' ' << nw << ' ' << sid[j] << '\n';
			cs[i] |= (1 << (sid[j] - 1));
		}
		f1[cs[i]]++;
	}
	for (int i = 0; i < ssz; i++){
		for (int s = 0; s < (1 << ssz); s++){
			if ((s >> i) & 1) f1[s] += f1[s ^ (1 << i)];
		}
	}
	// for (int s = 0; s < (1 << ssz); s++) cerr << "f1 " << s << ' ' << f1[s] << '\n';
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= tsz; i++) f[cs[i]][1]++;
	for (int s = 1; s < (1 << ssz); s++){
		for (int i = 1; i <= f1[s]; i++){
			// cerr << "f " << s << ' ' << i << ' ' << f[s][i] << '\n';
			for (int j = 1; j <= tsz; j++){
				if ((cs[j] & s) == 0 || (cs[j] | s) == s) continue;
				upd(f[s | cs[j]][i + 1], f[s][i]);
			}
			if (i < f1[s]) upd(f[s][i + 1], f[s][i] * (f1[s] - i) % P);
		}
	}
	return f[(1 << ssz) - 1][tsz];
}
ll fac[MAXN], ifac[MAXN];
ll C(int u, int v){
	if (v < 0 || v > u) return 0;
	else return fac[u] * ifac[v] % P * ifac[u - v] % P;
}
int main(){
	ios::sync_with_stdio(false);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < MAXN; i++){
		fac[i] = fac[i - 1] * i % P;
		ifac[i] = pwr(fac[i], -1);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j) continue;
			if (a[j] % a[i] == 0) flag[i][j] = ind[j] = true;
		}
	}
	// for (int i = 1; i <= n; i++) cerr << ind[i] << ' ';
	// cerr << '\n';
	ll ans = 1;
	int tol = 0;
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		ans = ans * wrk(i) % P;
		if (tsz > 0){
			ans = ans * C(tol + tsz - 1, tsz - 1);
			tol += tsz - 1;
		}
		// cerr << "ans " << ans << '\n';5
	}
	cout << ans << '\n';
	return 0;
}