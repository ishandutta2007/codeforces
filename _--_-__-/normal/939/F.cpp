#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;
int l[105], r[105];
int dp[105][200005];
deque<PII> cur;
inline void ins(PII ele)
{
    while(!cur.empty() && cur.back() > ele) cur.pop_back();
    cur.push_back(ele);
}
inline void era(PII ele)
{
    if(!cur.empty() && cur.front() == ele) cur.pop_front();
}
inline int mini(){
    return cur.empty() ? INF : cur.front().first;
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	rep1(i, k) scanf("%d%d", &l[i], &r[i]);
	for(int i = 0; i <= k; i ++) for(int j = 0; j <= 200000; j ++) dp[i][j] = INF;
	dp[0][0] = 0;
	rep1(i, k) {
		int cl = 0, cr = 0;
		cur.clear();
		for(int j = r[i] - r[i - 1]; j <= 200000; j ++)
		dp[i][j] = dp[i - 1][j - r[i] + r[i - 1]];
		for(int j = 0; j <= 200000; j ++) {
			int lb = j - r[i] + r[i - 1], rb = j - l[i] + r[i - 1];
			while(cr <= rb && cr <= 200000) {
				ins(MP(dp[i - 1][cr], cr));
				cr ++;
			}
			while(cl < lb && cl <= 200000) {
				era(MP(dp[i - 1][cl], cl));
				cl ++;
			}
			dp[i][j] = min(dp[i][j], mini() + 2);
		}
		cl = cr = 0;
		cur.clear();
		for(int j = 200000; j >= 0; j --) {
			int lb = r[i - 1] - j, rb = r[i - 1] + r[i] - l[i] - j;
			while(cr <= rb && cr <= 200000) {
				ins(MP(dp[i - 1][cr], cr));
				cr ++;
			}
			while(cl < lb && cl <= 200000) {
				era(MP(dp[i - 1][cl], cl));
				cl ++;
			}
			dp[i][j] = min(dp[i][j], mini() + 1);
		}
	}
	if(r[k] < n || dp[k][r[k] - n] == INF) printf("Hungry\n");
	else printf("Full\n%d\n", dp[k][r[k] - n]);
	return 0;
}