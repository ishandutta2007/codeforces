# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
const int MAXS = 1000051;
int n, m;
char s[MAXS];
struct SegTree{
	struct Node{
		int tag;
		Node *ls, *rs;
	} pool[MAXS * 4];
	int tsz, sz;
	Node *rt;
	Node* modify(Node *nw, int lft, int rgt, int l, int r, int nm){
		if (!nw) nw = pool + (++tsz);
		// printf("modify %d %d %d\n", nw - pool, l, r);
		if (lft == l && rgt == r){
			nw -> tag += nm;
			return nw;
		}
		int mid = (lft + rgt) >> 1;
		if (l <= mid) nw -> ls = modify(nw -> ls, lft, mid, l, min(mid, r), nm);
		if (r >= mid + 1) nw -> rs = modify(nw -> rs, mid + 1, rgt, max(mid + 1, l), r, nm);
		return nw;
	}
	int getnm(Node *nw, int lft, int rgt, int pos){
		if (!nw) return 0;
		if (lft == rgt) return nw -> tag;
		int mid = (lft + rgt) >> 1;
		if (pos <= mid) return getnm(nw -> ls, lft, mid, pos) + nw -> tag;
		else return getnm(nw -> rs, mid + 1, rgt, pos) + nw -> tag;
	}
	void modify(int l, int r, int nm){
		rt = modify(rt, 1, sz, l, r, nm);
	}
	int getnm(int pos){
		return getnm(rt, 1, sz, pos);
	}
};
struct ACTree{
	struct Node{
		int id;
		bool ed;
		Node *fail;
		Node *ch[26];
	} pool[MAXS];
	struct Edge{
		int t, nxt;
		Edge(){}
		Edge(int t, int nxt): t(t), nxt(nxt){}
	} g[MAXS * 2];
	int tsz, gsz, cnt;
	int fte[MAXS], dfn[MAXS], sz[MAXS];
	Node *rt1, *rt2;
	Node *pos[MAXN];
	SegTree sgt;
	void addedge(int u, int v){
		g[++gsz] = Edge(v, fte[u]);
		fte[u] = gsz;
	}
	void dfs(int nw){
		dfn[nw] = ++cnt;
		sz[nw] = 1;
		for (int i = fte[nw]; i; i = g[i].nxt){
			int nxtn = g[i].t;
			dfs(nxtn);
			sz[nw] += sz[nxtn];
		}
	}
	Node* newnode(){
		tsz++;
		pool[tsz].id = tsz;
		return pool + tsz;
	}
	void build(char s[], int sz, int id){
		Node *nw = rt2;
		for (int i = 1; i <= sz; i++){
			if (!nw -> ch[s[i] - 'a']) nw -> ch[s[i] - 'a'] = newnode();
			nw = nw -> ch[s[i] - 'a'];
			// printf("build %d\n", nw -> id);
		}
		pos[id] = nw;
	}
	void getfail(){
		for (int i = 0; i < 26; i++) rt1 -> ch[i] = rt2;
		rt1 -> fail = rt2 -> fail = rt1;
		queue <Node*> q;
		q.push(rt2);
		while (!q.empty()){
			Node *nw = q.front();
			q.pop();
			for (int i = 0; i < 26; i++){
				if (nw -> ch[i]){
					Node *nxtn = nw -> ch[i];
					nxtn -> fail = nw -> fail -> ch[i];
					addedge(nxtn -> fail -> id, nxtn -> id);
					q.push(nxtn);
				} else nw -> ch[i] = nw -> fail -> ch[i];
			}
		}
	}
	void add(int id){
		// printf("add %d\n", id);
		if (pos[id] -> ed) return;
		sgt.modify(dfn[pos[id] -> id], dfn[pos[id] -> id] + sz[pos[id] -> id] - 1, 1);
		pos[id] -> ed = true;
	}
	void del(int id){
		if (!pos[id] -> ed) return;
		sgt.modify(dfn[pos[id] -> id], dfn[pos[id] -> id] + sz[pos[id] -> id] - 1, -1);
		pos[id] -> ed = false;
	}
	int find(char s[], int sz){
		Node *nw = rt2;
		int ans = 0;
		for (int i = 1; i <= sz; i++){
			nw = nw -> ch[s[i] - 'a'];
			ans += sgt.getnm(dfn[nw -> id]);
		}
		return ans;
	}
} act;
int main(){
	act.rt1 = act.newnode();
	act.rt2 = act.newnode();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		scanf("%s", s + 1);
		int sz = strlen(s + 1);
		act.build(s, sz, i);
	}
	act.getfail();
	act.dfs(act.rt2 -> id);
	act.sgt.sz = act.tsz;
	for (int i = 1; i <= m; i++) act.add(i);
	for (int i = 1; i <= n; i++){
		char op;
		int x;
		scanf(" %c", &op);
		if (op == '+'){
			scanf("%d", &x);
			act.add(x);
		} else if (op == '-'){
			scanf("%d", &x);
			act.del(x);
		} else {
			scanf("%s", s + 1);
			int sz = strlen(s + 1);
			printf("%d\n", act.find(s, sz));
		}
	}
	return 0;
}