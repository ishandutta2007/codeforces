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
#include <unordered_map>

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
int n, m, q;
bool a[5005][5005];
int L = 5000;
string s;
int S[5005][5005];

pll dp[66];
int col[66];

int getColor(int x) {
	int need = 0;
	for(int i = 30; i >= 0; i--) {
		if((1<<i) <= x) {
			x -= 1<<i;
			need ^= 1;
		}
	}
	return need;
}
pll get3(ll x, ll b, ll w) {
	dp[0] = mp(b, w);
	for(int i = 1; i <= 60; i++) {
		dp[i] = mp(dp[i-1].f + dp[i-1].s,dp[i-1].s + dp[i-1].f);
	}
	ll need = 0;
	pll res = mp(0, 0);
	for(int i = 60; i >= 0; i--) {
		if((1ll<<i) <= x) {
			if(need) res.f += dp[i].s, res.s += dp[i].f;
			else res.f+= dp[i].f, res.s += dp[i].s;
			x -= 1ll<<i;
			need ^= 1;
		}
	}
	return res;
}
ll get2(ll x, ll y, ll b, ll w) {
	pll cur = get3(y, b, w);
	//out << cur.f << " "<<cur.s << "\n";
	pll cur2 = get3(x, cur.f, cur.s);
	return cur2.f;
}
ll get(ll x, ll y) {
	if(x == 0 || y == 0) return 0;
	if(x <= n && y <=m) {
		return S[x][y];
	}
	ll ans = get2(x/n, y/m, S[n][m], n * m - S[n][m]);
	//cout << ans << "\n";
	int rev1 = getColor(x/n);
	int rev2 = getColor(y/m);
	int rev = (rev1 + rev2) % 2;
	int xx = x % n;
	int yy = y % m;
	if(rev) {
		ans += xx * yy - S[xx][yy];
	}
	else ans += S[xx][yy];
	if(rev2) {
		ans += get2(x/n, 1, n * yy - S[n][yy], S[n][yy]);
	}else {
		ans += get2(x/n, 1,  S[n][yy], n * yy - S[n][yy]);
	}
	
	if(rev1) {
		ans += get2(y/m, 1,   xx * m - S[xx][m], S[xx][m]);
		
	}else {
		ans += get2(y/m, 1,  S[xx][m], xx * m - S[xx][m]);
	}
	return ans;
}
void solve(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < m; j++) a[i][j] = s[j] - '0';
	}

	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i-1][j-1];
		}
	}
	for(int i = 0; i < q; i++){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ll ans = get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
		cout << ans << "\n";
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