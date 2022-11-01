#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;

class UnionFind {
 public:
  UnionFind(int n) {
	  groups_ = std::vector<int>(n, -1);
  }

  int Find(int p) {
	  int r = p;
	  while (groups_[r] >= 0) r = groups_[r];
	  int t = groups_[p];
	  while (t >= 0) {
		groups_[p] = r;
		p = t;
		t = groups_[p];
	  }
	  return r;
  }

  std::vector<int> groups_;
};

struct Query
{
    int tp;
    int key;
    int ret;
};
struct Edge
{
    int u;
    int v;
};

struct Range
{
	int s = 0;
	int t = -1;
	Range() = default;
	Range(int s, int t) : s(s), t(t) { }

	int size() const { return t - s + 1; }
	bool has_overlap(const Range& other_range) const { return s <= other_range.t && t >= other_range.s; }
	bool is_contain(const Range& other_range) const { return s <= other_range.s && t >= other_range.t; }
};

struct Node
{
	Range range;
	Node* left_child;
	Node* right_child;

	// Data
	ipair max_val;

	void init(Range _range)
	{
		range = _range;
		max_val = MP(0, range.s);
	}
	void pop()
	{
		if (range.s == range.t) { assert(left_child == nullptr && right_child == nullptr); return; }
		assert(left_child != nullptr && right_child != nullptr);
		const Node& l = *left_child;
		const Node& r = *right_child;
		max_val = max(l.max_val, r.max_val);
	}
	void push()
	{
	}

	int size() const { return range.size(); }
	int mid() const { return (range.s + range.t) / 2; }
};

class IntervalTree
{
public:
	void build(int min_idx, int max_idx)
	{
		assert(min_idx <= max_idx);
		int size = max_idx - min_idx + 1;
		for (; size & (size - 1); size += (size & (-size)));
		reset_buffer(size * 2);
		root = build_internal(min_idx, max_idx);
	}

	template<class Func>
	void traverse(const Range& range, Func func)
	{
		traverse_internal(range, func, 0);
	}

	template<class Func>
	void traverse_in_reverse_order(const Range& range, Func func)
	{
		traverse_internal(range, func, 1);
	}

	Node* root;

private:
	template<class Func>
	void traverse_internal(const Range& range, Func func, int reverse_order)
	{
		assert(root != nullptr);
		if (!range.has_overlap(root->range)) return;
		traverse_nodes_internal(root, range, func, reverse_order);
	}

	template<class Func>
	void traverse_nodes_internal(Node* p, const Range& range, Func func, int reverse_order)
	{
		if (range.is_contain(p->range)) { func(p); return; }
		p->push();
		int m = p->mid();
		if (reverse_order) 
		{
			if (m < range.t) traverse_nodes_internal(p->right_child, range, func, reverse_order);
			if (m >= range.s) traverse_nodes_internal(p->left_child, range, func, reverse_order);
		}
		else
		{
			if (m >= range.s) traverse_nodes_internal(p->left_child, range, func, reverse_order);
			if (m < range.t) traverse_nodes_internal(p->right_child, range, func, reverse_order);
		}
		p->pop();
	}

	Node* build_internal(int min_idx, int max_idx)
	{
		assert(buffer_pos < buffer.size());
		Node* p = &buffer[buffer_pos++];
		p->init(Range(min_idx, max_idx));
		if (min_idx == max_idx)
			p->left_child = p->right_child = nullptr;
		else
		{
			int m = (min_idx + max_idx) / 2;
			p->left_child = build_internal(min_idx, m);
			p->right_child = build_internal(m + 1, max_idx);
			p->pop();
		}
		return p;
	}

	void reset_buffer(int size)
	{
		buffer_pos = 0;
		buffer.clear();
		buffer.resize(size);
	}

	vector<Node> buffer;
	int buffer_pos;
};


int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
    int n,m,nq;
    cin>>n>>m>>nq;
    VI val(n+m);
    REP(i,n) cin>>val[i];
    vector<Edge> e(m);
    REP(i,m) { cin>>e[i].u>>e[i].v; --e[i].u; --e[i].v; }
    vector<Query> q(nq);
    REP(i,nq) { cin>>q[i].tp>>q[i].key; --q[i].key; }
    VI deleted(m);
    REP(i,nq) if (q[i].tp==2) deleted[q[i].key]=1;
    UnionFind uf(n+m);
    int next_id=n;
    vector<VI> g(n+m);
    auto add=[&](int a,int b) {
        a=uf.Find(a);
        b=uf.Find(b);
        if (a==b) return;
        int c=(next_id++);
        uf.groups_[a]=uf.groups_[b]=c;
        g[c].push_back(a);
        g[c].push_back(b);
    };
    REP(i,m) if (!deleted[i]) add(e[i].u,e[i].v);
    for (int i=nq-1;i>=0;i--)
        if (q[i].tp==2)
            add(e[q[i].key].u,e[q[i].key].v);
        else
            q[i].key=uf.Find(q[i].key);
    VI que;
    VI idx(n+m,-1);
    VI last(n+m);
    std::function<void(int)> dfs=[&](int p) {
        idx[p]=SIZE(que);
        que.push_back(p);
        for (int x:g[p]) dfs(x);
        last[p]=SIZE(que)-1;
    };
	VI indeg(n+m);
	REP(i,n+m) for (int j:g[i]) ++indeg[j];
    REP(i,n+m) if (indeg[i]==0) dfs(i);
    VI a(n+m);
    REP(i,SIZE(que)) a[i]=val[que[i]];

	IntervalTree tree;
	tree.build(0,n+m-1);
	auto update=[&](int at,int val) {
		a[at]=val;
		tree.traverse(Range(at,at),[&](Node* node) { if (node->range.size()==1) node->max_val=MP(val,at); });
	};
	REP(i,n+m) update(i,a[i]);

    REP(k,nq)
        if (q[k].tp==1)
        {
            int s=idx[q[k].key];
            int t=last[q[k].key];
			ipair ret=MP(-1,-1);
			tree.traverse(Range(s,t),[&](Node* node) { ret=max(ret,node->max_val); });
			printf("%d\n",ret.first);
			int key=ret.second;
			update(key,0);
			/*
            int key=-1;
            FOR(i,s,t+1) if (key<0 || a[i]>a[key]) key=i;
            printf("%d\n",a[key]);
            a[key]=0;
			*/
        }
	return 0;
}