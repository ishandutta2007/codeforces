#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct Node {
	Node *c[2];
	int cnt;

	Node() : c{0, 0}, cnt(0) {}
};

int main() {
	int q;
	while(~scanf("%d", &q)) {
		const int B = 30;
		vector<Node> nodes((q + 1) * B + 1);
		int nNodes = 0;
		Node *root = new(&nodes[nNodes ++]) Node();
		for(int ii = -1; ii < q; ++ ii) {
			char ty[10];
			if(ii == -1) {
				*ty = '+';
			} else {
				scanf("%s", ty);
			}
			if(*ty == '+' || *ty == '-') {
				int x;
				if(ii == -1) {
					x = 0;
				} else {
					scanf("%d", &x);
				}
				Node *p = root;
				Node *path[B + 1];
				path[B] = root;
				for(int i = B - 1; i >= 0; -- i) {
					Node *&c = p->c[x >> i & 1];
					if(!c) c = new(&nodes[nNodes ++]) Node();
					p = c;
					path[i] = p;
				}
				for(Node *t : path)
					t->cnt += *ty == '+' ? +1 : -1;
			} else if(*ty == '?') {
				int x;
				scanf("%d", &x);
				int ans = 0;
				Node *p = root;
				for(int i = B - 1; i >= 0; -- i) {
					int b = x >> i & 1;
					if(p->c[b ^ 1] && p->c[b ^ 1]->cnt > 0) {
						p = p->c[b ^ 1];
						ans |= 1 << i;
					} else {
						p = p->c[b];
					}
					assert(p != nullptr && p->cnt > 0);
				}
				printf("%d\n", ans);
			} else abort();
		}
	}
	return 0;
}