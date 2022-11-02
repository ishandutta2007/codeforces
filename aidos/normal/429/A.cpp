#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
vector < int > ans;
int n;
vector < int > v[111111];
bool used[111111];
int init[111111];
int goal[111111];
void dfs(int g, int c1, int c2){
	used[g] = 1;
	int ok;
	if((init[g] + c1) % 2 != goal[g]){
		ans.pb(g);
		c1++;
	}
	for(int i = 0; i < v[g].size(); i++){
		int to = v[g][i];
		if(!used[to]) {
			dfs(to, c2, c1);
		}
	}
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 1; i< n; i++){
    	int x, y;
    	scanf("%d%d", &x, &y);
    	x--;
    	y--;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    for(int i = 0;i<n; i++){
    	scanf("%d",&init[i]);
    }

    for(int i = 0;i<n; i++){
    	scanf("%d",&goal[i]);
    }

    dfs(0, 0, 0);
    cout << ans.size()<<endl;
    for(int i = 0;i<ans.size(); i++)
    	cout << ans[i]+1 << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}