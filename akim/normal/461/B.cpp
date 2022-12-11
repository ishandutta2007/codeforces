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

vector<int> rb[100100];
long long x[100100];

pair<long long, long long> dfs(long long u) {
	pair<long long, long long> pu = mp(1, 0);
	for(int i = 0; i < rb[u].size(); i++) {
		pair<int, int> pv = dfs(rb[u][i]);
		pu.sc *= pv.fs; pu.sc %= mod;
		pu.sc += pu.fs * pv.sc; pu.sc %= mod;
		pu.fs *= pv.fs; pu.fs %= mod;
	}
	if(x[u]) {
		pu.sc = pu.fs;
	} else {
		pu.fs += pu.sc; pu.fs %= mod;
	}
//	printf("%I64d  %I64d %I64d\n", u, pu.fs, pu.sc);
	return(pu);
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	long long n; scanf("%I64d", &n);
	for(int i = 1; i < n; i++) {
		long long u;
		scanf("%I64d", &u);
		rb[u].pb(i);
	}
	for(int i = 0; i < n; i++) {
		scanf("%I64d", &x[i]);
	}
	pair<long long, long long> p = dfs(0);
	printf("%I64d", p.sc);
	
	return(0);
}

// by Kim Andrey