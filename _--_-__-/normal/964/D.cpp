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
vector<int> G[200005];
vector<PII> dp[200005], cho[200005];
PII dpt[200005];
vector<int> fin[200005][2][2];

void dfs(int v, int par)
{
	bool can = G[v].size() & 1;
	if(par > 0) can = !can;
	dp[v].push_back(MP(0, 1));
	cho[v].push_back(MP(-1, -1));
	for(int i = G[v].size() - 1; i >= 0; i --) {
		int u = G[v][i];
		if(u == par) continue;
		PII pre = dp[v].back();
		dp[v].push_back(MP(false, false));
		PII& cur = dp[v].back();
		cho[v].push_back(MP(-1, -1));
		PII& cch = cho[v].back();
		dfs(u, v);
		if(dpt[u].first) {
			if(pre.first) {
				cur.first = true;
				cch.first = 0;
			}
			if(pre.second) {
				cur.second = true;
				cch.second = 2;
			}
		}
		if(dpt[u].second) {
			if(pre.first) {
				cur.second = true;
				cch.second = 1;
			}
			if(pre.second) {
				cur.first = true;
				cch.first = 3;
			}
		}
	}
	reverse(dp[v].begin(), dp[v].end());
	reverse(cho[v].begin(), cho[v].end());
	dpt[v] = dp[v][0];
	if(dpt[v].first) {
		bool cur = false;
		int i = 0;
		rep(id, G[v].size()) {
			int u = G[v][id];
			if(u == par) continue; 
			if(!cur) {
				fin[v][0][cho[v][i].first & 1].push_back(u);
				cur = (cho[v][i].first >> 1);
			} else {
				fin[v][0][cho[v][i].second & 1].push_back(u);
				cur = (cho[v][i].second >> 1);
			}
			i ++;
		}
	}
	if(dpt[v].second) {
		bool cur = true;
		int i = 0;
		rep(id, G[v].size()) {
			int u = G[v][id];
			if(u == par) continue; 
			if(!cur) {
				fin[v][1][cho[v][i].first & 1].push_back(u);
				cur = (cho[v][i].first >> 1);
			} else {
				fin[v][1][cho[v][i].second & 1].push_back(u);
				cur = (cho[v][i].second >> 1);
			}
			i ++;
		}
	}
}

void findway(int v, int tp)
{
	rep(i, fin[v][tp][0].size()) findway(fin[v][tp][0][i], 0);
	printf("%d\n", v);
	rep(i, fin[v][tp][1].size()) findway(fin[v][tp][1][i], 1);
}

int main()
{
	int n, p;
	scanf("%d", &n);
	rep1(i, n) {
		scanf("%d", &p);
		if(p == 0) continue;
		G[i].push_back(p);
		G[p].push_back(i);
	}
	dfs(1, -1);
	if(!dpt[1].second) puts("NO");
	else {
		puts("YES");
		findway(1, 1);
	}
	return 0;
}