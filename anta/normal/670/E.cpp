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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int m; int p;
	while(~scanf("%d%d%d", &n, &m, &p)) {
		-- p;
		string s, ops;
		cin >> s;
		cin >> ops;
		vector<int> match(n, -1);
		{
			vi stk;
			rep(i, n) {
				if(s[i] == '(') {
					stk.push_back(i);
				} else {
					int j = stk.back();
					match[i] = j;
					match[j] = i;
					stk.pop_back();
				}
			}
		}
		set<int> rem;
		rep(i, n) rem.insert(i);
		rep(i, m) {
			if(ops[i] == 'L') {
				p = *(-- rem.lower_bound(p));
			} else if(ops[i] == 'R') {
				p = *rem.lower_bound(p + 1);
			} else {
				assert(ops[i] == 'D');
				int q = match[p];
				if(q < p) swap(p, q);
				auto pt = rem.lower_bound(p);
				auto qt = rem.lower_bound(q);
				assert(*pt == p && *qt == q);
				++ qt;
				rem.erase(pt, qt);
				if(qt != rem.end()) {
					p = *qt;
				} else {
					assert(qt != rem.begin());
					-- qt;
					p = *qt;
				}
			}
		}
		string ans;
		for(int i : rem)
			ans += s[i];
		puts(ans.c_str());
	}
	return 0;
}