#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

vector<int> t_parent;
vector<int> t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)g[i].size() - 1; j >= 0; j--) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

int main() {
	char S[1000001];
	while (~scanf("%s", S)) {
		for (char *p = S; *p; ++p)
			if (*p == ',')
				*p = ' ';
		vector<pair<string, int>> words;
		{
			stringstream ss(S);
			string x; int n;
			while (ss >> x >> n)
				words.emplace_back(x, n);
		}
		vector<vi> g(words.size() + 1);
		int root = (int)words.size();
		{
			int cur = 0;
			function<int()> dfs = [&]() -> int {
				int i = cur++;
				int n = words[i].second;
				rep(t, n) {
					int j = dfs();
					g[i].push_back(j);
				}
				return i;
			};
			while (cur != words.size()) {
				int i = dfs();
				g[root].push_back(i);
			}
		}
		tree_getorder(g, root);
		vector<int> depth(t_ord.size());
		for (int ix = 1; ix < (int)t_ord.size(); ++ix) {
			int i = t_ord[ix], p = t_parent[i];
			depth[i] = depth[p] + 1;
		}
		int D = *max_element(depth.begin(), depth.end());
		printf("%d\n", D);
		vector<vi> levels(D + 1);
		for (int ix = 0; ix < (int)t_ord.size(); ++ix) {
			int i = t_ord[ix], p = t_parent[i];
			levels[depth[i]].push_back(i);
		}
		rer(d, 1, D) {
			int num = 0;
			for (int i : levels[d]) {
				if (num++ != 0) putchar(' ');
				printf("%s", words[i].first.c_str());
			}
			puts("");
		}
		break;
	}
	return 0;
}