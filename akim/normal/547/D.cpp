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

vector<int> px[maxn], py[maxn];
vector<int> rb[maxn];
bool ans[maxn];
bool pm[maxn];

void dfs(int u, int col = 0) {
	pm[u] = 1;
	ans[u] = col;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		if(!pm[rb[u][i]]) {
			dfs(rb[u][i], 1 - col);
		}
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
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(px[x].size() & 1) {
			rb[px[x].back()].pb(i);
			rb[i].pb(px[x].back());
		}
		px[x].pb(i);
		if(py[y].size() & 1) {
			rb[py[y].back()].pb(i);
			rb[i].pb(py[y].back());
		}
		py[y].pb(i);
	}

	for(int i = 0; i < n; i++) {
		if(!pm[i]) {
			dfs(i);
		}
	}

	for(int i = 0; i < n; i++) {
		printf("%c", ans[i] ? 'r' : 'b');
	}

	return(0);
}

// by Kim Andrey