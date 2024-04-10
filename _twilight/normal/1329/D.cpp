#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

#define pic pair<int, char>
#define pii pair<int, int>

typedef class Fenwick {
	public:
		int s;
		vector<int> a;

		Fenwick() {	}

		void init(int n) {
			this->s = n;
			a.assign(n + 1, 0);
		}
		void add(int idx, int val) {
			for ( ; idx <= s; idx += idx & (-idx)) {
				a[idx] += val;
			}
		}
		int query(int idx) {
			int ret = 0;
			for ( ; idx; idx -= idx & (-idx)) {
				ret += a[idx];
			}
			return ret;
		}
} Fenwick;

int n;
char s[N];
set<pii> Sp;
set<pii> G[26];

int cnt[26];

void remove_edge(int x, int y) {
	if (x > y) {
		swap(x, y);
	}
	if (s[x] ^ s[y]) {
		G[s[x]].erase(pii(x, y));
		G[s[y]].erase(pii(x, y));
	}
}
void add_edge(int x, int y) {
	if (x > y) {
		swap(x, y);
	}
	if (s[x] ^ s[y]) {
		G[s[x]].insert(pii(x, y));
		G[s[y]].insert(pii(x, y));
	} 
} 

void insert(int p, int c) {
	++cnt[c];
	auto it = Sp.insert(pic(p, c)).first;
	auto pr = it, sf = it;
	++sf;
	if (it != Sp.begin()) {
		--pr;
		add_edge((*pr).first, p);
	}
	if (sf != Sp.end()) {
		add_edge(p, (*sf).first);
	}
	if (it != Sp.begin() && sf != Sp.end()) {
		remove_edge((*pr).first, (*sf).first);
	}
	
}
void remove(int p, int c) {
	--cnt[c];
	auto it = Sp.find(pic(p, c));
	auto pr = it, sf = it;
	++sf;
	if (it != Sp.begin()) {
		--pr;
		remove_edge((*pr).first, p);
	}
	if (sf != Sp.end()) {
		remove_edge(p, (*sf).first);
	}
	if (it != Sp.begin() && sf != Sp.end()) {
		add_edge((*pr).first, (*sf).first);
	}
	Sp.erase(it);
}

Fenwick fen;
vector<pii> seq;
vector<int> pre, suf;

void erase(int p) {
	pre[suf[p]] = pre[p];
	suf[pre[p]] = suf[p];
}

void work(int l, int r, bool flg = true) {
	seq.emplace_back(l - fen.query(l), r - fen.query(r));
	if (flg) {
		remove(l - 1, s[l]);
		remove(r, s[r]);
	}
	for (int i = l; i <= r; i = suf[i]) {
		erase(i);
		fen.add(i, 1);
	}
}

void solve() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		s[i] -= 'a';
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i + 1]) {
			insert(i, s[i]);
		}
	}
	pre.resize(n + 2);
	suf.resize(n + 2);
	fen.init(n);
	pre[0] = 0, suf[0] = 1;
	pre[n + 1] = n, suf[n + 1] = n + 1;
	for (int i = 1; i <= n; i++) {
		pre[i] = i - 1;
		suf[i] = i + 1;
	}
	
	while (true) {
		int mxc = 0;
		for (int c = 1; c < 26; c++) {
			if (cnt[c] > cnt[mxc]) {
				mxc = c;
			}
		}
		if (G[mxc].empty()) {
			break;
		}
		auto x = *G[mxc].begin();
		work(x.first + 1, x.second);
	}

	int ls = 1;
	for (auto par : Sp) {
		int a = par.first;
		work(ls, a, false);
		ls = ++a;
	}
	work(ls, pre[n + 1], false);

	printf("%d\n", (signed) seq.size());
	for (auto x : seq) {
		printf("%d %d\n", x.first, x.second);
	}
	
	memset(cnt, 0, sizeof(cnt));
	Sp.clear();
	seq.clear();
	for (int i = 0; i < 26; i++) {
		G[i].clear();
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}