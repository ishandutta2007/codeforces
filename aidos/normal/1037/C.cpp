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
char c[1000100];
char t[1000100];
int n;
int dp[1000100][2];
void solve(){
	scanf("%d%s%s", &n, c, t);
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++)	dp[i][j] = inf;
	}
	dp[0][1-(c[0] - '0')] = 1;
	dp[0][(c[0] - '0')] = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 2; j++){
			dp[i][j] = min(dp[i][j], dp[i-1][t[i-1] - '0'] + (c[i]-'0' != j));
		}
		if(c[i] == t[i-1]){
			for(int j = 0; j < 2; j++){
				dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
			}
		}
	}
	cout << dp[n-1][t[n-1] - '0'] << "\n";
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