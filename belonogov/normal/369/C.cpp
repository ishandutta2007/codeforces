#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5 + 2;
const int inf = 1e9;

vector < int > e[maxn];
vector < int > w[maxn];
bool use[maxn];
vector < int > ans;

bool dfs(int v, int flagE){
	use[v] = 1;
	bool flag = 0;
	for (int i = 0; i < (int)e[v].size(); i++)
		if (!use[e[v][i]]){
			flag |= dfs(e[v][i], w[v][i]);	
		}
	if (!flag && flagE){
		ans.pb(v);
		flag = 1;		
	}
	return flag;
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, v, u, t;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		scanf("%d%d%d", &v, &u, &t); v--; u--; t--;
		e[v].pb(u);
		w[v].pb(t);
		
		e[u].pb(v);
		w[u].pb(t);
	}
	dfs(0, 0);
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
    return 0;
}