#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Shirt {
	int p;
	int a, b;
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<Shirt> shirts(n);
		rep(i, n) {
			int p;
			scanf("%d", &p);
			shirts[i].p = p;
		}
		rep(i, n) {
			int a;
			scanf("%d", &a), -- a;
			shirts[i].a = a;
		}
		rep(i, n) {
			int a;
			scanf("%d", &a), -- a;
			shirts[i].b = a;
		}
		sort(shirts.begin(), shirts.end(), [](Shirt x, Shirt y) { return x.p < y.p; });
		vector<vi> indices(3);
		rep(i, n) {
			indices[shirts[i].a].push_back(i);
			indices[shirts[i].b].push_back(i);
		}
		rep(k, 3) {
			auto &v = indices[k];
			reverse(v.begin(), v.end());
		}
		vector<bool> bought(n);
		int m;
		scanf("%d", &m);
		rep(i, m) {
			int c;
			scanf("%d", &c), -- c;
			auto &v = indices[c];
			while (!v.empty()) {
				if (!bought[v.back()]) break;
				v.pop_back();
			}
			if (i != 0)putchar(' ');
			if (v.empty()) {
				printf("-1");
			} else {
				int j = v.back();
				bought[j] = true;
				int ans = shirts[j].p;
				printf("%d", ans);
			}
		}
		puts("");
	}
	return 0;
}