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
	int X;
	int h, m;
	while(~scanf("%d%d:%d", &X, &h, &m)) {
		pair<int,int> a(INF,INF), b(INF,INF);
		if(X == 12) {
			rer(x, 1, 12)
				amin(a, make_pair((x / 10 != h / 10) + (x % 10 != h % 10), x));
		} else {
			rep(x, 24)
				amin(a, make_pair((x / 10 != h / 10) + (x % 10 != h % 10), x));
		}
		rep(x, 60)
			amin(b, make_pair((x / 10 != m / 10) + (x % 10 != m % 10), x));

		printf("%02d:%02d\n", a.second, b.second);
	}
	return 0;
}