#include <bits/stdc++.h>

const int N = 1000005;

int n;
int op[N];
int ls[N], rs[N];
int f[N];

int calc(int op, int x, int y) {
	if (op == 2) {
		return x & y;
	} else if (op == 3) {
		return x | y;
	} else if (op == 4) {
		return x ^ y;
	}
	return -1;
}

void getf(int u) {
	if (op[u] == 0) {
		return;
	}
	if (op[u] == 1) {
		getf(ls[u]);
		f[u] = !f[ls[u]];
	} else {
		getf(ls[u]), getf(rs[u]);
		f[u] = calc(op[u], f[ls[u]], f[rs[u]]);
	}
}

int g[N][2];

void getg(int u) {
	if (op[u] == 0) {
		return;
	}
	if (op[u] == 1) {
		g[ls[u]][0] = g[u][1];
		g[ls[u]][1] = g[u][0];
		getg(ls[u]);
		return;
	}
	for (int i = 0; i < 2; ++i) {
		g[ls[u]][i] = g[u][calc(op[u], i, f[rs[u]])];
	}
	for (int i = 0; i < 2; ++i) {
		g[rs[u]][i] = g[u][calc(op[u], f[ls[u]], i)];
	}
	getg(ls[u]), getg(rs[u]);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::string tmp;
		std::cin >> tmp;
		if (tmp == "IN") {
			op[i] = 0;
			std::cin >> f[i];
		} else if (tmp == "NOT") {
			op[i] = 1;
			std::cin >> ls[i];
		} else {
			if (tmp == "AND") {
				op[i] = 2;
			} else if (tmp == "OR") {
				op[i] = 3;
			} else if (tmp == "XOR") {
				op[i] = 4;
			}
			std::cin >> ls[i] >> rs[i];
		}
	}
	
	getf(1);
	
	g[1][0] = 0, g[1][1] = 1;
	getg(1);
	
	for (int i = 1; i <= n; ++i) {
		if (op[i] == 0) {
			std::cout << g[i][!f[i]];
		}
	}
	std::cout << "\n";
}