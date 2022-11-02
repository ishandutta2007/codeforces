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

const int inf = (1ll << 25) - 1;
const int maxn = (int)3e3+20;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
int dp[maxn][maxn];
int mx[maxn];
int mi[maxn];
int p[maxn];
int ans = 0;
queue<pii> q;
void add(int x, int y, int dis) {
	if(dis > m) return;
	x = min(x, n);
	y = min(y, n);
	if(dp[x][y] == -1) {
		dp[x][y] = dis;
		q.push(mp(x, y));
		ans++;
	}
}
void solve(){
	scanf("%d%d", &n, &m);
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	mx[n-1] = mi[n-1] = p[n-1];
	for(int i = n-2; i >= 0; i--) {
		mx[i] = max(mx[i+1], p[i]);
		mi[i] = min(mi[i+1], p[i]);
	}
	add(0, 1, 0);
	while(q.size() > 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int dis = dp[x][y] + 1;
		if(y >= n) continue;
		if(p[x] > 0 && mx[y] > 0) {
			add(y+1, y+2, dis);
		}
		if(p[x] < 100 && mx[y] > 0) {
			add(y, y + 1, dis);
		}
		if(p[x] > 0 && mx[y] < 100) {
			add(x, y+1, dis);
		}
	}
	cout << ans << "\n";
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