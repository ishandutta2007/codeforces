#include<bits/stdc++.h>

using namespace std;

int n, Mod = 998244353, K, R[2][80], Comb[110][110], D[5010][80], T[80];
vector<int>E[5010], Ch[5010];

void DFS(int a, int pp) {
	int i, j;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		DFS(x, a);
		Ch[a].push_back(x);
	}
	D[a][0] = 1;
	if (Ch[a].empty()) {
		return;
	}
	for (i = 0; i <= K; i+=2) {
		for (auto &x : Ch[a]) {
			for (j = 0; i + j + 2 <= K; j+=2) {
				D[a][i + j + 2] = (D[a][i + j + 2] + (long long)D[a][i] * D[x][j]) % Mod;
			}
		}
	}
}

void Go(int a) {
	int i, j, k;
	for (auto &x : Ch[a]) {
		for (j = 0; j <= K; j++)T[j] = 0;
		for (j = 0; j <= K; j+=2) {
			for (k = 0; j+k <= K; k+=2) {
				T[j + k] = (T[j + k] + (long long)D[x][j] * D[x][k]) % Mod;
			}
		}
		for (j = K; j >= 2; j-=2) {
			for (k = 0; k <= j - 2; k+=2) {
				D[x][j] = (D[x][j] + (long long)T[k] * D[a][j - k - 2]) % Mod;
			}
		}
		Go(x);
	}
}

void Do(int pv) {
	int i, j, a, b;
	for (i = 1; i <= n; i++) {
		E[i].clear();
		Ch[i].clear();
		for (j = 0; j <= K; j++)D[i][j] = 0;
	}
	for (i = 1; i < n; i++) {
		cin>>a>>b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	Go(1);
	for (i = 0; i <= K; i += 2) {
		for (j = 1; j <= n; j++) {
			R[pv][i] = (R[pv][i] + D[j][i]) % Mod;
		}
	}
}
int main() {
	int i, a, b, j, n1, n2;
	for (i = 0; i <= 100; i++) {
		Comb[i][0] = 1;
		for (j = 1; j <= i; j++)Comb[i][j] = (Comb[i - 1][j - 1] + Comb[i - 1][j]) % Mod;
	}
	cin>>n1>>n2>>K;
	n = n1;
	Do(0);
	n = n2;
	Do(1);
	int res = 0;
	for (i = 0; i <= K; i++) {
		res = (res + 1ll*R[0][i] * R[1][K - i]%Mod*Comb[K][i]) % Mod;
	}
	cout<<res<<endl;
	return 0;
}