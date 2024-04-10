#include <bits/stdc++.h> ////////////////////
using namespace std;

bool Mbe;
const int N = 1e5 + 5;
const int K = 777;

int n, k, x[N], y[N];
int f[K + 5], pre[K + 5], g[K + 5];
int s[K + 5], ans, delt;
vector <int> buc[N];

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Med - &Mbe) / 1048576.0);
	
//	freopen("tower.in", "r", stdin);
//	freopen("tower.out", "w", stdout);
	
	cin >> n >> k, ans = k * 3;
	for(int i = 1; i <= k; i++) {
		cin >> x[i] >> y[i];
		if(x[i] > n - K)
			buc[n - (x[i] - y[i])].push_back(x[i] - (n - K))
//			, s[n - (x[i] - y[i])][x[i] - (n - K)] = 1
//			, cerr << "fix " << n - (x[i] - y[i]) << " " << x[i] - (n - K) << endl
			;
	}
	
//	for(int i = n; i; i--, cout << endl) {
//		cerr << "sLine " << i << endl;
//		for(int j = 1; j < i; j++) cout << setw(6) << 0;
//		for(int j = 1; j <= K + 1; j++)
//			cout << setw(5) << s[i][j];
//	} cout << endl;
	
	
	pre[0] = 1e9;
	for(int i = 1; i <= K + 1; i++) f[i] = pre[i] = 2;
	for(int i = 1; i <= n; i++) {
		
		memset(s, 0, sizeof(s));
		for(int it : buc[i]) s[it] = 1;
		for(int j = K; j; j--) s[j] = (s[j] ? -2 : 1) + s[j + 1];
		for(int j = 1; j <= K; j++) g[j] = min(pre[j] + 2 + (K - j) * (K - j + 1) / 2, f[j + 1]) + s[j];
		g[K + 1] = min(pre[K] + 2, f[K + 1]);
		
//		cerr << "Line " << i << endl;
//		for(int j = 1; j < i; j++) cout << setw(6) << 0;
//		for(int j = 1; j <= K + 1; j++) cout << setw(6) << g[j]; cout << endl;
		
		
		for(int j = 1; j <= K + 1; j++) pre[j] = min(g[j], pre[j - 1]);
		swap(f, g), delt = min(delt, pre[K + 1]);
	}
	cout << ans + delt << endl;
	return cerr << "Time " << clock() << endl, 0;
}