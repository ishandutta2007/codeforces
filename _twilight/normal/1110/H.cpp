#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int M = 805, N = 2e3 + 5;

typedef class TrieNode {
	public:
		TrieNode* ch[10];
		TrieNode* fail;
		int g[M];

		int id();
		int sum(int n);
		TrieNode* extend(int c);
} TrieNode;

TrieNode pool[200 * M];
TrieNode *top = pool;

TrieNode* newnode() {
	return top++;
}

TrieNode* TrieNode :: extend(int c) {
	return (ch[c]) ? (ch[c]) : (ch[c] = newnode());
}
int TrieNode :: id() {
	return this - pool;
}

typedef class Trie {
	public:
		TrieNode* rt;

		Trie() : rt(NULL) {	}
		Trie(char* sL, int len1, char* sR, int len2) {
			rt = newnode();
			TrieNode *pl = rt, *pr = rt;
			if (len1 == len2) {
				for (int i = 0; i < len1; i++) {
					int cl = sL[i] - '0', cr = sR[i] - '0';
					if (pl == pr) {
						TrieNode* pc;
						for (int c = cl + 1; c < cr; c++) {
							pc = pl->extend(c);
							pc->g[len1 - i - 1]++;
						}
					} else {
						for (int c = cl + 1; c < 10; c++) {
							pl->extend(c)->g[len1 - i - 1]++;
						}
						for (int c = 0; c < cr; c++) {
							pr->extend(c)->g[len2 - i - 1]++;
						}
					}
					pl = pl->extend(cl);
					pr = pr->extend(cr);
				}
				pl->g[0]++;
				if (pl != pr) {
					pr->g[0]++;
				}
			} else {
				for (int i = 0, c; i < len1; i++) {
					c = sL[i] - '0';
					for (int j = c + 1; j < 10; j++) {
						pl->extend(j)->g[len1 - i - 1]++;
					}
					pl = pl->extend(c);
				}
				for (int i = 0, c; i < len2; i++) {
					c = sR[i] - '0';
					for (int j = (!i); j < c; j++) {
						pr->extend(j)->g[len2 - i - 1]++;
					}
					pr = pr->extend(c);
				}
				for (int l = len1 + 1; l < len2; l++) {
					for (int j = 1; j < 10; j++) {
						rt->extend(j)->g[l - 1]++;
					}
				}
				pl->g[0]++, pr->g[0]++;
			}
			build(len2);
		}

		void build(int len2) {
			queue<TrieNode*> que;
			for (int i = 0; i < 10; i++) {
				if (rt->ch[i]) {
					rt->ch[i]->fail = rt;
					que.push(rt->ch[i]);
				} else {
					rt->ch[i] = rt;
				}
			}
			while (!que.empty()) {
				TrieNode *p = que.front();
				que.pop();
				for (int i = 0; i <= len2; i++) {
					p->g[i] += p->fail->g[i];
				}
				for (int i = 0; i < 10; i++) {
					if (p->ch[i]) {
						p->ch[i]->fail = p->fail->ch[i];
						que.push(p->ch[i]);
					} else {
						p->ch[i] = p->fail->ch[i];
					}
				}
			}
			for (TrieNode* p = pool; p != top; p++) {
				for (int j = 1; j <= len2; j++) {
					p->g[j] += p->g[j - 1];
				}
			}
		}
		
} Trie;

int n;
Trie tr;
int len1, len2;
char sL[M], sR[M];
vector<vector<int> > f;
vector<vector<char> > g;

int TrieNode :: sum(int n) {
	return (n > len2) ? (g[len2]) : (g[n]); 
}

inline void init() {
	scanf("%s", sL);
	scanf("%s", sR);
	len1 = strlen(sL);
	len2 = strlen(sR);
	scanf("%d", &n);
}

int dfs(int len, TrieNode *p) {
	if (len == n) {
		return 0;
	}
	int id = p->id();
	if (~f[len][id]) {
		return f[len][id];
	}
	int& rt = f[len][id];
	for (int c = 0; c < 10; c++) {
		int t = dfs(len + 1, p->ch[c]) + p->ch[c]->sum(n - len - 1);
		if (t > rt) {
			g[len][id] = c + '0';
			rt = t;
		}
	}
	return rt;
}

inline void solve() {
	tr = move(Trie(sL, len1, sR, len2));
	f = move(vector<vector<int> >(n + 1, vector<int> (top - pool, -1)));
	g = move(vector<vector<char> >(n + 1, vector<char> (top - pool, '0')));
	int ans = dfs(0, tr.rt);
	printf("%d\n", ans);
	TrieNode* p = tr.rt;
	for (int i = 0; i < n; i++) {
		printf("%c", g[i][p->id()]);
		p = p->ch[g[i][p->id()] - '0'];
	}
}

int main() {
	init();
	solve();
	return 0;
}