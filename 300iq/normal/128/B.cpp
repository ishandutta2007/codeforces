#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 7;
const int MAXV = 2 * MAXN + 7;

int to[MAXV][27];
bool used[MAXV];
int link[MAXV], len[MAXV];
long long dp1[MAXV], dp2[MAXV];
bool leaf[MAXV];
int last, sz, cur, p, q, suf;

void init() {
	for (int i = 0; i < MAXV; i++) {
		memset(to[i], 0, sizeof to[i]);
		link[i] = len[i] = dp1[i] = dp2[i] = 0;
	}
	link[0] = -1;
	len[0] = 0;	
	sz++;
}

void add_char(char c) {
	cur = sz++;
	len[cur] = len[last] + 1;
	p = last;
	while (p != -1 && !to[p][c]) {
		to[p][c] = cur;
		p = link[p];
	}
	if (p == -1) {
		link[cur] = 0;
	} else {
		q = to[p][c];
		suf = sz++;
		len[suf] = len[p] + 1;
		link[suf] = link[q];
		for (int t = 0; t < 26; t++) {
			to[suf][t] = to[q][t];
		}
		while (p != -1 && to[p][c] == q) {
			to[p][c] = suf;
			p = link[p];
		}
		link[q] = suf;
		link[cur] = suf;
	}
	last = cur;
}

long long k;
string ans;

void dfs(int v) {
	if (dp1[v]) {
		return;
	}
	long long cnt = 0, count = 0;
	if (leaf[v]) {
		cnt++;
		count++;
	}
	for (int c = 0; c < 26; c++) {
		if (to[v][c]) {
			dfs(to[v][c]);
			cnt += dp1[to[v][c]];
			count += dp1[to[v][c]] + dp2[to[v][c]];
		}
	}
	dp1[v] = cnt;
	dp2[v] = count;
}

void find(int v) {
	if (k <= 0) {
		return;
	}
	for (int c = 0; c < 26; c++) {
		if (to[v][c]) {
			if (dp2[to[v][c]] >= k) {
				ans += char(c + 'a');
				k -= dp1[to[v][c]];
				find(to[v][c]);
				return;
			} else {
				k -= dp2[to[v][c]];
			}
		}
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	string s;
	cin >> s >> k;
	for (int i = 0; i < (int) s.size(); i++) {
		add_char(s[i] - 'a');	
	}
	int t = last;
	while (t > 0) {
		leaf[t] = true;
		t = link[t];
	}
	dfs(0);
	find(0);
	cout << (ans == "" ? "No such line.\n" : ans) << endl;
}