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
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		map<int,int> cnt;
		char buf[101];
		rep(i, n) {
			scanf("%s", buf);
			++ cnt[strlen(buf)];
		}
		scanf("%s", buf);
		int len = strlen(buf);
		int L = 0, U = 0;
		for(auto p : cnt) {
			if(len > p.first) {
				L += p.second;
				U += p.second;
			} else if(len == p.first) {
				L += 1;
				U += p.second;
			}
		}
		L += (L - 1) / k * 5;
		U += (U - 1) / k * 5;
		printf("%d %d\n", L, U);
	}
	return 0;
}