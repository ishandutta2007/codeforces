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
const int maxn = (int) 3e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int k;
int b[maxn];
vector<int> rec(int l, int r) {
	vector<int> dp;
	for(int i = 0; i < 4; i++) {
		dp.pb(-inf);
	}
	dp[0] = 0;
	if(l == r) {
		int v1 = b[l*2];
		int v2 = b[l*2+1];
		if(v1 && v2) {
			dp[3] = 1;
			return dp;
		}
		if(v1 || v2) {
			dp[2] = 1;
			dp[1] = 1;
			return dp;
		}
		return dp;
	}
	int mid = (l+r)/2;
	vector<int> ldp = rec(l, mid);
	vector<int> rdp = rec(mid+1, r);
	for(int m1 = 0; m1 < 4; m1++) {
		for(int m2 = 0; m2 < 4; m2++) {
			int x1=m1&2, x2 = m1&1, y1 = m2&2, y2 = m2&1;
			
			for(int j = 0; j < 2; j++) {
				int cur = ldp[m1] + rdp[m2];
				if(x1||y1) {
					cur++;
				}
				if(x2 || y2) {
					cur++;
				}
				int c1 = x1, c2 = y1;
				if(j&1) {
					c1 = x1;
					c2 = y1;
				}else {
					c1 = y1;
					c2 = x1;
				}
				int val = (c1>0) * 2;
				if(x2 || y2 || c2) {
					val++;
					cur++;
				} else {

				}
				dp[val] = max(cur, dp[val]);
			}
		}
	}
	return dp;
}
void solve(){
	scanf("%d%d", &n, &k);
	n = (1<<n);
	for(int i = 0; i < k; i++){
		int x;
		scanf("%d", &x);
		b[x-1] = 1;
	}
	vector<int> dp = rec(0, n/2-1);
	int ans = dp[0];
	for(int i = 1; i < dp.size(); i++) {
		ans = max(ans, dp[i] + 1);
	}
	cout << ans << "\n";
}

int main () {
	srand(time(0));
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}