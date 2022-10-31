#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

class IncrementalAhoCorasic {
	struct Node {
		char alpha;
		Node *fail;
		Node *head, *sibling;
		int sum;
		Node() : fail(nullptr), head(nullptr), sibling(nullptr), sum(0) { }
	};

	struct String {
		string str;
		int sign;
	};

public:
	//totalLen = sum of (len + 1)
	void init(int totalLen) {
		nodes.resize(totalLen);
		nNodes = 0;
		strings.clear();
		roots.clear();
		sizes.clear();
		que.resize(totalLen);
	}

	void insert(const string &str, int sign) {
		strings.push_back(String{ str, sign });
		roots.push_back(nodes.data() + nNodes);
		sizes.push_back(1);
		nNodes += (int)str.size() + 1;
		auto check = [&]() { return sizes.size() > 1 && sizes.end()[-1] == sizes.end()[-2]; };
		if(!check())
			makePMA(strings.end() - 1, strings.end(), roots.back(), que);
		while(check()) {
			int m = sizes.back();
			roots.pop_back();
			sizes.pop_back();
			sizes.back() += m;
			if(!check())
				makePMA(strings.end() - m * 2, strings.end(), roots.back(), que);
		}
	}

	int match(const string &str) const {
		int res = 0;
		for(const Node *t : roots)
			res += matchPMA(t, str);
		return res;
	}

private:
	static Node *getNext(Node *t, char c) {
		for(Node *p = t->head; p != nullptr; p = p->sibling) {
			if(p->alpha == c)
				return p;
		}
		if(t->alpha == -1)	//t is root
			return t;
		return nullptr;
	}
	static const Node *getNext(const Node *t, char c) {
		return getNext(const_cast<Node*>(t), c);
	}

	static void makePMA(vector<String>::const_iterator begin, vector<String>::const_iterator end, Node *nodes, vector<Node*> &que) {
		int nNodes = 0;
		Node *root = new(&nodes[nNodes ++]) Node();
		root->alpha = -1;
		for(auto it = begin; it != end; ++ it) {
			Node *t = root;
			for(char c : it->str) {
				Node *n = getNext(t, c);
				if(n == nullptr || n == root) {
					n = new(&nodes[nNodes ++]) Node();
					n->alpha = c;
					n->sibling = t->head;
					t->head = n;
				}
				t = n;
			}
			t->sum += it->sign;
		}
		int qt = 0;
		for(Node *n = root->head; n != nullptr; n = n->sibling) { 
			n->fail = root;
			que[qt ++] = n;
		}
		for(int qh = 0; qh != qt; ++ qh) {
			Node *t = que[qh];
			for(Node *n = t->head; n != nullptr; n = n->sibling) {
				que[qt ++] = n;
				Node *r = t->fail, *rn;
				while((rn = getNext(r, n->alpha)) == nullptr)
					r = r->fail;
				n->fail = rn;
				n->sum += rn->sum;
			}
		}
	}

	static int matchPMA(const Node *t, const string &str) {
		int res = 0;
		for(char c : str) {
			const Node *n;
			while((n = getNext(t, c)) == nullptr)
				t = t->fail;
			t = n;
			res += t->sum;
		}
		return res;
	}


	vector<Node> nodes;
	int nNodes;
	vector<String> strings;
	vector<Node*> roots;
	vector<int> sizes;
	vector<Node*> que;
};

int main() {
	int m;
	while(~scanf("%d", &m)) {
		IncrementalAhoCorasic iac;
		iac.init(600000);
		rep(i, m) {
			int ty;
			char s[300001];
			scanf("%d%s", &ty, s);
			if(ty == 1) {
				iac.insert(s, +1);
			} else if(ty == 2) {
				iac.insert(s, -1);
			} else if(ty == 3) {
				int ans = iac.match(s);
				printf("%d\n", ans);
				fflush(stdout);
			} else {
				abort();
			}
		}
	}
	return 0;
}