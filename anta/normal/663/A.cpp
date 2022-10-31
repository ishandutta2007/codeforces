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
	string line;
	while(getline(cin, line)) {
		int plus = 1, minus = 0;
		vector<char> ops;
		for(char c : line) {
			if(c == '+') {
				++ plus;
				ops.push_back('+');
			} else if(c == '-') {
				++ minus;
				ops.push_back('-');
			}
		}
		int i = line.size();
		while(line[i] != ' ') -- i;
		int n = stoi(line.substr(i));
		ll L = plus - (ll)minus * n, R = (ll)plus * n - minus;
		if(L <= n && n <= R) {
			puts("Possible");
			vector<int> nums(plus + minus);
			ll sum = L;
			rep(i, plus) {
				int add = (int)min(n - 1LL, n - sum);
				nums[i] = 1 + add;
				sum += add;
			}
			rep(i, minus) {
				int sub = (int)min(n - 1LL, n - sum);
				nums[plus + i] = n - sub;
				sum += sub;
			}
			printf("%d", nums[0]);
			int indices[2] = { 1, plus };
			rep(i, ops.size()) {
				int x = nums[indices[ops[i] == '+' ? 0 : 1] ++];
				printf(" %c %d", ops[i], x);
			}
			printf(" = %d\n", n);
		} else {
			puts("Impossible");
		}
	}
	return 0;
}