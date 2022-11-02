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

const int inf = (1 << 29) - 1;
const int maxn = (int)3e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m, k;
vector<int> g[2020];
int col[2020][1010];
pii e[maxn];
int ans[maxn];

void dfs(int v, int cur, int nxt) {
	if(col[v][cur] == 0) {
		return;
	}
	int val = col[v][cur];
	col[v][cur] = 0;
	col[e[val].f^e[val].s^v][cur] = 0;
	dfs(e[val].f^e[val].s^v, nxt, cur);
	col[v][nxt] = val;
	col[e[val].f^e[val].s^v][nxt] = val; 
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		y += n;
		e[i] = mp(x, y);
	}
	n += m;
	for(int i = 1; i <= k; i++) {
		int u = e[i].f;
		int v = e[i].s;
		int c1 = 1; 
		while(col[u][c1]) ++c1;
		int c2 = 1;
		while(col[v][c2]) ++c2;
		if(c1>c2) {
			swap(u, v);
			swap(c1, c2);
		}
		if(c1 == c2) {
			col[u][c1] = col[v][c2] = i;
			continue;
		}
		dfs(v, c1, c2);
		col[v][c1] = i;
		col[u][c1] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < 1010; j++) {
			ans[col[i][j]] = j;
		}
	}
	cout << *max_element(ans + 1, ans + k + 1) << "\n";
	for(int i=1; i <= k; i++) {
		cout << ans[i] << " ";
	}
}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}