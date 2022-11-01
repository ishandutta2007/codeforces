#include<bits/stdc++.h>
using namespace std;
int read() {	
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int m;
struct node {
	int ls, rs;
	int tag, maxn, pl;
}nd[2000001];
int cnt;
struct SGT {
	int rt;
	static void pushdown(int p) {
		if (!nd[p].tag) return;
		if (nd[p].ls) {
			int tmp = nd[p].ls;
			nd[p].ls = ++cnt;
			nd[nd[p].ls] = nd[tmp];
			nd[nd[p].ls].tag = 1;
		}
		if (nd[p].rs) {
			int tmp = nd[p].rs;
			nd[p].rs = ++cnt;
			nd[nd[p].rs] = nd[tmp];
			nd[nd[p].rs].tag = 1;
		}
		nd[p].tag = 0;
	}
	static void update(int p) {
		nd[p].maxn = max(nd[nd[p].ls].maxn, nd[nd[p].rs].maxn);
		if (nd[p].maxn == nd[nd[p].ls].maxn) nd[p].pl = nd[nd[p].ls].pl;
		else nd[p].pl = nd[nd[p].rs].pl;
	}
	static void insert(int &p, int l, int r, int x) {
		if (!p) p = ++cnt;
		if (l == r) {
			++nd[p].maxn, nd[p].pl = l;
			return;
		}
		if (l == r) return;
		int mid = (l + r) / 2;
		if (x <= mid) insert(nd[p].ls, l, mid, x);
		else insert(nd[p].rs, mid + 1, r, x);
		update(p);
	}
	static pair<int, int> query(int p, int l, int r, int l0, int r0) {
		if (!p) return make_pair(0, max(l, l0));
		pushdown(p);
		if (l >= l0 && r <= r0) return make_pair(nd[p].maxn, nd[p].pl);
		int mid = (l + r) / 2;
		pair<int, int> ans = make_pair(0, l0);
		if (l0 <= mid) {
			pair<int, int> tmp = query(nd[p].ls, l, mid, l0, r0);
			if (tmp.first > ans.first) ans = tmp;
		}
		if (r0 > mid) {
			pair<int, int> tmp = query(nd[p].rs, mid + 1, r, l0, r0);
			if (tmp.first > ans.first) ans = tmp;
		}
		return ans;
	}
	static void merge(int &p1, int p2, int l, int r) {
		if (!p2) return;
		if (!p1) {
			p1 = ++cnt;
			nd[p1] = nd[p2];
			nd[p1].tag = 1;
			return;
		}
		if (l == r) {
			nd[p1].maxn += nd[p2].maxn;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(p1), pushdown(p2);
		merge(nd[p1].ls, nd[p2].ls, l, mid), merge(nd[p1].rs, nd[p2].rs, mid + 1, r);
		update(p1);
	}
	void query(int l, int r) {
		pair<int, int> ans = query(rt, 1, m, l, r);
		write(ans.second), putchar(' '), write(ans.first), putchar('\n');
	}
	void insert(int x) {
		insert(rt, 1, m, x);
	}
};
void merge(SGT &p1, SGT &p2) {
	p1.merge(p1.rt, p2.rt, 1, m);
}
struct SAM {
	struct node {
		int fa, ch[26];
		int len, rt;
		vector<int> son;
		SGT sgt;
	}nd[100001];
	int id[50001], cnt;
	int f[100001][20];
	void insert(int last, int now, SGT sgt, int c) {
		int p = id[last], u = ++cnt;
		nd[u].len = nd[p].len + 1;
		nd[u].sgt = sgt;
		id[now] = cnt;
		while (p && !nd[p].ch[c]) nd[p].ch[c] = u, p = nd[p].fa;
		if (!nd[p].ch[c]) {
			nd[p].ch[c] = u;
			return;
		}
		int v = nd[p].ch[c];
		if (nd[v].len == nd[p].len + 1) {
			nd[u].fa = v;
			return;
		}
		int q = ++cnt;
		nd[q] = nd[v], nd[q].len = nd[p].len + 1, nd[q].sgt.rt = 0;
		nd[u].fa = nd[v].fa = q;
		while (nd[p].ch[c] == v) nd[p].ch[c] = q, p = nd[p].fa;
	}
	void init() {
		for (int i = 1; i <= cnt; i++)
			nd[nd[i].fa].son.push_back(i), f[i][0] = nd[i].fa;
		for (int j = 1; j < 20; j++)
			for (int i = 1; i <= cnt; i++)
				f[i][j] = f[f[i][j-1]][j-1];
	}
	void build(int x) {
		for (int i = 0; i < nd[x].son.size(); i++)
			build(nd[x].son[i]), merge(nd[x].sgt, nd[nd[x].son[i]].sgt);
	}
	int up(int x, int len) {
		for (int i = 19; i >= 0; i--)
			if (nd[f[x][i]].len >= len) x = f[x][i];
		return x;
	}
}sam;
struct Trie {
	int ch[50001][26], cnt;
	SGT sgt[50001];
	void insert(string t, int id) {
		int p = 0;
		sgt[0].insert(id);
		for (int i = 0; i < t.size(); i++) {	
			int c=t[i]-'a';
			if (!ch[p][c]) ch[p][c] = ++cnt;
			p = ch[p][c], sgt[p].insert(id);
		}
	}
	void getsam() {
		queue<int> q;
		q.push(0);
		while (q.size()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < 26; i++)
				if (ch[u][i]) {
					sam.insert(u, ch[u][i], sgt[ch[u][i]], i);
					q.push(ch[u][i]);
				}
		}
		sam.init(), sam.build(0);
	}
}trie;
int st[500001], ed[500001];
int main() {
	string s;
	cin >> s >> m;
	for (int i = 1; i <= m; i++) {
		string t;
		cin >> t;
		trie.insert(t, i);
	}
	trie.getsam();
	st[0] = 0;
	for (int i = 1; i <= s.size(); i++) {
		int p = ed[i-1];
		st[i] = st[i-1];
		while (p && !sam.nd[p].ch[s[i-1]-'a']) p = sam.nd[p].fa, st[i] = sam.nd[p].len;
		if (sam.nd[p].ch[s[i-1]-'a']) ++st[i];
		ed[i] = sam.nd[p].ch[s[i-1]-'a'];
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int l = read(), r = read(), pl = read(), pr = read();
		if (st[pr] < pr - pl + 1) {
			write(l), putchar(' '), write(0), putchar('\n');
			continue;
		}
		int u = sam.up(ed[pr], pr - pl + 1);
		sam.nd[u].sgt.query(l, r);
	}
}