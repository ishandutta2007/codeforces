#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const string clr[] = {"WR", "YB"};
const string op[] = {".R", "YB"};

struct matrix {
	int a[2][2];
	int* operator [](int x) {
		return a[x];
	}
};

matrix operator *(matrix A, matrix B) {
	matrix C = {0, 0, 0, 0};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				C[i][j] ^= A[i][k] & B[k][j];
	return C;
}

int N, K;
matrix curr[MAXN];
map <string, matrix> trans;
vector <bitset <MAXN>> sys;

void mix(const vector <int> &subset) {
	bitset <MAXN> row[2];
	for (auto it : subset)
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < 2; j++)
				if (curr[it][i][j])
					row[i].set(2 * it + j);
	char result;
	scanf(" %c", &result);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (clr[i][j] == result) {
				if (i)
					row[0].set(2 * N);
				if (j)
					row[1].set(2 * N);
			}
	for (int i = 0; i < 2; i++)
		sys.push_back(row[i]);
}

void update(const vector <int> &subset, matrix mult) {
	for (auto it : subset)
		curr[it] = mult * curr[it];
}

void load() {
	scanf("%d%d", &N, &K);
	trans["RY"] = {0, 1, 1, 0};
	trans["RB"] = {1, 1, 0, 1};
	trans["YB"] = {1, 0, 1, 1};
	for (int i = 0; i < N; i++)
		curr[i] = {1, 0, 0, 1};
	while (K--) {
		string cmd;
		cin >> cmd;
		int m;
		scanf("%d", &m);
		vector <int> cells(m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &cells[i]);
			cells[i]--;
		}
		if (cmd == "mix")
			mix(cells);
		else
			update(cells, trans[cmd]);
	}
}

void solve() {
	int rnk = 0;
	vector <int> cols;
	for (int j = 0; j < 2 * N && rnk < sys.size(); j++) {
		for (int i = rnk; i < sys.size(); i++)
			if (sys[i].test(j)) {
				swap(sys[i], sys[rnk]);
				break;
			}
		if (sys[rnk].test(j)) {
			for (int i = rnk + 1; i < sys.size(); i++)
				if (sys[i].test(j))
					sys[i] ^= sys[rnk];
			cols.push_back(j);
			rnk++;
		}
	}
	
	for (int i = rnk; i < sys.size(); i++)
		if (sys[i].test(2 * N)) {
			puts("NO");
			return;
		}
	
	vector <int> ans(2 * N);
	for (int i = rnk - 1; i >= 0; i--) {
		ans[cols[i]] = sys[i].test(2 * N);
		for (int j = cols[i] + 1; j < 2 * N; j++)
			if (sys[i].test(j))
				ans[cols[i]] ^= ans[j];
	}
	
	puts("YES");
	for (int i = 0; i < N; i++)
		printf("%c", op[ans[2 * i]][ans[2 * i + 1]]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}