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
const int mod = (int) 1e9 + 7;
using namespace std;

int n, l, r;
int c[123];
int dp[300100][3];
void solve(){
	scanf("%d%d%d", &n, &l, &r);
	while(l % 3 != r % 3) {
		c[l % 3]++;
		l++;
	}
	c[l%3]++;
	l++;
	for(int i = 0; i < 3; i++) c[i] += (r + 1 - l)/3;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++){
				dp[i][(j + k) % 3] = (dp[i][(j + k) % 3] + dp[i-1][j] * 1ll * c[k]) % mod;
			}
		}
	}
	cout << dp[n][0] << "\n";
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