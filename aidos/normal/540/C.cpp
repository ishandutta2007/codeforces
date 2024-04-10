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
#include <ctime>
#include <bitset>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
char c[555][555];
int u[555][555];
int sx, sy, fx, fy;
int ok(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m) return 0;
	if(sx ==x && sy == y) return 1;
	return c[x][y] == '.';
}
void dfs(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m) return;
	if(u[x][y]) return;
	u[x][y] = 1;
	if(x == fx && y == fy) {
	
		int g = ok(x+1, y) + ok(x-1, y) + ok(x, y-1) + ok(x, y+1);
		if(c[x][y] == 'X') {
			if(g>=1){
				cout << "YES\n";
				exit(0);
			}
		}
		if(g>=2) {
			cout << "YES\n";
			exit(0);
		}
	}
	if(c[x][y] == 'X' && (sx != x || sy != y)) return;
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y-1);
	dfs(x, y+1);
	
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> c[i];
	cin >> sx >> sy >> fx >> fy;
	sx--;
	sy--;
	fx--;
	fy--;
	dfs(sx, sy);
	cout << "NO\n";
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}