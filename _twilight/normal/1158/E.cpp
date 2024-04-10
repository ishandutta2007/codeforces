#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e3 + 5;

int n;
char s[N];
boolean known[N];
vector<int> Ls[N];
vector<boolean> r1, r2;
vector<int> level[N], _level[N], nxt[N];

vector<boolean> ask(vector<int> D) {
	putchar('?');
	for (auto d : D) {
		printf(" %d", d);
	}
	putchar('\n');
	fflush(stdout);
	scanf("%s", s);
	vector<boolean> rt (n);
	for (int i = 0; i < n; i++) {
		rt[i] = s[i] - '0';
	}
	return rt;
}

int main() {
	scanf("%d", &n);
	known[0] = true;
	known[1] = true;
	known[n] = true;
	level[0].push_back(0);
	for (int i = 1; i < n; i++) {
		level[1].push_back(i);
	}
	vector<int> deps;
	while (true) {
		deps.clear();
		for (int i = 0; i <= n; i++) {
			if (known[i]) {
				deps.push_back(i);
				_level[i] = level[i];
			}
		}
		if ((signed) deps.size() == n + 1) {
			break;
		}
		for (int st = 0; st <= 2; st++) {
			vector<int> D (n, 0);
			boolean qry = false;
			for (int i = st; i < (signed) deps.size() - 1; i += 3) {
				int L = deps[i], R = deps[i + 1];
				if (L + 1 == R--) {
					continue;
				} else if (level[L].empty()) {
					known[((L + R) >> 1) + 1] = true;
					continue;
				}
				qry = true;
				int d = ((L + R) >> 1) - L + 1;
				for (auto p : level[deps[i - 1]]) {
					D[p] = d;
				}
			}
			if (!qry) continue;
			r1 = ask(D);
			for (int i = st; i < (signed) deps.size() - 1; i += 3) {
				int L = deps[i], R = deps[i + 1];
				if (L + 1 == R--) {
					continue;
				}
				int d = ((L + R) >> 1) + 1;
				known[d] = true;
				vector<int> tmp1, tmp2;
				for (auto p : level[L]) {
					if (r1[p]) {
						tmp1.push_back(p);
					} else {
						tmp2.push_back(p);
					}
				}
				_level[L] = tmp1, _level[d] = tmp2;
			}
		}
		for (int i = 0; i <= n; i++) {
			if (known[i]) {
				level[i] = _level[i];
				/* cerr << i << ":";
				for (auto p : level[i]) {
					cerr << " " << p;
				}
				cerr << '\n'; */
			}
		}
	}
	int dt = 0;
	while (!level[dt].empty())
		dt++;
	for (int i = 0; i <= n; i++)
		nxt[i].clear();
	/* for (int i = 0; i < dt; i++) {
		for (auto p : level[i]) {
			cerr << p << " ";
		}	
		cerr << '\n';
	} */
	for (int i = 0; i < dt - 1; i++) {
		Ls[i].push_back(0);
		Ls[i].push_back(level[i].size());
		nxt[level[i][0]] = level[i + 1];
	}
	boolean fin = true;
	do {
		fin = true;
		for (int st = 0; st < 3; st++) {
			vector<int> D (n, 0);
			boolean qry = false;
			for (int i = st; i < dt - 1; i += 3) {
				for (int j = 0; j < (signed) Ls[i].size() - 1; j++) {
					int L = Ls[i][j], R = Ls[i][j + 1];
					if (R-- == L + 1) {
						continue;
					}
					qry = true, fin = false;
					int mid = (L + R) >> 1;
					for (int k = L; k <= mid; k++) {
						D[level[i][k]] = 1;
					}
				}
			}
			if (!qry) continue;
			r1 = ask(D);	
			for (int i = st; i < dt - 1; i += 3) {
				vector<int> tmpL;
				for (int j = 0; j < (signed) Ls[i].size() - 1; j++) {
					int L = Ls[i][j], R = Ls[i][j + 1];
					tmpL.push_back(L);
					if (R-- == L + 1) {
						continue;
					}
					tmpL.push_back(((L + R) >> 1) + 1);
					vector<int> tmp1, tmp2;
					int p = level[i][L], q = level[i][tmpL.back()];
					for (auto e : nxt[p]) {
						if (r1[e]) {
							tmp1.push_back(e);
						} else {
							tmp2.push_back(e);
						}
					}
					nxt[p] = tmp1, nxt[q] = tmp2;
				}
				tmpL.push_back(level[i].size());
				Ls[i] = tmpL;
			}
		}
		/* for (int i = 0; i < dt - 1; i++) {
			cerr << i << ": ";
			for (auto p : Ls[i]) {
				cerr << p << " ";
			}	
			cerr << '\n';
		} */
	} while (!fin);
	puts("!");
	for (int i = 0; i < n; i++) {
		for (auto p : nxt[i]) {
			printf("%d %d\n", i + 1, p + 1);
		}
	}
	return 0;
}