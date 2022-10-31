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
#include <limits>
#include <functional>
#include <unordered_map>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct GModInt {
	static int Mod;
	int x;
	GModInt(): x(0) { }
	GModInt(signed sig) { if((x = sig % Mod + Mod) >= Mod) x -= Mod; }
	GModInt(signed long long sig) { if((x = sig % Mod + Mod) >= Mod) x -= Mod; }
	int get() const { return x; }
	
	GModInt &operator+=(GModInt that) { if((x += that.x) >= Mod) x -= Mod; return *this; }
	GModInt &operator-=(GModInt that) { if((x += Mod - that.x) >= Mod) x -= Mod; return *this; }
	GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }
	
	GModInt operator+(GModInt that) const { return GModInt(*this) += that; }
	GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }
	GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }
};
int GModInt::Mod = 0;
typedef GModInt mint;

int main() {
	int n, k, m;
	while(cin >> n >> k >> m) {
		mint::Mod = m;
		vector<vector<mint> > dp(n+1, vector<mint>((k+1) * 2));
		dp[0][0 * 2 + 1] = 1;
		int p10 = 1 % k;
		rep(i, n) {
			rep(j, k+1) rep(z, 2) {
				mint x = dp[i][j * 2 + z];
				if(x.get() == 0) continue;
				rep(d, 10) {
					if(i == n-1 && d == 0) continue;
					int nj = j == k ? k : (j + p10 * d) % k;
					dp[i+1][(nj == 0 && (!z || d != 0) ? k : nj) * 2 + (z && d == 0)] += x;
				}
			}
			(p10 *= 10) %= k;
		}
		mint ans = dp[n][k * 2 + 0];
		printf("%d\n", ans.get());
	}
	return 0;
}