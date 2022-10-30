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
	int n; int t;
	while(~scanf("%d%d", &n, &t)) {
		char s[200003];
		scanf("%s", s);
		int i = 0;
		for(; s[i] != '.'; ++ i);
		++ i;
		for(; s[i] != 0 && s[i] <= '4'; ++ i);
		if(s[i] != 0) {
			while(t > 0) {
				-- t;
				if(s[i - 1] == '.') {
					s[-- i] = 0;
					reverse(s, s + i);
					i = 0;
					while(s[i] == '9') s[i ++] = '0';
					if(s[i] == 0) s[i] = '1', s[i + 1] = 0;
					else ++ s[i];
					reverse(s, s + strlen(s));
					break;
				} else {
					++ s[i - 1];
					s[i] = 0;
					if(s[i - 1] != '5')
						break;
					-- i;
				}
			}
		}
		puts(s);
	}
	return 0;
}