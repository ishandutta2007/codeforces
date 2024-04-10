#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Node {
	Node *next[5];
	int cnt;
	bool vis;
	Node() : next{}, cnt(0), vis(false) {}
};

int main() {
	int N; int M;
	while (~scanf("%d%d", &N, &M)) {
		vector<Node> nodes(N * 51 + 1);
		int nNodes = 0;
		Node *root = new(&nodes[nNodes ++]) Node;
		rep(i, N) {
			char buf[101];
			scanf("%s", buf);
			auto t = root;
			for (const char *p = buf; *p; ++ p) {
				auto &n = t->next[*p - 'a'];
				if(!n) n = new(&nodes[nNodes ++]) Node;
				t = n;
			}
			++ t->cnt;
		}
		vector<Node*> visited;
		rep(i, M) {
			char buf[101];
			scanf("%s", buf);
			auto rec = [&visited](auto rec, const char *p, Node *t) -> int {
				if (!t) return 0;
				char c = *p;
				if (c == '\0') {
					if (t->vis) return 0;
					t->vis = true;
					visited.push_back(t);
					return t->cnt;
				} else if (c == '?') {
					int r = rec(rec, p + 1, t);
					rep(a, 5)
						r += rec(rec, p + 1, t->next[a]);
					return r;
				} else {
					return rec(rec, p + 1, t->next[c - 'a']);
				}
			};
			int ans = rec(rec, buf, root);
			for (auto t : visited)
				t->vis = false;
			visited.clear();
			printf("%d\n", ans);
		}
	}
	return 0;
}