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
int n, m;
int a[111], b[111], c[111], d[111];
int dp[1111][12];
int u[1111][12];
int get(int x, int y) {
	if(x < 0) return -inf;
	if(y == 0) {
		return (x/c[y]) * d[y];
	}
	if(u[x][y]) return dp[x][y];
	u[x][y] = 1;
	for(int i = 0; i <= a[y]/b[y]; i++){
		dp[x][y] = max(get(x-i*c[y], y-1) + i * d[y], dp[x][y]);
	}
	return dp[x][y];
}
void solve(){
	cin >> n >> m >> c[0] >> d[0];
	for(int i = 1;  i<=m;i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	cout << get(n, m) << "\n";
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