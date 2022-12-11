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

vector<int> rb[maxn];
int cnt;
bool used[maxn];

int dfs1(int u, int h = 0) {
	if(rb[u].size() == 0) {
		return(1);
	}
	if(!(h & 1)) {
		int ans = mod;
		for(int i = 0; i < (int)rb[u].size(); i++) {
			ans = min(ans, dfs1(rb[u][i], h + 1));
		}
		return(ans);
	} else {
		int ans = 0;
		for(int i = 0; i < (int)rb[u].size(); i++) {
			ans += dfs1(rb[u][i], h + 1);
		}
		return(ans);
	}
}

int dfs2(int u, int h = 0) {
	if(rb[u].size() == 0) {
		return(1);
	}
	if(h & 1) {
		int ans = mod;
		for(int i = 0; i < (int)rb[u].size(); i++) {
			ans = min(ans, dfs2(rb[u][i], h + 1));
		}
		return(ans);
	} else {
		int ans = 0;
		for(int i = 0; i < (int)rb[u].size(); i++) {
			ans += dfs2(rb[u][i], h + 1);
		}
		return(ans);
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
	scanf("%d", &n);
	cnt=  n;
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		if(!used[u]){
			cnt--;
			used[u] = 1;
		}
		rb[u].pb(v);
	}

	cout << cnt + 1 - dfs1(0, 0) << " " << dfs2(0, 0);

	return(0);
}

// by Kim Andrey