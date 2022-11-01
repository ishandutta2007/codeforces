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
namespace DSU
{
	int pre[128];
	void init()
	{
		for(int i = 'a'; i <= 'z'; i ++) pre[i] = i;
	}
	int root(int v)
	{
		return v == pre[v] ? v : pre[v] = root(pre[v]);
	}
	bool unite(int u, int v)
	{
		u = root(u);
		v = root(v);
		if(u == v) return true;
		pre[u] = v;
		return false;
	}
}
char chv[100005], cht[100005];
int main()
{
	int n;
	scanf("%d%s%s", &n, chv, cht);
	DSU::init();
	rep(i, n) DSU::unite(chv[i], cht[i]);
	vector<pair<char, char> > ans;
	for(int i = 'a'; i <= 'z'; i ++)
	if(DSU::pre[i] != i) ans.push_back(MP(i, DSU::pre[i]));
	printf("%d\n", ans.size());
	rep(i, ans.size()) printf("%c %c\n", ans[i].first, ans[i].second);
	return 0;
}