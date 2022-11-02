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

int n, m, k;

map< pair< pii, pii> ,ll > mm;

int x[100100], y[100100];
void go(int x, int y, int dx, int dy, ll ti){
	if(mm.count(mp(mp(x, y), mp(dx, dy)))) return;
	mm[mp(mp(x, y), mp(dx, dy))] = ti;
	if(ti){
		if(x == 0 && y == 0) return;
		if(x == 0 && y == m) return;
		if(x == n && y == 0) return;
		if(x == n && y == m) return;
	}
	ll l = 0, r = 2e5, res = 0;
	while(l <= r){
		int mid = (l + r)>>1;
		int X = x + mid * dx;
		int Y = y + mid * dy;
		if(X >= 0 && X <= n && Y>=0 && Y<=m){
			res = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	int X = x + dx * res;
	int Y = y + dy * res;
	if(X+dx < 0 || X + dx > n) dx *= -1;
	if(Y + dy < 0 || Y + dy > m) dy *= -1;
	go(X, Y, dx, dy, ti + res);
}

ll cur = inf * 1ll * inf;

ll getans(int x, int y, int dx, int dy){
	ll l = 0, r = 2e5, res = 0;
	while(l <= r){
		int mid = (l + r)>>1;
		int X = x + mid * dx;
		int Y = y + mid * dy;
		if(X >= 0 && X <= n && Y>=0 && Y<=m){
			res = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	int X = x + dx * res;
	int Y = y + dy * res;
	dx *= -1;
	dy *= -1;
	if(!mm.count(mp(mp(X, Y), mp(dx, dy)))) return cur;
	ll ti = mm[mp(mp(X, Y), mp(dx, dy))];
	return ti + res;
}
void solve(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	go(0, 0, 1, 1, 0);
	for(int i = 0; i < k; i++){
		ll ans = cur;
		ans = min(ans, getans(x[i], y[i], 1, 1));
		ans = min(ans, getans(x[i], y[i], 1, -1));
		ans = min(ans, getans(x[i], y[i], -1, 1));
		ans = min(ans, getans(x[i], y[i], -1, -1));
		if(ans < cur){
			printf("%I64d\n", ans);
		}
		else {
			printf("-1\n");
		}
	}
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