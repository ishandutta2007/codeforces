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
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> p(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &p[i]);
		vector<int> s(m);
		for(int i = 0; i < m; ++ i)
			scanf("%d", &s[i]);
		map<int, vi> computers;
		rep(i, n)
			computers[p[i]].push_back(i);
		int c = 0, u = 0;
		vector<pair<int, int>> si(m);
		rep(i, m)
			si[i] = { s[i], i };
		sort(si.begin(), si.end());
		vector<int> a(m, 0), b(n, -1);
		for(auto t : si) {
			int x = t.first, k = 0;
			while(1) {
				auto it = computers.find(x);
				if(it != computers.end() && !it->second.empty()) {
					++ c, u += k;
					int i = it->second.back();
					int j = t.second;
					b[i] = j;
					a[j] = k;
					it->second.pop_back();
					break;
				}
				if(x == 1) break;
				x = (x + 1) / 2, ++ k;
			}
		}
		printf("%d %d\n", c, u);
		for(int i = 0; i < m; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", b[i] + 1);
		}
		puts("");
	}
	return 0;
}