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
	int T;
	scanf("%d", &T);
	for (int ii = 0; ii < T; ++ii) {
		int n;
		scanf("%d", &n);
		vector<string> names(n);
		rep(i, n) {
			char buf[101];
			scanf("%s", buf);
			names[i] = buf;
		}
		map<string, int> nameMap;
		rep(i, n)
			nameMap[names[i]] = i;
		int m;
		scanf("%d\n", &m);
		vector<string> texts(m);
		vector<vector<bool>> possible(m, vector<bool>(n));
		rep(i, m) {
			string line;
			getline(cin, line);
			auto p = line.find(':');
			string user = line.substr(0, p);
			string text = line.substr(p + 1);
			if (user != "?") {
				assert(nameMap.count(user));
				int from = nameMap[user];
				possible[i][from] = true;
			} else {
				rep(j, n)
					possible[i][j] = true;
			}
			string t = text;
			for (char &c : t) if (!isalnum(c))
				c = ' ';
			stringstream ss(t);
			string word;
			while (ss >> word) {
				auto it = nameMap.find(word);
				if (it != nameMap.end())
					possible[i][it->second] = false;
			}
			texts[i] = text;
		}
		vector<vi> dp(m + 1, vi(n + 1, -1));
		dp[0][n] = -2;
		rep(i, m) rep(j, n + 1) {
			int x = dp[i][j];
			if (x == -1) continue;
			rep(k, n) if (possible[i][k] && j != k)
				dp[i + 1][k] = j;
		}
		int j = 0;
		while (j < n && dp[m][j] == -1) ++ j;
		if (j == n) {
			puts("Impossible");
		} else {
			vector<int> ans(m);
			for (int i = m - 1; i >= 0; --i) {
				ans[i] = j;
				j = dp[i + 1][j];
			}
			rep(i, m)
				printf("%s:%s\n", names[ans[i]].c_str(), texts[i].c_str());
		}
	}
	return 0;
}