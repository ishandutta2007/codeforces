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
const int maxn = (int) 1e7 + 10;
const int mod = (int) 1e9 + 7;
const int maxd = (int) 700700;
using namespace std;
pair<int, int> a;
pair<int, int> b;
pair<int, int> c[4][4];
pair<int, int> rot(pair<int, int> x, pair<int, int> y) {
	y.f -= x.f;
	y.s -= x.s;
	return make_pair(x.f - y.s, x.s + y.f);
}
ll sqr(ll x) {
	return x * x;
}
int ok(vector< pair<int, int> > a) {
	vector<ll> dis;
	for(int i = 0; i < a.size(); i++) {
		for(int j =i + 1; j < a.size(); j++) {
			dis.pb(sqr(a[i].f - a[j].f) + sqr(a[i].s - a[j].s));
		}
	}
	sort(all(dis));
	if(dis[0] != dis[3]) return 0;
	if(dis[4] != dis[5]) return 0;
	if(dis[0] * 2 != dis[4]) return 0;
	return dis[0] > 0;
}
void solve(){
	for(int i = 0; i < 4; i++) {

		cin >> b.f >> b.s;
		cin >> a.f >> a.s;
		c[i][0] = b;
		for(int j = 1; j < 4; j++) {
			c[i][j] = rot(a, c[i][j-1]);
		}
	}
	int ans = 1<<30;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				for(int t = 0; t < 4; t++) {
					if(ok({c[0][i], c[1][j], c[2][k], c[3][t]})) ans = min(ans, i + j + k + t);
				}
			}
		}
	}

	if(ans > 100) ans = -1;
	cout << ans << "\n";
}

int main () {
    int t=1;
   	scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}