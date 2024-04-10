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

string s;
int dp[27][5050][27];
int ok[27];
void solve(){
	cin >> s;
	int n = s.size();
	s += s;
	for(int i = 0; i < n; i++){
		for(int j = 1; j < n; j++){
			dp[s[i] - 'a'][j + 1][s[i + j]-'a']++;
		}
		ok[s[i] - 'a'] = 1;
	}
	int ans = 0;
	for(int i = 0; i < 26; i++){
		if(!ok[i]) continue;
		int mx = 0;
		for(int j = 1; j <= n; j++){
			int cnt = 0;
			for(int k = 0; k < 26; k++) if(dp[i][j][k] == 1) cnt++;
			mx = max(mx, cnt);
		}
		ans += mx;
	}
	printf("%.15lf\n", ((double)ans)/(n));
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