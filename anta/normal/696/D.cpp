#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct Matrix {
	typedef long long Num;
	vector<vector<Num> > v, w;
	Matrix() {}
	Matrix(int n, int m) : v(n, vector<Num>(m, -INFL)) {}
	inline int height() const { return (int)v.size(); }
	inline int width() const { return (int)v[0].size(); }
	inline Num& at(int i, int j) { return v[i][j]; }
	inline const Num& at(int i, int j) const { return v[i][j]; }
	static Matrix identity(int n) {
		Matrix A(n, n);
		rep(i, n) A.at(i, i) = 0;
		return A;
	}
	inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
	Matrix& operator*=(const Matrix& B) {
		int n = height(), m = B.width(), p = B.height();
		assert(p == width());
		w.assign(n, vector<Num>(m, 0));
		rep(i, n) rep(j, m) {
			Num x = -INFL;
			rep(k, p) amax(x, at(i, k) + B.at(k, j));
			if(x < -INFL / 2) x = -INFL;
			w[i][j] = x;
		}
		v.swap(w);
		return *this;
	}
};
Matrix operator^(const Matrix& t, ll k) {
	Matrix A = t, B = Matrix::identity(t);
	while(k) {
		if(k & 1) B *= A;
		A *= A;
		k >>= 1;
	}
	return B;
}

struct Node {
	Node *fail;
	Node *next[26];
	int sum;
	Node() : fail(NULL), next{}, sum(0) { }
};

int main() {
	int n; long long l;
	while(~scanf("%d%lld", &n, &l)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<string> s(n);
		int sumLen = 1;
		rep(i, n) {
			char buf[201];
			scanf("%s", buf);
			s[i] = buf;
			sumLen += s[i].size();
		}
		vector<Node> nodes(sumLen);
		int nNodes = 0;
		{
			Node *root = new(&nodes[nNodes ++]) Node();
			rep(i, n) {
				Node *t = root;
				for(char c : s[i]) {
					Node *&n = t->next[c - 'a'];
					if(n == nullptr)
						n = new(&nodes[nNodes ++]) Node();
					t = n;
				}
				t->sum += a[i];
			}
			int qt = 0;
			vector<Node*> que(nNodes);
			for(Node *&n : root->next) {
				if(n != nullptr) {
					n->fail = root;
					que[qt ++] = n;
				} else {
					n = root;
				}
			}
			for(int qh = 0; qh != qt; ++ qh) {
				Node *t = que[qh];
				int a = 0;
				for(Node *n : t->next) {
					if(n != nullptr) {
						que[qt ++] = n;
						Node *r = t->fail;
						while(r->next[a] == nullptr)
							r = r->fail;
						n->fail = r->next[a];
						n->sum += r->next[a]->sum;
					}
					++ a;
				}
			}
		}
		Matrix A(nNodes, nNodes);
		rep(i, nNodes) rep(a, 26) {
			Node *t = &nodes[i];
			while(t->next[a] == nullptr) t = t->fail;
			t = t->next[a];
			int j = t - &nodes[0];
			amax(A.at(i, j), t->sum);
		}
		A = A ^ l;
		ll ans = -INFL;
		rep(i, nNodes)
			amax(ans, A.at(0, i));
		printf("%lld\n", ans);
	}
	return 0;
}