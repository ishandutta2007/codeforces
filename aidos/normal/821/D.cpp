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

int n, m, k;
pii x[100100];
int used[100100];
int dp[100100];
void solve(){
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++)
		cin >> x[i].f >> x[i].s;
	sort(x, x + k);
	for(int i = 0; i < k; i++){
		dp[i] = inf;
	}
	dp[0] = 0;
	int ans = inf;
	for(int i = 0; i < k; i++){
		int g = -1;
		for(int t = 0; t < k; t++){
			if(used[t]) continue;
			if(g == -1 || dp[g] > dp[t]) g = t;
		}
		used[g] = 1;
		for(int t = 0; t < k; t++){
			if(used[t]) continue;
			if(x[g].f == x[t].f){
				if(abs(x[g].s-x[t].s) == 1) dp[t] = min(dp[t], dp[g]);
				else dp[t] = min(dp[t], dp[g] + 1); 
			}else if(x[g].s == x[t].s){
				if(abs(x[g].f-x[t].f) == 1) dp[t] = min(dp[t], dp[g]);
				else dp[t] = min(dp[t], dp[g] + 1); 
			}else if(abs(x[g].f-x[t].f) <=2 || abs(x[g].s-x[t].s) <= 2) {
				dp[t] = min(dp[t], dp[g] + 1); 
			}
		}
	}
	if(x[k-1] == mp(n, m)) ans = min(ans, dp[k-1]);
	for(int i = 0; i < k; i++){
		if(x[i].f == n||x[i].s==m || x[i].f == n-1||x[i].s==m-1) ans = min(ans, dp[i] + 1);
	}
	if(ans == inf) ans = -1;
	cout << ans << endl;
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}