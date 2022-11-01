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
int w[100005];
int main()
{
	int n, l, r, ans, cnt = 0, mc = 0;
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &w[i]);
	scanf("%d%d", &l, &r);
	for(int i = l; i < r; i ++) cnt += w[i];
	int cl = l, cr = r;
	rep1(i, n) {
		if(cnt > mc) {
			mc = cnt;
			ans = i;
		}
		cl --;
		cr --;
		if(cl < 1) cl = n;
		if(cr < 1) cr = n;
		cnt += w[cl] - w[cr];
	}
	printf("%d\n", ans);
	return 0;
}