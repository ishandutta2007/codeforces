#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct Query {
	int ty;
	int y, x;
};

vector<vi> children;
vector<Query> queries;
vector<int> ans;
vector<int> curRows;
vector<vector<bool>> book;
vector<bool> inverted;
int curSum;
int n, m;

bool getBook(int y, int x) {
	return book[y][x] != inverted[y];
}

bool process(int ty, int y, int x) {
	if(ty == 1) {
		if(!getBook(y, x)) {
			book[y][x] = !book[y][x];
			++ curRows[y];
			++ curSum;
			return true;
		}
	} else if(ty == 2) {
		if(getBook(y, x)) {
			book[y][x] = !book[y][x];
			-- curRows[y];
			-- curSum;
			return true;
		}
	} else if(ty == 3) {
		curSum += (m - curRows[y]) - curRows[y];
		curRows[y] = m - curRows[y];
		inverted[y] = !inverted[y];
		return true;
	}
	return false;
}

void dfs(int i) {
	bool processed = false;
	if(i != 0) {
		processed = process(queries[i].ty, queries[i].y, queries[i].x);
	}
	ans[i] = curSum;
	for(int j : children[i])
		dfs(j);
	if(processed) {
		int ty = queries[i].ty;
		process(ty == 1 ? 2 : ty == 2 ? 1 : ty, queries[i].y, queries[i].x);
	}
}

int main() {
	int q;
	while(~scanf("%d%d%d", &n, &m, &q)) {
		queries.resize(q + 1);
		children.assign(q + 1, vi());
		int cur = 0;
		for(int ii = 1; ii <= q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1 || ty == 2) {
				int y; int x;
				scanf("%d%d", &y, &x), -- y, -- x;
				queries[ii] = Query{ ty, y, x };
				children[cur].push_back(ii);
				cur = ii;
			} else if(ty == 3) {
				int y;
				scanf("%d", &y), -- y;
				queries[ii] = Query{ ty, y, -1 };
				children[cur].push_back(ii);
				cur = ii;
			} else if(ty == 4) {
				int k;
				scanf("%d", &k);
				cur = k;
				queries[ii] = Query{ ty, -1, -1 };
				children[cur].push_back(ii);
				cur = ii;
			} else abort();
		}
		ans.assign(q + 1, -1);
		curRows.assign(n, 0);
		curSum = 0;
		book.assign(n, vector<bool>(m, false));
		inverted.assign(n, false);
		dfs(0);
		rep(i, q)
			printf("%d\n", ans[i + 1]);
	}
	return 0;
}