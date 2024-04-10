#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


void rec(ll a, int b, vi &ops, vi &ans) {
	if(a > b) return;
	if(ops.size() >= ans.size()) return;
	if(a == b) {
		ans = ops;
		return;
	}
	ops.push_back((int)a);
	rec(a * 2, b, ops, ans);
	rec(a * 10 + 1, b, ops, ans);
	ops.pop_back();
}

int main() {
	int a; int b;
	while(~scanf("%d%d", &a, &b)) {
		vi ops, ans(100, -1);
		rec(a, b, ops, ans);
		if(ans.size() == 100) {
			puts("NO");
		} else {
			puts("YES");
			ans.push_back(b);
			printf("%d\n", (int)ans.size());
			for(int i = 0; i < (int)ans.size(); ++ i) {
				if(i != 0) putchar(' ');
				printf("%d", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}