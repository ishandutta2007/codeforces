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
#include <bitset>

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
int n, k;
int dp[2][200100];
string s[2];
queue<pii> q;
void solve(){
	cin >> n >> k >> s[0] >> s[1];
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	q.push(mp(0, 0));
	while(q.size() > 0) {
		int x=q.front().f, y = q.front().s;
		q.pop();
		if(dp[x][y] > y) continue;
		if(s[x][y] == 'X') continue;
		if(y+k >= n) {
			cout << "YES";
			return;
		}
		if(dp[x^1][y+k] == -1) {
			dp[x^1][y+k] = dp[x][y]+1;
			q.push(mp(x^1, y+k));
		}
		if(dp[x][y+1] == -1) {
			dp[x][y+1] = dp[x][y]+1;
			q.push(mp(x, y+1));
		}
		if(y > 0 && dp[x][y-1] == -1) {
			dp[x][y-1] = dp[x][y]+1;
			q.push(mp(x, y-1));
		}
	}
	cout << "NO";
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