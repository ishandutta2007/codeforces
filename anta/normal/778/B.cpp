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
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		using BitSet = bitset<1000>;
		vector<BitSet> a[2];
		rep(k, 2) a[k].resize(n + 1);
		rep(j, m) a[1][n].set(j);
		map<string, int> id;
		id["?"] = n;
		rep(i, n) {
			char buf[1001];
			scanf("%s :=", buf);
			id[buf] = i;
			scanf("%s", buf);
			if (*buf != '0' && *buf != '1') {
				int x = id[buf];
				scanf("%s", buf);
				char op = *buf;
				scanf("%s", buf);
				int y = id[buf];
				if (op == 'A') {
					rep(k, 2)
						a[k][i] = a[k][x] & a[k][y];
				} else if (op == 'O') {
					rep(k, 2)
						a[k][i] = a[k][x] | a[k][y];
				} else if (op == 'X') {
					rep(k, 2)
						a[k][i] = a[k][x] ^ a[k][y];
				} else {
					assert(false);
				}
			} else {
				rep(k, 2) rep(j, m)
					a[k][i][j] = buf[j] == '1';
			}
		}
		string ansMin, ansMax;
		rep(j, m) {
			int cnt[2] = { 0, 0 };
			rep(i, n) {
				rep(k, 2)
					cnt[k] += a[k][i][j];
			}
			ansMin += cnt[0] <= cnt[1] ? '0' : '1';
			ansMax += cnt[0] >= cnt[1] ? '0' : '1';
		}
		puts(ansMin.c_str());
		puts(ansMax.c_str());
	}
	return 0;
}