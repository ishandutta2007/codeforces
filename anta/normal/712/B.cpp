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
	char s[100001];
	while(~scanf("%s", s)) {
		int n = strlen(s);
		int x = 0, y = 0;
		rep(i, n) {
			if(s[i] == 'R')
				++ x;
			if(s[i] == 'L')
				-- x;
			if(s[i] == 'D')
				++ y;
			if(s[i] == 'U')
				-- y;
		}
		if(n % 2 == 1) {
			puts("-1");
		} else {
			int ans = abs(x) / 2 + abs(y) / 2 + ((x & 1) != 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}