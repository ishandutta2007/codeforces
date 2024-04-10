#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <unordered_map>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<typename T, size_t WW>
void rotate_left_square(T a[][WW], int n) {
	int n1 = n / 2, n2 = n - n1;
	rep(j, n1) rep(i, n2) {
		//a[j][i], a[n-1-i][j], a[n-1-j][n-1-i], a[i][n-1-j]
		T t = a[i][n-1-j];
		a[i][n-1-j] = a[n-1-j][n-1-i];
		a[n-1-j][n-1-i] = a[n-1-i][j];
		a[n-1-i][j] = a[j][i];
		a[j][i] = t;
	}
}
template<typename T, size_t WW>
void rotate_left(T a[][WW], int H, int W) {
	rotate_left_square(a, max(H, W));
	int pad = max(0, H - W);
	if(pad > 0) {
		for(int i = 0; i < W; i ++)
			memcpy(a[i], a[i+pad], H * sizeof(**a));
	}
}

char s[1000][1001], ans[1000][1001];
bool dp[1001][4][4];
char dpprev[1001][4][4];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", s[i]);
	rep(rot, 2) {
		mset(dp, 0);
		dp[0][0][0] = true;
		rep(j, m) {
			char cs[2] = { '0', '0' };
			bool ok = true;
			rep(i, n) {
				char c = s[i][j];
				if(c == '0') continue;
				if(cs[i % 2] != '0' && cs[i % 2] != c) {
					ok = false;
				}
				cs[i % 2] = c;
			}
			if(!ok) break;
//			cerr << j << ": " << cs[0] << ", " << cs[1] << endl;
			rep(c1, 4) rep(c2, 4) if(dp[j][c1][c2]) {
//				cerr << j << ", " << c1 << ", " << c2 << endl;
				rep(c3, 4) if((cs[0] == '0' || cs[0] - '1' == c3) && (j == 0 || (c3 != c1 && c3 != c2)))
				rep(c4, 4) if((cs[1] == '0' || cs[1] - '1' == c4) && c3 != c4 && (j == 0 || (c4 != c1 && c4 != c2))) {
					dp[j+1][c3][c4] = true;
					dpprev[j+1][c3][c4] = c1 | c2 << 2;
				}
			}
		}
		rep(c1, 4) rep(c2, 4) if(dp[m][c1][c2]) {
			int x = c1, y = c2;
			for(int j = m-1; j >= 0; j --) {
				rep(i, n) ans[i][j] = '1' + (i % 2 == 0 ? x : y);
				int t = dpprev[j+1][x][y];
				x = t & 3, y = t >> 2;
			}
			if(rot == 1) {
				rep(roti, 3) {
					rotate_left(ans, n, m);
					swap(n, m);
				}
			}
			rep(i, n) ans[i][m] = 0;
			rep(i, n) puts(ans[i]);
			return 0;
		}
		rotate_left(s, n, m);
		swap(n, m);
	}
	puts("0");
	return 0;
}