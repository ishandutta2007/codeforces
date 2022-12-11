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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 2 * 100100;

ll w[maxn], ans[maxn][2];
vector<int> rb[maxn];

void dfs(int u) {
	if(rb[u].size() == 0) {
		ans[u][0] = 0;
		ans[u][1] = -1;
		return;
	}
	ans[u][0] = 0;
	ans[u][1] = -1;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		dfs(v);
		ll cc0 = ans[u][0];
		ll cc1 = ans[u][1];
		ans[u][0] = max(ans[u][0], max(((cc1 != -1) ? (ans[v][0] + w[v] + cc1) : (0)), max(ans[v][0] + cc0, (((cc1 != -1) && (ans[v][1] != -1)) ? (ans[v][1] + cc1) : (0)))));
		ans[u][1] = max(ans[u][1], max(ans[v][0] + w[v] + cc0, max(((ans[v][1] != -1) ? (ans[v][1] + cc0) : (0)), ((cc1 != -1) ? (ans[v][0] + cc1) : (0)))));
	}
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n;
	scanf("%d%*d%I64d", &n, &w[0]);
	for(int i = 1; i < n; i++) {
		int p;
		scanf("%d%I64d", &p, &w[i]);
		rb[p - 1].pb(i);
	}

	dfs(0);

	cout << max(ans[0][0] + w[0], ans[0][1]);

	return(0);
}

// by Kim Andrey