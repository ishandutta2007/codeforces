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

template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }

int main() {
	typedef unsigned long long ull;
	//lcm(w,b) x + y (0 <= y < min(w,b))
	ull t, w, b;
	while(cin >> t >> w >> b) {
		++ t;
		ull g = gcd(w, b);
		ull num = 0;
		ull l = w / g * 1. * b < 1e19 ? w / g * b : (ull)1e19;
		ull r = t / l;
		num += r * min(w, b);
		num += min(t % l, min(w, b));
		-- num, -- t;
		ull h = gcd(num, t);
		cout << num / h << "/" << t / h << endl;
	}
	return 0;
}