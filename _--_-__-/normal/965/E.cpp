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

struct s_set
{
	multiset<int> s;
	int d;
	s_set()
	{
		s.clear();
		d = 0;
	}
	s_set(const s_set& oth)
	{
		s = oth.s;
		d = oth.d; 
	}
	void add(int x)
	{
		d += x;
	}
	void push(int v)
	{
		s.insert(v - d);
	}
	int size()
	{
		return s.size();
	}
	bool empty()
	{
		return s.empty();
	}
	int maxi()
	{
		return d + *s.rbegin(); 
	}
	int mini()
	{
		return d + *s.begin();
	}
	void pop()
	{
		s.erase(s.find(*s.rbegin()));
	}
	void merge(s_set& oth)
	{
		while(!oth.empty())
		{
			push(oth.maxi());
			oth.pop();
		}
	}
};

void update(s_set& s)
{
	if(s.empty()) return;
	if(s.mini() > 0) {
		s.pop();
		s.push(0);
	}
	s.add(1);
}

int son[100005][26];
bool hv[100005];
int sz[100005];
int id[100005], cnt;
s_set st[100005];

void dfs(int v)
{
	int mu = -1;
	sz[v] = hv[v];
	rep(i, 26) {
		int u = son[v][i];
		if(u == -1) continue;
		dfs(u);
		if(mu == -1 || sz[u] > sz[mu]) mu = u;
		sz[v] += sz[u];
	}
	if(mu == -1) id[v] = cnt ++;
	else {
		update(st[id[mu]]);
		id[v] = id[mu];
		rep(i, 26) {
			int u = son[v][i];
			if(u == -1 || u == mu) continue;
			update(st[id[u]]); 
			st[id[v]].merge(st[id[u]]);
		}
	}
	if(hv[v]) st[id[v]].push(0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(son, -1, sizeof(son));
	int n, sv = 1;
	string s;
	cin >> n;
	rep(i, n) {
		cin >> s;
		int cur = 0;
		rep(i, s.length()) {
			int id = s[i] - 'a';
			if(son[cur][id] == -1) son[cur][id] = sv ++;
			cur = son[cur][id];
		}
		hv[cur] = true;
	}
	dfs(0);
	s_set ans = st[id[0]];
	LL ret = 0;
	while(!ans.empty()) {
		ret += ans.maxi();
		ans.pop();
	}
	cout << ret << '\n';
	return 0;
}