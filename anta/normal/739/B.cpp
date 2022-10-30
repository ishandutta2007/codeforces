#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

vector<int> a;
vector<vpii> gw;
vector<ll> path;
vector<int> pathu;
vector<int> ans;
void dfs(int i, int p) {
	int k = (int)(lower_bound(path.begin(), path.end(), path.back() - a[i]) - path.begin());
	assert(k < (int)path.size());
	if(k != path.size() - 1) {
		if(k != 0) -- ans[pathu[k - 1]];
		++ ans[p];
	}
	for(auto e : gw[i]) if(e.first != p) {
		ll d = path.back() + e.second;
		path.push_back(d);
		pathu.push_back(e.first);
		dfs(e.first, i);
		pathu.pop_back();
		path.pop_back();
	}
}

void dfs2(int i, int p) {
	for(auto e : gw[i]) if(e.first != p) {
		dfs2(e.first, i);
		ans[i] += ans[e.first];
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		a.resize(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		gw.assign(n, vpii());
		rep(i, n - 1) {
			int p; int w;
			scanf("%d%d", &p, &w), -- p;
			gw[p].emplace_back(i + 1, w);
			gw[i + 1].emplace_back(p, w);
		}
		path.push_back(0);
		pathu.push_back(0);
		ans.assign(n, 0);
		dfs(0, -1);
		pathu.pop_back();
		path.pop_back();
		dfs2(0, -1);
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}