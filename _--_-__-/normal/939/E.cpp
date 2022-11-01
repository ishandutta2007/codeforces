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
LL num[500005], pres[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cur = 1, q = 0;
	long double ans = 0.0;
	cin >> q;
	while(q --) {
		int t;
		cin >> t;
		if(t == 1) {
			cin >> num[cur];
			pres[cur] = pres[cur - 1] + num[cur];
			int l = 1, r = cur;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(pres[mid] + num[cur] > num[mid] * (mid + 1)) l = mid + 1;
				else r = mid;
			}
			ans = max(ans, num[cur] - (long double)(pres[r - 1] + num[cur]) / r);
			cur ++;
		} else cout << fixed << setprecision(10) << ans << '\n';
	}
	cout << flush;
	return 0;
}