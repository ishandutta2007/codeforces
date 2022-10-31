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
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]), -- a[i];
		vector<int> ans(n, INF);
		ans[0] = 0;
		vi q, nq;
		nq.push_back(0);
		while(!nq.empty()) {
			q.swap(nq);
			while(!q.empty()) {
				int i = q.back(); q.pop_back();
				if(i > 0 && ans[i - 1] == INF) {
					ans[i - 1] = ans[i] + 1;
					nq.push_back(i - 1);
				}
				if(i + 1 < n && ans[i + 1] == INF) {
					ans[i + 1] = ans[i] + 1;
					nq.push_back(i + 1);
				}
				if(ans[a[i]] == INF) {
					ans[a[i]] = ans[i] + 1;
					nq.push_back(a[i]);
				}
			}
		}
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}