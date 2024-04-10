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

int64 gcd(int64 a, int64 b) 
{
	return b == 0 ? a : gcd(b, a % b);
}

struct Node
{
	Range range;
	Node* left_child;
	Node* right_child;

	// Data
	int count;
	int64 min_v;
	int64 max_v;
	int64 ret;

	void init(Range _range)
	{
		range = _range;
		// TODO : initialize the node.
		count = 0;
		ret = 0;
	}
	void pop()
	{
		if (range.s == range.t) { assert(left_child == nullptr && right_child == nullptr); return; }
		assert(left_child != nullptr && right_child != nullptr);
		const Node& l = *left_child;
		const Node& r = *right_child;
		// TODO : update node.info based on children's info.

		count = l.count + r.count;
		if (count == 0) {
			ret = 0;
		} else if (r.count == 0) {
			count = l.count;
			min_v = l.min_v;
			max_v = l.max_v;
			ret = l.ret;
		} else if (l.count == 0) {
			count = r.count;
			min_v = r.min_v;
			max_v = r.max_v;
			ret = r.ret;			
		} else {
			ret = gcd(l.ret, r.ret);
			min_v = l.min_v;
			max_v = r.max_v;
			ret = gcd(gcd(l.ret, r.ret), r.min_v - l.max_v);
		}
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

void solve()
{
	int n;
	cin>>n;
	vector<int64> a(n);
	REP(i,n) cin>>a[i];
	vector<int64> b=a;
	sort(ALL(b));
	unordered_map<int64,int> mp;
	REP(i,n) mp[b[i]]=i;

	int ret=0;
	IntervalTree tree;
	tree.build(0,n-1);

	auto update=[&](int idx,int add) {
		int64 val=a[idx];
		int p=mp[val];
		tree.traverse(Range(p,p),[&](Node* p) {
			if (p->size()==1)
				if (add)
				{
					p->count=1;
					p->min_v=p->max_v=val;
					p->ret=0;
				}
				else
					p->count=0;
		});
	};
	int j=0;
	REP(i,n)
	{
		for (;j<n;j++)
		{
			update(j,1);
			if (tree.root->ret==1) break;
		}
		ckmax(ret,j-i);
		if (j==n) break;
		update(i,0);
	}
	printf("%d\n",ret);
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		solve();
	}
	return 0;
}