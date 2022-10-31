#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

vector<int> sqrtSort(const vector<pair<int, int> > &q, const int S) {
	int n = q.size();
	vector<pair<pair<int,int>,int>> list(n);
	for(int i = 0; i < n; i ++) {
		int b = q[i].first / S;
		list[i] = make_pair(make_pair(b, b % 2 == 0 ? q[i].second : -q[i].second), i);
	}
	sort(list.begin(), list.end());
	vector<int> res(n);
	for(int i = 0; i < n; i ++)
		res[i] = list[i].second;
	return res;
}

class LinkedList {
public:
	struct Node {
		int prev;
		int next;
	};

	class Iterator : std::iterator<input_iterator_tag, int> {
		friend class LinkedList;
		Iterator(int i, const LinkedList *list) : i(i), list(list) {}
	public:
		Iterator() : i(-1), list(nullptr) {}

		bool operator!=(Iterator that) { return i != that.i; }
		int operator*() const { return i; }
		Iterator &operator++() { i = list->nodes[i].next; return *this; }

		int i;
		const LinkedList * const list;
	};

	void init(int n) {
		nodes.assign(n + 1, Node{ -1, -1 });
		nodes[n].prev = nodes[n].next = n;
	}

	Iterator begin() const { return Iterator(nodes.back().next, this); }
	Iterator end() const { return Iterator((int)nodes.size() - 1, this); }

	bool isPresent(int i) const {
		return nodes[i].next != -1;
	}

	void insertAfter(int i, int p) {
		assert(!isPresent(i) && isPresent(p));
		int pn = nodes[p].next;
		nodes[i] = { p, pn };
		nodes[p].next = i;
		nodes[pn].prev = i;
	}

	void insertBefore(int i, int n) {
		assert(!isPresent(i) && isPresent(n));
		int np = nodes[n].prev;
		nodes[i] = { np, n };
		nodes[n].prev = i;
		nodes[np].next = i;
	}

	void movePosition(int i, int j) {
		assert(isPresent(i) && !isPresent(j));
		Node &ni = nodes[i];
		int ip = ni.prev, in = ni.next;
		nodes[j] = { ip, in };
		nodes[ip].next = j;
		nodes[in].prev = j;
		ni.prev = ni.next = -1;
	}

	void remove(int i) {
		assert(isPresent(i));
		Node &ni = nodes[i];
		int ip = ni.prev, in = ni.next;
		nodes[ip].next = in;
		nodes[in].prev = ip;
		ni.prev = ni.next = -1;
	}


private:
	vector<Node> nodes;
};

template<typename Val>
class Queue {
public:
	void init(int n) {
		v.resize(n);
		clear();
	}

	void init(int n, const Val &x) {
		v.assign(n, x);
		clear();
	}

	void clear() {
		h = t = 0;
	}

	bool empty() const { return h == t; }
	int size() const { return t - h; }

	void push(const Val &x) {
		v[t ++] = x;
	}

	Val &front() {
		return v[h];
	}

	Val &operator[](int i) {
		return v[h + i];
	}

	Val &pop() {
		return v[h ++];
	}

	Val *begin() { return v.begin() + h; }
	Val *end() { return v.begin() + t; }

	vector<Val> v;
	int h, t;
};

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]), -- a[i];
		int X = *max_element(a.begin(), a.end()) + 1;
		int q;
		scanf("%d", &q);
		vpii queries(q);
		rep(i, q) {
			int l; int r;
			scanf("%d%d", &l, &r), -- l, -- r;
			queries[i] = { l, r };
		}
		vi ord = sqrtSort(queries, 300);

		vector<int> freq(X, 0);
		vector<int> freqCnt(n + 1, 0);
		LinkedList list;
		list.init(n + 1);
		freqCnt[0] = X;
		list.insertBefore(0, *list.end());

		auto add = [&](int i, int sign) {
			int f = freq[a[i]] += sign;
			int x = -- freqCnt[f - sign];
			int y = ++ freqCnt[f];
			if(x == 0 && y == 1) {
				list.movePosition(f - sign, f);
			} else if(y == 1) {
				if(sign == 1)
					list.insertAfter(f, f - 1);
				else
					list.insertBefore(f, f + 1);
			} else if(x == 0) {
				list.remove(f - sign);
			}
		};

		vector<int> ans(q, -1);
		Queue<pair<int,int>> que[2];
		rep(k, 2)
			que[k].init(X + 2, make_pair(INF, 0));
		int L = 0, R = -1;
		for(int qi : ord) {
			int qL = queries[qi].first, qR = queries[qi].second;
			while(R < qR)
				add(++ R, +1);
			while(L > qL)
				add(-- L, +1);
			while(R > qR)
				add(R --, -1);
			while(L < qL)
				add(L ++, -1);

			int cnt = 0;
			for(auto it = list.begin(); it != list.end(); ++ it)
				++ cnt;
			for(int f : list) if(f > 0)
				que[0].push({ f, freqCnt[f] });
			int cost = 0;
			while(1) {
				int k = que[0][0].first <= que[1][0].first ? 0 : 1;
				auto &x = que[k][0];
				if(x.second >= 2) {
					cost += (x.second / 2) * (x.first * 2);
					que[1].push({ x.first * 2, x.second / 2 });
					if((x.second %= 2) == 0) {
						que[k].pop();
						continue;
					}
				}
				int l = que[k][1].first <= que[1 - k][0].first ? k : 1 - k;
				auto &y = l == k ? que[k][1] : que[1 - k][0];
				if(x.first == y.first) {
					assert(x.first != INF);
					y.second += x.second;
					que[k].pop();
					continue;
				}
				if(y.first == INF) break;
				cost += x.first + y.first;
				que[1].push({ x.first + y.first, 1 });
				que[k].pop();
				if(-- y.second == 0)
					que[l].pop();
			}
			rep(k, 2) {
				rep(i, que[k].t)
					que[k].v[i] = make_pair(INF, 0);
				que[k].clear();
			}
			ans[qi] = cost;
		}
		for(int i = 0; i < q; ++ i)
			printf("%d\n", ans[i]);
	}
	return 0;
}