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
#include <random>
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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct GModInt {
	static int Mod;
	unsigned x;
	GModInt() : x(0) {}
	GModInt(signed sig) { int sigt = sig % Mod; if(sigt < 0) sigt += Mod; x = sigt; }
	GModInt(signed long long sig) { int sigt = sig % Mod; if(sigt < 0) sigt += Mod; x = sigt; }
	int get() const { return (int)x; }

	GModInt &operator+=(GModInt that) { if((x += that.x) >= (unsigned)Mod) x -= Mod; return *this; }
	GModInt &operator-=(GModInt that) { if((x += Mod - that.x) >= (unsigned)Mod) x -= Mod; return *this; }
	GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }

	GModInt operator+(GModInt that) const { return GModInt(*this) += that; }
	GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }
	GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }
};
int GModInt::Mod = 0;
typedef GModInt mint;

int main() {
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vector<int> a(n + 1);
		vector<bool> known(n + 1);
		rep(i, n + 1) {
			char buf[20];
			scanf("%s", buf);
			if(*buf == '?') {
				known[i] = false;
			} else {
				known[i] = true;
				sscanf(buf, "%d", &a[i]);
			}
		}
		default_random_engine re{ random_device{}() };

		auto isRoot = [&](int xx) -> bool {
			bool ok = true;
			rep(trials, 200) {
				int mod;
				while(1) {
					mod = re() & 0x7fffffffU;
					if(mod == 0) continue;
					bool ok = true;
					for(int d = 2; (ll)d * d <= mod; ++ d) {
						if(mod % d == 0) {
							ok = false;
							break;
						}
					}
					if(ok) break;
				}
				mint::Mod = mod;
				mint x = xx, rem = 0;
				for(int i = n; i >= 0; -- i) {
					rem *= x;
					rem += a[i];
				}
				ok &= rem.get() == 0;
			}
			return ok;
		};

		bool ans;
		if(count(all(known), false) == 0) {
			ans = isRoot(k);
		} else if(k != 0) {
			ans = (n + 1) % 2 == 0;
		} else if(known[0]) {
			ans = a[0] == 0;
		} else {
			ans = count(all(known), true) % 2 != 0;
		}
		puts(ans ? "Yes" : "No");
	}
	return 0;
}