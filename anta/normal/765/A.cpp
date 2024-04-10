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
		string home;
		cin >> home;
		int cnt = 0;
		rep(i, n) {
			string s;
			cin >> s;
			string x = s.substr(0, 3);
			string y = s.substr(5);
			if (x == home) ++ cnt;
			if (y == home) -- cnt;
		}
		bool ans = cnt == 0;
		puts(ans ? "home" : "contest");
	}
	return 0;
}