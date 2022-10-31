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
		//0, 1, 2, 3, 4, 5, 6
		//0, 0, 1, 0, 1, 
		int x = 0;
		for(int i = 0; i < n; ++ i) {
			int a;
			scanf("%d", &a);
			x ^= (a + 1) % 2;
			puts(x != 0 ? "1" : "2");
		}

	}
	return 0;
}