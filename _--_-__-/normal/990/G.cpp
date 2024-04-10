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

int gcd(int u, int v)
{
	return v == 0 ? u : gcd(v, u % v);
}

vector<int> divs[200005];
int mu[200005];

void init_nt()
{
	mu[1] = 1;
	rep1(i, 200000) for(int j = i; j <= 200000; j += i) if(j > i) mu[j] -= mu[i];
}

int dat[200005];
LL tot[200005];

vector<PII> E[200005];
vector<int> G[200005];
vector<int> hv[200005];
bool vis[200005];

int dfs(int v)
{
	vis[v] = true;
	int ret = 1;
	rep(i, G[v].size())
	if(!vis[G[v][i]]) ret += dfs(G[v][i]);
	return ret;
}

vector<int> chv;

int main()
{
	init_nt();
	int n;
	scanf("%d", &n);
	rep1(i, n) {
		scanf("%d", &dat[i]);
		hv[dat[i]].push_back(i);
	}
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[gcd(dat[u], dat[v])].push_back(MP(u, v));
	}
	rep1(i, 200000) {
		chv.clear();
		for(int j = i; j <= 200000; j += i) rep(k, hv[j].size())
		chv.push_back(hv[j][k]);
		rep(j, chv.size()) {
			G[chv[j]].clear();
			vis[chv[j]] = false;
		}
		for(int j = i; j <= 200000; j += i) rep(k, E[j].size()) {
			G[E[j][k].first].push_back(E[j][k].second);
			G[E[j][k].second].push_back(E[j][k].first);
		}
		rep(j, chv.size()) if(!vis[chv[j]]) {
			int cur = dfs(chv[j]);
			tot[i] += LL(cur + 1) * cur / 2;
		}
	}
	rep1(i, 200000) {
		LL cur = 0;
		for(int j = i; j <= 200000; j += i) cur += tot[j] * mu[j / i];
		if(cur != 0) printf("%d %I64d\n", i, cur);
	}
	return 0;
}