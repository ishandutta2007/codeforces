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
const int maxn = (int) 2e5 + 10;
const int mod1 = (int) 1031564197;
const int mod2 = (int) 1021342139;
const ll pr1 = 31;
const ll pr2 = 73;
using namespace std;
int n, m;
pair<int, int> dp[26][maxn];

int nxt[26][maxn];
ll P1[maxn], P2[maxn];
pair<int, int> sub(pair<int, int> a, pair<int, int> b, int len) {
	return mp((a.f - b.f * P1[len] % mod1 + mod1) % mod1, (a.s - b.s * P2[len] % mod2 + mod2) % mod2);
}
int ok(int l, int r, int y, int z) {
	vector<pair<int, int> > a, b;
	for(int i = 0; i < 26; i++) {
		if(nxt[i][l] <= r) a.push_back(mp(nxt[i][l]-l, i));
		if(nxt[i][y] <= z) b.push_back(mp(nxt[i][y]-y, i));
	}
	if(a.size() != b.size()) return 0;
	sort(all(a));
	sort(all(b));
	for(int i = 0; i < a.size(); i++) {
		if(a[i].f!=b[i].f) return 0;
		pair<int, int> c = sub(dp[a[i].s][l], dp[a[i].s][r+1], r-l+1);
		pair<int, int> d = sub(dp[b[i].s][y], dp[b[i].s][z+1], r-l+1);
		if(c!=d) return 0;
	}
	return 1;
}
int main () {
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i < 26; i++) nxt[i][n] = n;
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < 26; j++) {
			if(s[i] - 'a' != j) {
				nxt[j][i] = nxt[j][i+1];
				dp[j][i] = mp(dp[j][i+1].f * pr1 % mod1, dp[j][i+1].s * pr2 % mod2);
			}
			else {
				dp[j][i] = mp((dp[j][i+1].f * pr1 % mod1+1) % mod1, (dp[j][i+1].s * pr2 % mod2+1) % mod2);
				nxt[j][i] = i;
			}
		}
	}
	P1[0] = 1;
	P2[0] = 1;
	for(int i = 1; i <= n; i++) {
		P1[i] = P1[i-1] * pr1 % mod1;
		P2[i] = P2[i-1] * pr2 % mod2;
	}
	for(int i = 0; i < m; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		if(ok(x-1, x - 1 + l -1, y-1, y-1+l-1)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
    return 0;
}