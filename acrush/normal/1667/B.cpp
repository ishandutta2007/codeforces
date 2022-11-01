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

	// Data
	int max_val;

	void init(Range _range)
	{
		range = _range;
		max_val = -1e9;
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
		if (range.s == range.t) return;
		assert(left_child != nullptr && right_child != nullptr);
		Node& l = *left_child;
		Node& r = *right_child;
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


void solve()
{
	int n;
	cin>>n;
	VI a(n);
	REP(i,n) cin>>a[i];
	vector<int64> s(n+1);
	REP(i,n) s[i+1]=s[i]+a[i];
	set<int64> ss(ALL(s));
	vector<int64> vals(ALL(ss));
	map<int64,int> ms;
	int m=SIZE(vals);
	REP(i,m) ms[vals[i]]=i;
	REP(i,n+1) s[i]=ms[s[i]];
	VI f(n+1);
	VI f1(n+1);
	VI f2(n+1);

	IntervalTree tree;
	tree.build(0,m*3-1);
	tree.traverse(Range(s[0],s[0]),[&](Node* node) { ckmax(node->max_val,f[0]); });
	tree.traverse(Range(m+s[0],m+s[0]),[&](Node* node) { ckmax(node->max_val,f1[0]); });
	tree.traverse(Range(m*2+s[0],m*2+s[0]),[&](Node* node) { ckmax(node->max_val,f2[0]); });

	FOR(i,1,n+1)
	{
		f[i]=-1e9;

		tree.traverse(Range(s[i],s[i]),[&](Node* node) { ckmax(f[i],node->max_val); });
		tree.traverse(Range(m*2,m*2+s[i]-1),[&](Node* node) { ckmax(f[i],node->max_val+i); });
		tree.traverse(Range(m+s[i]+1,m+(m-1)),[&](Node* node) { ckmax(f[i],node->max_val-i); });
		/*
		REP(j,i)
			if (s[i]==s[j])
				ckmax(f[i],f[j]);
			else if (s[i]>s[j])
				ckmax(f[i],f2[j]+i);
			else
				ckmax(f[i],f1[j]-i);
		*/

		f1[i]=f[i]+i;
		f2[i]=f[i]-i;
		tree.traverse(Range(s[i],s[i]),[&](Node* node) { ckmax(node->max_val,f[i]); });
		tree.traverse(Range(m+s[i],m+s[i]),[&](Node* node) { ckmax(node->max_val,f1[i]); });
		tree.traverse(Range(m*2+s[i],m*2+s[i]),[&](Node* node) { ckmax(node->max_val,f2[i]); });
	}
	printf("%d\n",f[n]);
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin>>t;t>0;--t) solve();
	return 0;
}