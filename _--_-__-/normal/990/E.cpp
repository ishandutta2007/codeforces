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
const LL LINF = 1LL << 60;

LL cost[1000005];
bool blk[1000005];
int pre_p[1000005];

int gett(int n, int k)
{
	int pos = 0, tot = 0;
	while(pos < n) {
		if(pre_p[pos] == -1) return -1;
		int np = pre_p[pos] + k;
		if(np <= pos) return -1;
		pos = np;
		tot ++;
	}
	return tot;
}

int main()
{
	int n, m, k;
	LL ans = LINF;
	scanf("%d%d%d", &n, &m, &k);
	rep(i, m) {
		int x;
		scanf("%d", &x);
		blk[x] = true;
	}
	rep(i, n) if(blk[i]) pre_p[i] = (i == 0 ? -1 : pre_p[i - 1]);
	else pre_p[i] = i;
	rep1(i, k) scanf("%I64d", &cost[i]);
	rep1(i, k) {
		int tt = gett(n, i);
		if(tt != -1) ans = min(ans, tt * cost[i]);
	}
	printf("%I64d\n", ans == LINF ? -1 : ans);
	return 0;
}