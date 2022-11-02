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

int dp[130][(1<<16)+100];
int c[111];
int r[111];
int b[111];
char temp[111];
int cntR[(1<<16) + 10];
int cntB[(1<<16) + 10];
int n;
void solve(){
	memset(dp, -1, sizeof dp);
	queue<pair<pii,int> > pq;
	scanf("%d", &n);
	int xx = 0;
	for(int i = 0; i < n; i++){
		scanf("%s%d%d", temp, &r[i], &b[i]);
		c[i] = temp[0] == 'R' ? 1 : 0;	
		xx += c[i];
	}
	if(xx * 2 > n){
		for(int i = 0; i < n; i++){
			c[i] ^= 1;
			swap(r[i], b[i]);
		}
	}
	for(int i = 0; i < (1<<n); i++){
		for(int j = 0; j < n; j++){
			if(i & (1<<j)){
				if(c[j]) cntR[i]++;
				else cntB[i]++;
			}
		}
	}
	dp[0][0] = 0;
	pq.push(mp(mp(0, 0),0));
	while(pq.size() > 0){
		int x = pq.front().f.f;
		int y = pq.front().f.s;
		int mask = pq.front().s;
		pq.pop();
		if(dp[x][mask] < y) continue;
		for(int i = 0; i < n; i++){
			if(mask & (1<<i)) continue;
			int nmask = mask | (1<<i);
			int X = x, Y = y;
			if(r[i] >= cntR[mask]){
				X += cntR[mask];
			}
			else X += r[i];
			if(b[i] >= cntB[mask]){
				Y +=cntB[mask];
			}
			else Y += b[i];

			if(dp[X][nmask] == -1 || dp[X][nmask] < Y){
				dp[X][nmask] = Y;
				pq.push(mp(mp(X, Y), nmask));
			}
		}
	}
	int sumA = 0, sumB = 0;
	for(int i = 0; i < n; i++){
		sumA += r[i];
		sumB += b[i];
	}
	int ans = inf;
	for(int i = 0; i<=128; i++){
		if(dp[i][(1<<n) - 1] == -1) continue;
		ans = min(ans, max(sumA - i, sumB - dp[i][(1<<n) - 1]));
	}
	printf("%d\n", ans + n);
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}