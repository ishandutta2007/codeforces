#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const int A = 26;
struct Node {
	Node *next[A];
	vi indices;
	Node() { mset(next, 0); }
};

Node *nodes; size_t nodesp;
void insertTrie(Node *t, const char *s, int i) {
	for(const char *p = s; *p; ++ p) {
		Node *&n = t->next[*p - 'a'];
		if(n == NULL) n = new(&nodes[nodesp ++]) Node;
		t = n;
	}
	t->indices.push_back(i);
}


long long solve(const Node *t, int depth, vi &rem1, vi &rem2, vi &ans) {
	vi currem1, currem2;
	ll quality = 0;
	rep(a, A) if(t->next[a] != NULL)
		quality += solve(t->next[a], depth + 1, currem1, currem2, ans);
	each(i, t->indices) {
		if(*i % 2 == 0)
			currem1.push_back(*i / 2);
		else
			currem2.push_back(*i / 2);
	}
	int n = min(currem1.size(), currem2.size());
	rep(i, n) {
		ans[currem1[i]] = currem2[i];
		quality += depth;
	}
	rem1.insert(rem1.end(), currem1.begin() + n, currem1.end());
	rem2.insert(rem2.end(), currem2.begin() + n, currem2.end());
	return quality;
}

int main() {
	char *tmp = new char[800001];
	nodes = new Node[800001];
	int n;
	while(~scanf("%d", &n)) {
		nodesp = 0;
		Node *root = new(&nodes[nodesp ++]) Node;
		rep(i, n) scanf("%s", tmp), insertTrie(root, tmp, i * 2 + 0);
		rep(i, n) scanf("%s", tmp), insertTrie(root, tmp, i * 2 + 1);
		vi ans(n, -1), rem1, rem2;
		ll quality = solve(root, 0, rem1, rem2, ans);
		assert(rem1.empty() && rem2.empty() && count(all(ans), -1) == 0);
		cout << quality << endl;
		rep(i, n)
			printf("%d %d\n", i+1, ans[i]+1);
	}
	return 0;
}