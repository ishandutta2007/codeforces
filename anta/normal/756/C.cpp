#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int m;
	while (~scanf("%d", &m)) {
		int nNodes = 1;
		while (nNodes < m) nNodes *= 2;
		struct Node {
			int add;
			int minAdd;
			Node() : add(0), minAdd(0) {}
			explicit Node(int add) : add(add), minAdd(min(0, add)) {}
			Node operator+(const Node &that) const {
				Node res;
				res.add = add + that.add;
				res.minAdd = min(that.minAdd, that.add + minAdd);
				return res;
			}
		};
		vector<Node> nodes(nNodes * 2);
		vector<int> value(m, -1);
		rep(qi, m) {
			int p;
			scanf("%d", &p), -- p;
			int t;
			scanf("%d", &t);
			if (t == 0) {
				nodes[nNodes + p] = Node(1);
				for (int i = (nNodes + p) >> 1; i > 0; i >>= 1)
					nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
			} else {
				int x;
				scanf("%d", &x);
				value[p] = x;
				nodes[nNodes + p] = Node(-1);
				for (int i = (nNodes + p) >> 1; i > 0; i >>= 1)
					nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
			}
			int ans;
			if (nodes[1].minAdd >= 0) {
				ans = -1;
			} else {
				int i, add;
				for (i = 1, add = 0; i < nNodes; ) {
					int l = i * 2, r = i * 2 + 1;
					if (nodes[r].minAdd + add < 0)
						i = r;
					else
						add += nodes[r].add, i = l;
				}
				ans = value[i - nNodes];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}