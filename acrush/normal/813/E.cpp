#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi = acos(-1.0);
const double eps = 1e-11;
template<class T> inline void ckmin(T& a, T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T& a, T b) { if (b > a) a = b; }
template<class T> inline T sqr(T x) { return x * x; }
typedef pair<int, int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI = vector<int>;

struct Range
{
	int64 s = 0;
	int64 t = -1;
	Range() = default;
	Range(int64 s, int64 t) : s(s), t(t) { }

	int64 size() const { return t - s + 1; }
	bool has_overlap(const Range& other_range) const { return s <= other_range.t && t >= other_range.s; }
	bool is_contain(const Range& other_range) const { return s <= other_range.s && t >= other_range.t; }
};

struct Node
{
	Range range;
	Node* left_child;
	Node* right_child;

	// Data
	int count;

	void init(Range _range)
	{
		range = _range;
		right_child = nullptr;
		left_child = nullptr;
		count = 0;
	}

	void pop()
	{
		if (range.s == range.t) { assert(left_child == nullptr && right_child == nullptr); return; }
		assert(left_child != nullptr && right_child != nullptr);
		const Node& l = *left_child;
		const Node& r = *right_child;
		count = l.count + r.count;
	}

	template<class Func>
	int push(Func new_func)
	{
		return 0;
	}

	int64 size() const { return range.size(); }
	int64 mid() const { return (range.s + range.t) / 2; }
};

class IntervalTree
{
public:
	void build(int min_idx, int max_idx)
	{
		assert(min_idx <= max_idx);
		reset_buffer();
		root = new_node();
		root->init(Range(min_idx, max_idx));
	}

	void build_all(int min_idx, int max_idx)
	{
		assert(min_idx <= max_idx);
		reset_buffer();
		build_all_internal(root, min_idx, max_idx);
	}

	template<class Func>
	void traverse(Node* root, const Range& range, Func func)
	{
		traverse_internal(root, range, func, 0);
	}

	template<class Func>
	void traverse_in_reverse_order(Node* root, const Range& range, Func func)
	{
		traverse_internal(root, range, func, 1);
	}

	template<class Func>
	Node* mutate_latest(const Range& range, Func func)
	{
		return root = mutate(root, range, func);
	}

	template<class Func>
	Node* mutate(Node* oldp, const Range& range, Func func)
	{
		Node* p;
		mutate_internal(p, oldp, range, func, 0);
		return p;
	}

	template<class Func>
	Node* mutate_latest_in_reverse_order(const Range& range, Func func)
	{
		return root = mutate_in_reverse_order(root, range, func);
	}

	template<class Func>
	Node* mutate_in_reverse_order(Node* oldp, const Range& range, Func func)
	{
		Node* p;
		mutate_internal(p, oldp, range, func, 1);
		return p;
	}

	template<class Func>
	Node* find_first(Node* p, const Range& range, Func func)
	{
		return find_first_internal(p, range, func, 0);
	}

	template<class Func>
	Node* find_last(Node* p, const Range& range, Func func)
	{
		return find_first_internal(p, range, func, 1);
	}

	Node* root;

private:
	void build_all_internal(Node* &p, int64 s, int64 t)
	{
		p = new_node();
		p->init(Range(s, t));
		if (s == t) 
			p->left_child = p->right_child = nullptr;
		else
		{
			int64 m = p->mid();
			build_all_internal(p->left_child, s, m);
			build_all_internal(p->right_child, m + 1, t);
		}
	}

	template<class Func>
	void traverse_internal(Node* p, const Range& range, Func func, int reverse_order)
	{
		assert(p != nullptr);
		if (!range.has_overlap(p->range)) return;
		traverse_nodes_internal(p, range, func, reverse_order);
	}

