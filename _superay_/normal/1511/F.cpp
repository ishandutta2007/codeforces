#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int go[45][26], ed[45], tot = 1, id[45][45], cnt;
string b[45];
inline bool chk(string s, string t) {
	return s.size() >= t.size() && s.substr(s.size() - t.size(), t.size()) == t;
}
struct Matrix {
	int mat[250][250];
	inline Matrix(int x = 0) {
		for (int i = 1; i <= cnt; i++) for (int j = 1; j <= cnt; j++) mat[i][j] = (i == j ? x : 0);
	}
	inline Matrix operator * (const Matrix &oth) const {
		Matrix res;
		for (int i = 1; i <= cnt; i++) for (int k = 1; k <= cnt; k++) for (int j = 1; j <= cnt; j++)
			res.mat[i][j] = (res.mat[i][j] + 1ll * mat[i][k] * oth.mat[k][j]) % mod;
		return res;
	}
};
inline Matrix matpow(Matrix a, long long b) {
	Matrix res(1);
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
int main() {
	int T, m;
	scanf("%d%d", &T, &m);
	while (T--) {
		char str[10];
		scanf(" %s", str);
		int len = strlen(str);
		int p = 1;
		for (int i = 0; i < len; i++) {
			int c = str[i] - 'a';
			if (!go[p][c]) {
				go[p][c] = ++tot;
				b[go[p][c]] = b[p] + str[i];
			}
			p = go[p][c];
		}
		ed[p] = 1;
	}
	for (int i = 1; i <= tot; i++) {
		for (int j = 1; j <= tot; j++) if (chk(b[i], b[j])) {
			id[i][j] = ++cnt;
		}
	}
	Matrix a;
	auto Add = [&](int i, int j, int x, int y) {
		if (b[x].size() < b[y].size()) swap(x, y);
		a.mat[id[x][y]][id[i][j]]++;
	};
	for (int i = 1; i <= tot; i++) {
		for (int j = 1; j <= tot; j++) if (id[i][j]) {
			for (int c = 0; c < 26; c++) if (go[i][c] && go[j][c]) {
				Add(i, j, go[i][c], go[j][c]);
				if (ed[go[i][c]]) Add(i, j, 1, go[j][c]);
				if (ed[go[j][c]]) Add(i, j, go[i][c], 1);
				if (ed[go[i][c]] && ed[go[j][c]]) Add(i, j, 1, 1);
			}
		}
	}
	printf("%d\n", matpow(a, m).mat[id[1][1]][id[1][1]]);
	return 0;
}