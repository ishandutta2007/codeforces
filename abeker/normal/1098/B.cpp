#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N, M;
string row[MAXN], col[MAXN], ans[MAXN];
int sol = MAXN;
string opt;
bool flag;
	
void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		cin >> row[i];
}

int diff(string s, string per) {
	int res = 0;
	for (int i = 0; i < s.size(); i++)
		res += s[i] != per[i % 2];
	return res;
}

int min_diff(string s, string per) {
	return min(diff(s, {per[0], per[1]}), diff(s, {per[1], per[0]}));
}

int solve_rows(string perm) {
	int res = 0;
	for (int i = 0; i < N; i++) 
		res += min_diff(row[i], perm.substr(i % 2 * 2, 2));
	return res;
}

int solve_cols(string perm) {
	int res = 0;
	for (int i = 0; i < M; i++)
		res += min_diff(col[i], perm.substr(i % 2 * 2, 2));
	return res;
}

void update(int val, string cand, bool f) {
	if (val >= sol)
		return;
	sol = val;
	opt = cand;
	flag = f;
}

void construct_rows(string perm) {
	for (int i = 0; i < N; i++) {
		string curr = perm.substr(i % 2 * 2, 2);
		if (diff(row[i], {curr[1], curr[0]}) < diff(row[i], {curr[0], curr[1]}))
			swap(curr[0], curr[1]);
		for (int j = 0; j < M; j++)
			ans[i][j] = curr[j % 2];
	}
}

void construct_cols(string perm) {
	for (int j = 0; j < M; j++) {
		string curr = perm.substr(j % 2 * 2, 2);
		if (diff(col[j], {curr[1], curr[0]}) < diff(col[j], {curr[0], curr[1]}))
			swap(curr[0], curr[1]);
		for (int i = 0; i < N; i++)
			ans[i][j] = curr[i % 2];
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		ans[i].resize(M);
		for (int j = 0; j < M; j++)
			col[j] += row[i][j];
	}
	
	string ltr = "ACGT";
	do {
		update(solve_rows(ltr), ltr, false);
		update(solve_cols(ltr), ltr, true);
	} while (next_permutation(ltr.begin(), ltr.end()));
	
	if (flag)
		construct_cols(opt);
	else
		construct_rows(opt);
	
	for (int i = 0; i < N; i++)
		puts(ans[i].c_str());
}

int main() {
	load();
	solve();
	return 0;
}