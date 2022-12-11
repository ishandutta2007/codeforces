#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

vector<int> rb[100100], vc;
int x[100100];

void dfs(int u) {
	vc.pb(u);
	x[u]--;
	for(int i = 0; i < rb[u].size(); i++) {
		x[rb[u][i]]--;
	}
	for(int i = 0; i < rb[u].size(); i++) {
		if(x[rb[u][i]] == 0) {
			dfs(rb[u][i]);
		}
	}
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int n, m; scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		rb[u].pb(v);
		rb[v].pb(u);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}

	for(int i = 1; i <= n; i++) {
		if(x[i] == 0) {
			dfs(i);
		}
	}

	printf("%d\n", vc.size());
	for(int i = 0; i < vc.size(); i++) {
		printf("%d ", vc[i]);
	}

	return(0);
}

// by Kim Andrey