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

string ans;
void make1(const int *a, int n) {
	if(count(a, a + n, 1) == n) {
		ans += "1";
		rep(i, n-1)
			ans += "->1";
	}else {
		int i = 0;
		while(a[i] == 1) ++ i;
		assert(i < n && a[i] == 0);
		if(i == n-1) cerr << "error" << endl;
		ans += '(';
		rep(j, i) {
			ans += "1->";
		}
		ans += "0)";
		ans += "->(";
		reu(j, i+1, n) {
			if(j != i+1) ans += "->";
			ans += char('0' + a[j]);
		}
		ans += ')';
	}
}

void rec(const vi &a, int i, const vi &dp) {
	int j = dp[i];
	if(j == -1) cerr << "error 2" << endl;
	if(j == a.size()) {
		ans += "0";
		return;
	}
	ans += '(';
	make1(&a[0] + i, j - i);
	ans += ")->(";
	rec(a, j, dp);
	ans += ')';
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vi a(n);
		rep(i, n) scanf("%d", &a[i]);
		vi next0(n+1);
		next0[n] = INF;
		for(int i = n-1; i >= 0; -- i)
			next0[i] = a[i] == 0 ? i : next0[i+1];
		set<int> s;
		vi dp(n);
		for(int i = n-1; i >= 0; -- i) {
			int r = -1;
			int j = next0[i];
			{	auto it = s.lower_bound(i);
				if(it != s.end() && *it <= j)
					amax(r, *it);
			}
			{	auto it = s.lower_bound(j + 2);
				if(it != s.end())
					amax(r, *it);
			}
			if(i == n-1 && a[i] == 0)
				amax(r, n);
			if(r != -1)
				s.insert(i);
			dp[i] = r;
		}
		if(dp[0] == -1) {
			puts("NO");
		}else {
			ans = "";
			puts("YES");
			rec(a, 0, dp);
			puts(ans.c_str());
		}
	}
	return 0;
}