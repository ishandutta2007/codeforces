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

int k, q;

double dp[1020];
double d[1020];
int used[1020];
int cur = 0;
int ans[1020];

bool ok(double x, double y){
	if(x >= y) return 1;
	return abs(x-y) < 1e-8;
}

void solve(){
	cin >> k >> q;
	dp[0] = 1;
	cur = 1;
	for(int i = 1; cur <= 1000; i++){
		for(int j = 0; j <= k; j++){
			d[j] = dp[j];
			dp[j] = 0;
		}
		for(int j = 1; j<=k; j++){
			dp[j] = d[j] * (j+0.0)/k + d[j-1] * (k-j + 1)/k;
		}
		while(cur <= 1000){
			if(ok(dp[k] * 2000.0, cur)){
				ans[cur] = i;
				cur++;
			}
			else break;
		}
	}
	for(int i = 0, p; i < q; i++){
		cin>>p;
		cout << ans[p] << endl;
	}
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