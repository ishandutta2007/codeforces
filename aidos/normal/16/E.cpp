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
int n, m;
double dp[(1<<20)];
double a[21][21];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0;j < n; j++) cin >> a[i][j];
	}
	dp[(1<<n)-1] = 1;
	for(int mask = (1<<n)-1; mask > 0; mask--){
		int d = __builtin_popcount(mask);
		int h = d * (d-1)/2;
		for(int i = 0; i < n; i++){
			if(mask & (1<<i)) {
				for(int j = i+1; j < n; j++){
					if(mask & (1<<j)) {
						dp[mask^(1<<j)] += dp[mask] * a[i][j]/h;
						dp[mask^(1<<i)] += dp[mask] * a[j][i]/h;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++) printf("%.12lf ", dp[(1<<i)]);
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