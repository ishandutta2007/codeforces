#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n, K, w[201000], Mul[122][122], Q[122], head, tail, vis[122];
long long res;
map<vector<int>, int>Map;
vector<int>P[122];
vector<int>G[122];
int main() {
	int i, j, cnt=0, k;
	scanf("%d%d", &n, &K);
	vector<int>T(K);
	for (i = 0; i < K; i++)T[i] = i;
	do {
		Map[T] = ++cnt;
		P[cnt] = T;
	} while (next_permutation(T.begin(),T.end()));
	for (i = 1; i <= n; i++) {
		vector<int>U(K);
		for (j = 0; j < K; j++) {
			scanf("%d", &U[j]);
			U[j]--;
		}
		w[i] = Map[U];
		G[w[i]].push_back(i);
	}
	for (i = 1; i <= cnt; i++) {
		for (j = 1; j <= cnt; j++) {
			vector<int>TP(K);
			for (k = 0; k < K; k++) {
				TP[k] = P[j][P[i][k]];
			}
			Mul[j][i] = Map[TP];
		}
	}
	int X[20] = { 0 }, R[20] = { 0 }, PP[20] = { 0 };
	vector<int>Save;
	for (i = n; i >= 1; i--) {
		int c = 0;
		PP[c] = i;
		X[c++] = w[i];
		int a = 1;
		for (j = 1; j <= cnt; j++)vis[j] = 0;
		head = tail = 0;
		Q[++tail] = 1, vis[1] = 1;
		while (head < tail) {
			int x = Q[++head];
			for (j = 0; j < c; j++) {
				int t = Mul[X[j]][x];
				if (!vis[t]) {
					vis[t] = 1;
					Q[++tail] = t;
				}
			}
		}
		R[c - 1] = tail;
		for (auto &t : Save) {
			PP[c] = t;
			X[c++] = w[t];
			head = 0;
			while (head < tail) {
				int x = Q[++head];
				for (j = 0; j < c; j++) {
					int t = Mul[X[j]][x];
					if (!vis[t]) {
						vis[t] = 1;
						Q[++tail] = t;
					}
				}
			}
			R[c - 1] = tail;
		}
		PP[c] = n + 1;

		for (j = 0; j < c; j++) {
			res += 1ll * (PP[j + 1] - PP[j])*R[j];
		}
		Save.clear();
		for (j = 0; j < c; j++) {
			if (!j || R[j] != R[j - 1]) {
				Save.push_back(PP[j]);
			}
		}
	}
	printf("%lld\n", res);
}