	template<class Func>
	void traverse_nodes_internal(Node* p, const Range& range, Func func, int reverse_order)
	{
		assert(p != nullptr);
		if (range.is_contain(p->range)) { func(p); return; }
		p->push([this]() { return new_node(); });
		int64 m = p->mid();
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

	template<class Func>
	void mutate_internal(Node* &p, const Node* oldp, const Range& range, Func func, int reverse_order)
	{
		assert(oldp != nullptr);
		p = new_node();
		*p = *oldp;
		if (range.is_contain(p->range)) { func(p); return; }
		int64 m = p->mid();
		if (p->push([this]() { return new_node(); }))
		{
			assert(p->left_child != nullptr && p->right_child != nullptr);
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
		}
		else
		{
			if (reverse_order)
			{
				if (m < range.t) mutate_internal(p->right_child, oldp->right_child, range, func, reverse_order);
				if (m >= range.s) mutate_internal(p->left_child, oldp->left_child, range, func, reverse_order);
			}
			else
			{
				if (m >= range.s) mutate_internal(p->left_child, oldp->left_child, range, func, reverse_order);
				if (m < range.t) mutate_internal(p->right_child, oldp->right_child, range, func, reverse_order);
			}
		}
		p->pop();
	}

	template<class Func>
	Node* find_first_internal(Node* p, const Range& range, Func func, int reverse_order)
	{
		assert(p != nullptr);
		if (!range.has_overlap(p->range)) return nullptr;
		return find_first_nodes_internal(p, range, func, reverse_order);
	}

	template<class Func>
	Node* find_first_nodes_internal(Node* p, const Range& range, Func func, int reverse_order)
	{
		assert(p != nullptr);
		if (range.is_contain(p->range)) return find_first_nodes_knowly_internal(p, func, reverse_order);
		p->push([this]() { return new_node(); });
		int64 m = p->mid();
		if (reverse_order) 
		{
			if (m < range.t) { Node* ret = find_first_nodes_internal(p->right_child, range, func, reverse_order); if (ret != nullptr) return ret; }
			if (m >= range.s) { Node* ret = find_first_nodes_internal(p->left_child, range, func, reverse_order); if (ret != nullptr) return ret; }
		}
		else
		{
			if (m >= range.s) { Node* ret = find_first_nodes_internal(p->left_child, range, func, reverse_order); if (ret != nullptr) return ret; }
			if (m < range.t) { Node* ret = find_first_nodes_internal(p->right_child, range, func, reverse_order); if (ret != nullptr) return ret; }
		}
		p->pop();
		return nullptr;
	}

	template<class Func>
	Node* find_first_nodes_knowly_internal(Node* p, Func func, int reverse_order)
	{
		assert(p != nullptr);
		if (!func(p)) return nullptr;
		if (p->range.s == p->range.t) return p;
		p->push([this]() { return new_node(); });
		if (reverse_order) 
		{
			Node* ret = find_first_nodes_knowly_internal(p->right_child, func, reverse_order); 
			if (ret != nullptr) return ret;
			ret = find_first_nodes_knowly_internal(p->left_child, func, reverse_order);
			if (ret != nullptr) return ret;
		}
		else
		{
			Node* ret = find_first_nodes_knowly_internal(p->left_child, func, reverse_order);
			if (ret != nullptr) return ret;
			ret = find_first_nodes_knowly_internal(p->right_child, func, reverse_order); 
			if (ret != nullptr) return ret;
		}
		p->pop();
		return nullptr;
	}

	Node* new_node()
	{
		if (buffer_pos == buffer.back().size())
		{
			buffer.push_back(vector<Node>(buffer_pos * 2));
			buffer_pos = 0;
		}
		return &buffer.back()[buffer_pos++];
	}

	void reset_buffer()
	{
		buffer_pos = 0;
		buffer.clear();
		buffer.push_back(vector<Node>(16));
	}

	vector<vector<Node>> buffer;
	int buffer_pos;
};

int main()
{
#ifdef _MSC_VER
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	VI a(n);
	REP(i,n) cin>>a[i];
	vector<VI> g(200000);
	REP(i,n) g[a[i]].push_back(i);
	VI p(n,n);
	for (const auto& x:g) REP(i,SIZE(x)-k) p[x[i]]=x[i+k];
	int nq;
	int last=0;
	IntervalTree tree;
	tree.build_all(0,n);
	vector<Node*> roots(n+1);
	roots[0]=tree.root;
	REP(i,n)
	{
		tree.mutate_latest(Range(p[i],p[i]),[](Node* p) { ++p->count; });
		roots[i+1]=tree.root;
	}
	for (cin>>nq;nq>0;nq--)
	{
		int l,r;
		cin>>l>>r;
		l=(l+last)%n+1;
		r=(r+last)%n+1;
		if (l>r) swap(l,r);
		--l;
		int ret=0;
		tree.traverse(roots[r], Range(r, n), [&](Node* p) { ret += p->count; });
		tree.traverse(roots[l], Range(r, n), [&](Node* p) { ret -= p->count; });
		printf("%d\n",ret);
		last=ret;
	}
	return 0;
}