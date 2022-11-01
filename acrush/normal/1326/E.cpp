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
	int sum = 0;
	int min_prefix_sum = 0;

	void init(Range _range)
	{
		range = _range;
		// TODO : initialize the node.
		sum = min_prefix_sum = 0;
	}
	void pop()
	{
		if (range.s == range.t) { assert(left_child == nullptr && right_child == nullptr); return; }
		assert(left_child != nullptr && right_child != nullptr);
		const Node& l = *left_child;
		const Node& r = *right_child;
		// TODO : update node.info based on children's info.
		sum = l.sum + r.sum;
		min_prefix_sum = min(l.min_prefix_sum, l.sum + r.min_prefix_sum);
	}
	void push()
	{
		if (range.s == range.t) return;
		assert(left_child != nullptr && right_child != nullptr);
		Node& l = *left_child;
		Node& r = *right_child;
		// TODO : push node.info to children's info.
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

	template<class Func>
	Node* find_first(const Range& range, Func func)
	{
		return find_first_internal(range, func, 0);
	}

	template<class Func>
	Node* find_last(const Range& range, Func func)
	{
		return find_first_internal(range, func, 1);
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

	template<class Func>
	Node* find_first_internal(const Range& range, Func func, int reverse_order)
	{
		assert(root != nullptr);
		if (!range.has_overlap(root->range)) return nullptr;
		return find_first_nodes_internal(root, range, func, reverse_order);
	}

	template<class Func>
	Node* find_first_nodes_internal(Node* p, const Range& range, Func func, int reverse_order)
	{
		if (range.is_contain(p->range)) return find_first_nodes_knowly_internal(p, func, reverse_order);
		p->push();
		int m = p->mid();
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
		if (!func(p)) return nullptr;
		if (p->range.s == p->range.t) return p;
		p->push();
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
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		VI a(n), q(n);
		REP(i, n) { cin >> a[i]; --a[i]; }
		REP(i, n) { cin >> q[i]; --q[i]; }
		VI p(n);
		REP(i, n) p[a[i]] = i;
		int ret = n - 1;
		VI d(n);
		IntervalTree tree;
		tree.build(0, n - 1);
		auto query = [&](int s, int t) {
			int sum = 0;
			int prefix = 0;
			tree.traverse(Range(s, t), [&](Node* node) {
				prefix = min(prefix, sum + node->min_prefix_sum);
				sum += node->sum;
			});
			return MP(sum, prefix);
		};
		auto ck = [&](int at)
		{
			ipair w = query(0, at - 1);
			int s = w.first - w.second;
			ipair p = query(at, n - 1);
			return s + p.second >= 0;
		};
		auto update = [&](int at, int delta) {
			tree.traverse(Range(at, at), [&](Node* node) {
				node->sum += delta;
				node->min_prefix_sum = min(0, node->sum);
			});
		};
		REP(i, n)
		{
			for (; ret > 0 && !ck(p[ret]); ret--)
			{
				d[p[ret]]++;
				update(p[ret], 1);
			}
			d[q[i]]--;
			update(q[i], -1);
			printf("%d ", ret + 1);
		}
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}