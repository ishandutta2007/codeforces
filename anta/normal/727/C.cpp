#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int query(int i, int j) {
	printf("? %d %d\n", i + 1, j + 1);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		int x = query(0, 1);
		int y = query(0, 2);
		int z = query(1, 2);
		vector<int> a(n, -1);
		a[0] = (x + y - z) / 2;
		a[1] = x - a[0];
		a[2] = y - a[0];
		reu(i, 3, n)
			a[i] = query(0, i) - a[0];
		printf("! ");
		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
		fflush(stdout);
	}
	return 0;
}