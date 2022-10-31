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
	char buf[100001];
	while (~scanf("%s", buf)) {
		bool isGood[26] = {};
		for (const char *p = buf; *p; ++ p)
			isGood[*p - 'a'] = true;
		scanf("%s", buf);
		string pattern = buf;
		auto mid = pattern.find('*');
		string L, R;
		bool noStar = false;
		if (mid == string::npos) {
			L = pattern;
			noStar = true;
		} else {
			L = pattern.substr(0, mid);
			R = pattern.substr(mid + 1);
		}
		auto match = [&](char p, char c) {
			if (p != '?')
				return p == c;
			else
				return isGood[c - 'a'];
		};
		int Q;
		scanf("%d", &Q);
		rep(ii, Q) {
			scanf("%s", buf);
			int len = (int)strlen(buf);
			bool ans = true;
			if ((int)(L.size() + R.size()) > len) {
				ans = false;
			} else {
				if (noStar)
					ans &= L.size() == len;
				rep(i, L.size())
					ans &= match(L[i], buf[i]);
				rep(i, R.size())
					ans &= match(R[i], buf[len - R.size() + i]);
				reu(i, L.size(), len - R.size())
					ans &= !isGood[buf[i] - 'a'];
			}
			puts(ans ? "YES" : "NO");
		}
	}
	return 0;
}