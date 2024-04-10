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

const int maxn = 3e3;
const int inf = 1e9;

bool a[maxn];
bool b[maxn];
vector < int > e[maxn];
int to[maxn];
int use[maxn];
int t = 0;

bool dfs(int v){
    if (use[v] == t)
	return 0;
    use[v] = t;
    for(int i = 0; i < (int)e[v].size(); i++){
	if (to[e[v][i]] == -1){
	    to[e[v][i]] = v;
	    return 1;
	}
	if (dfs(to[e[v][i]])){
	    to[e[v][i]] = v;
	    return 1;	    
	}
    }
    return 0;
}

int main(){
//    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, ans = 0, x, y;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
	scanf("%d%d", &x, &y); x--; y--;
	a[x] = 1;
	b[y] = 1;    
    }
    for(int i = 1; i < n - 1; i++){
	ans += !a[i];
	ans += !b[i];
    }
    ans -= (n % 2 == 1 && !a[n / 2] && !b[n / 2]);
    cout << ans << endl;
//     epr("a: ");
//     for(int i = 0; i < n; i++)
// 	epr("%d ", a[i]);
//     epr("\n");
//     epr("b: ");
//     for(int i = 0; i < n; i++)
// 	epr("%d ", b[i]);
//     epr("\n");
    
//     for(int i = 1; i < n - 1; i++){
// 	if (!a[i]) e[i].pb(i);
// 	if (!a[n - 1 - i]) e[i].pb(n - 1 - i);
// 	if (!b[i]) e[i].pb(i + n);
// 	if (!b[n - 1 - i]) e[i].pb(n - 1 - i + n);
//     }
//     memset(to, -1, sizeof(to));
//     for(int i = 1; i < n - 1; i++){
// 	epr("%d: ", i);
// 	for(int j = 0; j < (int)e[i].size(); j++)
// 	    epr("%d ", e[i][j]);
// 	epr("\n");
//     }
/*    
    for(int i = 1; i < n - 1; i++){
	t++;
	ans += dfs(i);
    }
    cout << ans << endl;
    */
    
    
    return 0;
}