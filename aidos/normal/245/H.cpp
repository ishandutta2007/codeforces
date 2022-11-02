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
int dp[5050][5050];
int a[5050][5050];
string s;
void solve(){
	cin >> s >> m;
	n = s.size();
	for(int i = 0; i < n; i++) a[i][i] = 1;
	for(int i = 0; i + 1< n; i++) if(s[i] == s[i+1]) a[i][i+1] = 1;
	for(int len = 2; len < n; len++){
		for(int i = len; i<n;i++){
			if(s[i] == s[i-len] && a[i-len+1][i-1]) a[i-len][i] = 1;
		}
	}
	for(int len = 0; len < n; len++){
		for(int i = len; i < n; i++){
			dp[i-len][i] = a[i-len][i];
			dp[i-len][i] += dp[i-len][i-1];
			dp[i-len][i] += dp[i-len+1][i];
			dp[i-len][i] -= dp[i-len+1][i-1];		
		}
	}
	for(int i = 0; i < m; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", dp[l-1][r-1]);
	}
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