#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n;
	while(~scanf("%d", &n)) {
		map<pair<int, int>, vector<pair<int,int>>> rectangles;
		set<pair<int,int>> curPairs;
		vi ans;
		int ansval = -1;
		rep(i, n) {
			int A; int B; int C;
			scanf("%d%d%d", &A, &B, &C);
			int a[3] = { A, B, C };
			sort(a, a + 3);
			if(ansval < a[0]) {
				ansval = a[0];
				ans = { i };
			}
			curPairs.clear();
			do {
				auto p = make_pair(a[0], a[1]);
				if(p.first > p.second) swap(p.first, p.second);
				if(curPairs.emplace(p).second)
					rectangles[p].emplace_back(a[2], i);
			} while(next_permutation(a, a + 3));
		}
		for(auto &&p : rectangles) {
			auto &v = p.second;
			if((int)v.size() <= 1) continue;
			sort(v.begin(), v.end());
			int len = v.end()[-2].first + v.end()[-1].first;
			int val = min({ p.first.first, p.first.second, len });
			if(ansval < val) {
				ansval = val;
				ans = { v.end()[-2].second, v.end()[-1].second };
			}
		}
		printf("%d\n", (int)ans.size());
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}