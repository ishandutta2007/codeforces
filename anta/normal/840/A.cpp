#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> A(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &A[i]);
		vector<int> B(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &B[i]);
		vpii Ais(n), Bis(n);
		rep(i, n) {
			Ais[i] = { A[i], i };
			Bis[i] = { B[i], i };
		}
		sort(Ais.begin(), Ais.end());
		sort(Bis.begin(), Bis.end());
		vector<int> ans(n);
		rep(i, n)
			ans[Bis[i].second] = Ais[n - 1 - i].first;
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}