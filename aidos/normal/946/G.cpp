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
int a[200200];
int b[400200];
int t[2][400200];
int k;
int n;

int get(int id, int p){
	int res = 0;
	while(p >= 0){
		res = max(res, t[id][p]);
		p = (p&(p+1)) - 1;
	}
	return res;
}
void upd(int id, int p, int v){
	while(p < k){
		t[id][p] = max(t[id][p], v);
		p|=p+1;
	}
}
void solve(){
	scanf("%d", &n);
	int sz = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[sz++] = a[i] - i;
		b[sz++] = a[i] - i + 1;
	}
	sort(b, b + sz);
	k = unique(b, b + sz) - b;
	int ans = 0;
	int cx = 0;
	int la = 0;
	for(int i = 0; i < n; i++){
		int x = lower_bound(b, b + k, a[i] - i) - b;
		int y = lower_bound(b, b + k, a[i] - i + 1) - b;
		int c = get(1, y) + 1;
		upd(1, y, c);
		upd(1, la, cx);
		c = get(0, x)+1;
		upd(0, x, c);
		la = x;
		cx = c;
	}
	ans = max(get(1, k-1), get(0, k-1));
	if(ans == n) ans = 0;
	else ans = n - 1 - ans;
	cout << ans << endl;
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