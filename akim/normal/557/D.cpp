#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

bool us[maxn], pm[maxn], now[maxn];
vector<int> rb[maxn];
set<int> st[maxn];

ll cnt1, cnt2;

int tim[maxn], nx[maxn], pr[maxn];
bool t = 0;

void dfs(int u) {
	pm[u] = 1;
	tim[u] = t;
	t = !t;
	if(t & 1) cnt1++; else cnt2++;
	now[u] = 1;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		if(!pm[v]) {
			nx[u] = v;
			pr[v] = u;
			dfs(v);
			t = 1 - tim[u];
		} else {
			if((tim[u]) == (tim[v])) {
				printf("0 1");
				exit(0);
			}
		}
	}
	now[u] = 0;
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	ll n, m;
	scanf("%I64d%I64d", &n, &m);
	if(m == 0) {
		printf("3 %I64d", (n) * (n - 1) * (n - 2) / 6);
		return(0);
	}

	bool ok = 0;
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);

		if(us[u] == 1) ok = 1;
		us[u] = 1;

		if(us[v] == 1) ok = 1;
		us[v] = 1;

		rb[u].pb(v);
		st[u].insert(v);
		rb[v].pb(u);
		st[v].insert(u);
	}

	if(!ok) {
		printf("2 %I64d", m * (n - 2));
		return(0);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!pm[i]) {
			cnt1 = cnt2 = 0;
			dfs(i);
			if(cnt1 == 0) cnt1++;
			if(cnt2 == 0) cnt2++;
			ans = (ans + ((cnt1 * (cnt1 - 1)) >> 1) + ((cnt2 * (cnt2 - 1)) >> 1));
		}
	}

	printf("1 %I64d", ans);

	return(0);
}

// by Kim Andrey