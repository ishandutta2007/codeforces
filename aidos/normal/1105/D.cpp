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

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, m, p;
int was[1010][1010];
char c[1010][1010];
vector<pii> last[11];
int mv[1010];
int T;
int L[1010][1010];
int cnt[1010];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m && was[x][y] != T && c[x][y] == '.';
}
void solve(){
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 0; i < p; i++) scanf("%d", &mv[i]);
	for(int i = 0; i < n; i++){
		scanf("%s", c[i]);
	}
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(c[i][j] == '.') continue;
			if(c[i][j] == '#') continue;
			int d = c[i][j] -'1';
			cnt[d]++;
			last[d].pb(mp(i, j));
		}
	}
	queue<pii> q;
	for(int tt = 0; tt < n * m * p; tt++) {
		int g = tt % p;
		if(last[g].size()==0) continue;
		for(int i = 0; i < last[g].size(); i++){
			q.push(last[g][i]);
		}
		last[g].clear();
		T++;
		while(q.size() > 0){
			int x = q.front().f;
			int y = q.front().s;
			q.pop();
			if(was[x][y] != T){
				was[x][y] = T;
				L[x][y] = 0;
			}
			for(int t = 0; t < 4; t++){
				int CX = x + dx[t];
				int CY = y + dy[t];
				if (good(CX, CY) && L[x][y] < mv[g]){
					was[CX][CY] = T;
					L[CX][CY] = L[x][y] + 1;
					q.push(mp(CX, CY));
					last[g].pb(mp(CX, CY));
					c[CX][CY] = '#';
					cnt[g]++;
				}
			}
		}
	}
	for(int i = 0; i < p; i++) cout << cnt[i] << " ";
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