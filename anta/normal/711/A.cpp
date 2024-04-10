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
		bool ans = false;
		vector<string> v(n);
		rep(i, n) {
			char s[6];
			scanf("%s", s);
			if(!ans) {
				if(s[0] == 'O' && s[1] == 'O') {
					s[0] = s[1] = '+';
					ans = true;
				}else if(s[3] == 'O' && s[4] == 'O') {
					s[3] = s[4] = '+';
					ans = true;
				}
			}
			v[i] = s;
		}
		if(ans) {
			puts("YES");
			rep(i, n)
				puts(v[i].c_str());
		} else {
			puts("NO");
		}
	}
	return 0;
}