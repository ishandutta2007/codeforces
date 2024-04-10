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
ll dp[2020][4040];
int t[4040];
int c[4040];
int u[2020][4040];
ll get(int p, int cur){
	cur = min(cur, n);
	if(p == n) {
		if(cur>=0) return 0;
		return -(1ll<<50);
	}
	if(u[p][cur+n]) return dp[p][cur+n];
	u[p][cur+n] = 1;
	dp[p][cur+n] = get(p+1, cur-1) + c[p];
	dp[p][cur+n] = max(dp[p][cur+n], get(p+1, cur+t[p]));
	return dp[p][cur+n];
}
void solve(){
	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n;i++) {
		cin >> t[i] >> c[i];
		sum += c[i];
	}
	
	cout << sum - get(0, 0) << "\n";
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