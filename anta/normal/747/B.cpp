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
	int n;
	while (~scanf("%d", &n)) {
		char s[256];
		scanf("%s", s);
		int cnt[128] = {};
		vi v[128] = {};
		for (const char *p = s; *p; ++p) {
			++cnt[*p];
			v[*p].push_back(p - s);
		}
		bool ok = true;
		for (char c : "ACGT") if(c) {
			int x = n / 4 - cnt[c];
			ok &= 0 <= x && x <= (int)v['?'].size();
			if (!ok) break;
			rep(k, x) {
				s[v['?'].back()] = c;
				v['?'].pop_back();
			}
		}
		ok &= v['?'].empty();
		if (!ok)
			puts("===");
		else
			puts(s);
	}
	return 0;
}