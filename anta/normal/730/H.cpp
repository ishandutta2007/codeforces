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
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<string> names(n);
		rep(i, n) {
			char buf[101];
			scanf("%s", buf);
			names[i] = buf;
		}
		string pat;
		vector<bool> including(n);
		rep(i, m) {
			int a;
			scanf("%d", &a), -- a;
			including[a] = true;
			if(i == 0) {
				pat = names[a];
			} else if(!pat.empty()) {
				if(pat.size() != names[a].size()) {
					pat.clear();
				} else {
					rep(j, pat.size()) {
						if(pat[j] != '?' && pat[j] != names[a][j])
							pat[j] = '?';
					}
				}
			}
		}
		rep(i, n) {
			bool match = true;
			if(pat.size() == names[i].size()) {
				rep(j, pat.size()) {
					if(pat[j] != '?' && pat[j] != names[i][j])
						match = false;
				}
			} else {
				match = false;
			}
			if(match != including[i]) {
				pat.clear();
				break;
			}
		}
		if(!pat.empty()) {
			puts("Yes");
			puts(pat.c_str());
		} else {
			puts("No");
		}
	}
	return 0;
}