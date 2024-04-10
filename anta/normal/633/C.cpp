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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct Node {
	int id;
	Node *next[26];
	Node() {
		id = -1;
		mset(next, 0);
	}
};

int main() {
	vector<Node> nodes(1000001);
	int n;
	while(~scanf("%d", &n)) {
		char t[10001];
		scanf("%s", t);
		int m;
		scanf("%d", &m);
		char buf[1001];
		vector<string> words(m);
		int nNodes = 0;
		Node *root = new(&nodes[nNodes ++]) Node();
		rep(i, m) {
			scanf("%s", buf);
			words[i] = buf;
			int len = strlen(buf);
			Node *p = root;
			rep(j, len) {
				int a = tolower(buf[len - 1 - j]) - 'a';
				Node *&np = p->next[a];
				if(!np)
					np = new(&nodes[nNodes ++]) Node();
				p = np;
			}
			p->id = i;
		}
		vector<int> dp(n + 1, -1);
		dp[0] = -2;
		rep(i, n) if(dp[i] != -1) {
			const Node *p = root;
			rer(j, i + 1, n) {
				int a = t[j - 1] - 'a';
				Node *np = p->next[a];
				if(!np) break;
				if(np->id != -1)
					dp[j] = np->id;
				p = np;
			}
		}
		vector<string> ans;
		for(int i = n; i > 0; ) {
			int id = dp[i];
			ans.push_back(words[id]);
			i -= words[id].size();
		}
		reverse(all(ans));
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%s", ans[i].c_str());
		}
		puts("");
	}
	return 0;
}