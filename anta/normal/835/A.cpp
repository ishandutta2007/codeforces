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
	int s;
	while (~scanf("%d", &s)) {
		int v1; int v2;
		scanf("%d%d", &v1, &v2);
		int t1; int t2;
		scanf("%d%d", &t1, &t2);
		int a = t1 * 2 + s * v1;
		int b = t2 * 2 + s * v2;
		puts(a == b ? "Friendship" : a < b ? "First" : "Second");
	}
	return 0;
}