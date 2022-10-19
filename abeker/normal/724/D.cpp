#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int offset = 1 << 17;

struct node {
	int sol, len, pref, suff;
	node(int sol, int len, int pref, int suff) : sol(sol), len(len), pref(pref), suff(suff) {}
	node() : sol(0), len(0), pref(0), suff(0) {}
};

int N, M;
char s[MAXN];
vector <int> pos[30];
node t[2 * offset];

void load() {
	scanf("%d%s", &M, s);
}

node merge(node l, node r) {
	node n;
	n.sol = max(l.suff + r.pref, max(l.sol, r.sol));
	n.len = l.len + r.len;
	n.pref = l.pref == l.len ? l.len + r.pref : l.pref;
	n.suff = r.suff == r.len ? r.len + l.suff : r.suff;
	return n;
}

void update(int x) {
	x += offset;
	t[x] = node(0, 1, 0, 0);
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from) return node();
	if (lo >= from && hi <= to) return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int query(int from, int to) {
	return query(1, 0, offset, from, to).sol;
}

string solve() {
	N = strlen(s);
	for (int i = 0; i < N; i++)
		pos[s[i] - 'a'].push_back(i);
	
	for (int i = 0; i < N; i++)
		t[i + offset] = node(1, 1, 1, 1);
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
	
	for (int i = 0; i < 26; i++) {
		pos[i].push_back(N);
		for (int j = 0; j < (int)pos[i].size() - 1; j++)
			if (query(0, pos[i][j + 1]) >= M) 
				update(pos[i][j]);
		if (query(0, N) < M) break;
		for (int j = 0; j < (int)pos[i].size() - 1; j++)
			update(pos[i][j]);
	}
	
	string ans = "";
	for (int i = 0; i < N; i++)
		if (!t[i + offset].sol)
			ans += s[i];
			
	sort(ans.begin(), ans.end());
	
	return ans;
}

int main() {
	load();
	puts(solve().c_str());
	return 0;
}