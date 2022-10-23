# include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int t, n, m;
int a[MAXN * 2], b[MAXN * 2];
bool f[MAXN][MAXN * MAXN];
int c[MAXN], d[MAXN];
bool flag[MAXN];
int wrk(int arr[], int brr[], bool tp){
	int bsz = 0;
	int s = 0;
	for (int i = 1; i <= n; i++) s += arr[i];
	if (s & 1) return -1;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= s / 2; j++) f[i][j] = false;
	}
	for (int i = 1; i <= n; i++) flag[i] = false;
	f[0][0] = true;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= s / 2; j++) f[i][j] = f[i - 1][j];
		for (int j = arr[i]; j <= s / 2; j++) f[i][j] |= f[i - 1][j - arr[i]];
	}
	if (!f[n][s / 2]) return -1;
	int nw = s / 2;
	for (int i = n; i >= 1; i--){
		if (nw >= arr[i] && f[i - 1][nw - arr[i]]){
			brr[++bsz] = arr[i];
			flag[i] = true;
			nw -= arr[i];
		}
	}
	int p = bsz;
	for (int i = 1; i <= n; i++) if (!flag[i]) brr[++bsz] = -arr[i];
	if (tp ^ (p > n / 2)){
		reverse(brr + 1, brr + n + 1);
		for (int i = 1; i <= n; i++) brr[i] = -brr[i];
		p = n - p;
	}
	return p;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		cin >> m;
		for (int i = 1; i <= m; i++) cin >> b[i];
		if (n != m){
			cout << "No\n";
			continue;
		}
		int p1 = wrk(a, c, false), p2 = wrk(b, d, true);
		if (p1 == -1 || p2 == -1){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		sort(c + 1, c + p2 + 1, [&](int u, int v){return u > v; });
		sort(c + p2 + 1, c + n + 1);
		sort(d + 1, d + p1 + 1);
		sort(d + p1 + 1, d + n + 1, [&](int u, int v){return u > v; });
		int nx = 0, ny = 0;
		for (int i = 1; i <= n; i++){
			cout << (nx += c[i]) << ' ' << ny << '\n';
			cout << nx << ' ' << (ny += d[i]) << '\n';
		}
		assert(nx == 0 && ny == 0);
	}
	return 0;
}