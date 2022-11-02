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
const int maxn = (int) 2000+20;
const int mod = (int) 1e9 + 7;
const int maxd = (int) 700700;
using namespace std;
int n, h;
int a[maxn];
int dp[maxn][maxn];
void add(int &v, int u) {
	v += u;
	if(v >= mod) v -= mod;
}
int rec(int p, int val) {
	if(p == n) {
		if(val > 0) return 0;
		return 1;
	}
	int &res = dp[p][val];
	if(res != -1) return res;
	res = 0;
	if(a[p] + val == h) {
		add(res, rec(p+1, val));
		if(val > 0) {
			add(res, rec(p+1, val-1) * 1ll * val % mod);
		}
	}
	if(a[p] + val + 1 == h) {
		add(res, rec(p+1, val + 1));
		add(res, rec(p+1, val) * 1ll * (val+1) % mod);
	}
	return res;
}
void solve(){
	memset(dp, -1, sizeof dp);
	scanf("%d%d", &n, &h);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	cout << rec(0, 0) << "\n";
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