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

struct Node
{
	Range range;
	Node* left_child;
	Node* right_child;

	int w=0;
	int d=0;

	void init(Range _range)
	{
		range = _range;
		w=d=0;
	}
	void pop()
	{
		if (range.s == range.t) { assert(left_child == nullptr && right_child == nullptr); return; }
		assert(left_child != nullptr && right_child != nullptr);
		const Node& l = *left_child;
		const Node& r = *right_child;
		w=min(l.w,r.w)+d;
	}
	void push()
	{
		if (d==0) return;
		if (range.s == range.t) return;
		assert(left_child != nullptr && right_child != nullptr);
		Node& l = *left_child;
		Node& r = *right_child;
		// TODO : push node.info to children's info.
		l.d+=d; l.w+=d;
		r.d+=d; r.w+=d;
		d=0;
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

struct Query
{
	int s;
	int t;
	int ret;
};
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,nq;
	while (cin>>n>>nq)
	{
		VI a(n);
		REP(i,n) { cin>>a[i]; --a[i]; }
		vector<Query> q(nq);
		REP(i,nq) { cin>>q[i].s>>q[i].t; q[i].t=n-q[i].t; }
		vector<vector<Query*>> g(n);
		REP(i,nq) g[q[i].s].push_back(&q[i]);

		VI b(n);
		REP(i,n) a[i]=i-a[i];
		REP(i,n) if (a[i]<0) a[i]=n+1;
		VI que;

		IntervalTree tree;
		tree.build(0,n-1);

		auto update_a=[&](int p,int new_val) {
			tree.traverse(Range(p, p), [&](Node* node) { if (node->size()==1) node->d=0,node->w=new_val; });
			assert(tree.root->w>=0);
		};

		VI sb(n+1);
		auto set_b=[&](int p) {
			assert(!b[p]);
			b[p]=1;
			que.push_back(p);
			for (int i=p+1;i<=n;i=(i|(i-1))+1) sb[i]++;
			update_a(p,n+1);
		};
		auto get_b=[&](int p) {
			int s=0;
			for (int i=p+1;i>0;i&=(i-1)) s+=sb[i];
			return s;
		};

		REP(i,n) update_a(i,a[i]);

		for (int s=n-1;s>=0;s--)
		{
			if (a[s]==0) set_b(s);
			while (!que.empty())
			{
				int pos=que.back();
				que.pop_back();
				if (pos+1<=n-1)
				{
					tree.traverse(Range(pos+1,n-1), [&](Node* node) { --node->d; --node->w; });
					assert(tree.root->w>=0);
					while (1)
					{
						Node* p=tree.find_first(Range(pos+1,n-1), [&](Node* node) { return node->w==0; });
						if (p==nullptr) break;
						set_b(p->range.s);
						assert(tree.root->w>=0);
					}
				}
				// FOR(i,pos+1,n) if ((--a[i])==0) set_b(i);
			}
			for (Query* q:g[s]) q->ret=get_b(q->t-1);
		}
		REP(i,nq) printf("%d\n",q[i].ret);
#ifndef _MSC_VER
		break;
#endif
		printf("\n");
	}
	return 0;
}