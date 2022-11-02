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
const LL MOD = 1e9 + 9;

int n, a, b, k;
int s[100005];

LL power(LL x, LL t)
{
	if(t == 0) return 1LL;
	LL cc = power(x, t >> 1);
	cc = cc * cc % MOD;
	if(t & 1) cc = cc * x % MOD;
	return cc;
}

LL divi(LL a, LL b)
{
	return a * power(b, MOD - 2) % MOD;
}

int main()
{
	scanf("%d%d%d%d", &n, &a, &b, &k);
	getchar();
	rep(i, k) s[i] = getchar() == '+' ? 1 : -1;
	LL cur = 0LL;
	rep(i, k) cur = (cur + power(a, k - 1 - i) * power(b, i) * s[i]) % MOD;
	cur = (cur + MOD) % MOD;
	LL ca = power(a, k), cb = power(b, k);
	int ct = (n + 1) / k;
	if(ca == cb) cur *= power(cb, ct - 1) * ct;
	else cur *= power(cb, ct - 1) * divi(1 - power(divi(ca, cb), ct), 1 - divi(ca, cb)) % MOD;
	cur = (cur % MOD + MOD) % MOD;
	printf("%d\n", int(cur));
	return 0;
}