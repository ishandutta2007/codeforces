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
	string s[2];
	while (cin >> s[0] >> s[1]) {
		int n;
		scanf("%d", &n);
		rep(i, n + 1) {
			printf("%s %s\n", s[0].c_str(), s[1].c_str());
			if (i == n) break;
			string x, y;
			cin >> x >> y;
			*find(s, s + 2, x) = y;
		}
	}
	return 0;
}