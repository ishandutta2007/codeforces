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
	auto check = [](string t) {
		int x = 0;
		for (char c : t) {
			if (c == 'x')
				++x;
			else
				x = 0;
			if (x == 3) return true;
		}
		return false;
	};
	char a[4][5];
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		bool ans = false;
		rep(y, 4) rep(x, 4) if(a[y][x] == '.') {
			a[y][x] = 'x';
			rep(i, 4) {
				string t;
				rep(j, 4)
					t += a[i][j];
				ans |= check(t);
			}
			rep(j, 4) {
				string t;
				rep(i, 4)
					t += a[i][j];
				ans |= check(t);
			}
			{
				string ms[7], ss[7];
				rep(i, 4) rep(j, 4) {
					ms[i + j] += a[i][j];
					ss[i + 3 - j] += a[i][j];
				}
				rep(k, 7) {
					ans |= check(ms[k]);
					ans |= check(ss[k]);
				}
			}
			a[y][x] = '.';
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}