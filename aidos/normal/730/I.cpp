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

int dp[3030][3030];
int d[3030][3030];
int n, p, s;
pair< pii, int> a[3030];

int get(int p, int x){
	if(x < 0) return -inf;
	if(p < 0) {
		if(x == 0) return 0;
		return -inf;
	}
	int &res = dp[p][x];
	if(res != -1) return res;
	res = -inf;
	res = max(get(p-1, x-1) + a[p].f.f, res);
	res = max(get(p-1, x) + a[p].f.s, res);
	return res;
}
int get2(int p, int x){
	if(x < 0) return -inf;
	if(p == n) {
		if(x == 0) return 0;
		return -inf;
	}
	int &res = d[p][x];
	if(res != -1) return res;
	res = -inf;
	res = max(get2(p+1, x-1) + a[p].f.s, res);
	res = max(get2(p+1, x), res);
	return res;
}
vector<int> ans1, ans2;
void rec(int p, int x){
	if(p < 0) return;
	int res = get(p, x);
	if(res == get(p - 1, x -1) + a[p].f.f){
		rec(p-1, x-1);
		ans1.pb(a[p].s + 1);
		return;
	}
	rec(p-1, x);
	ans2.pb(a[p].s + 1);
}
void rec2(int p, int x){
	if(x == 0 || p == n) return;
	int res = get2(p, x);
	if(res == get2(p + 1, x-1) + a[p].f.s){
		ans2.pb(a[p].s + 1);
		rec2(p + 1, x-1);
		return;
	}
	rec2(p + 1, x);
}
void solve(){
	scanf("%d%d%d", &n, &p, &s);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].f.f);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].f.s);
		a[i].s = i;
	}
	sort(a, a + n);
	reverse(a, a + n);
	memset(dp, -1, sizeof dp);
	memset(d, -1, sizeof d);
	int ans=-inf;
	for(int i = p-1; i < p + s; i++){
		int x = i - p + 1;
		ans = max(ans, get(i, p) + get2(i + 1, s - x));
	}
	for(int i = p - 1; i < p + s; i++){
		int x = i - p + 1;
		if(ans == get(i, p) + get2(i + 1, s-x)){
			rec(i, p);
			rec2(i+1, s-x);
			break;
		}
	}
	cout <<ans << endl;
	for(int i = 0; i < ans1.size(); i++)
		cout << ans1[i] << " ";
	cout << endl;
	for(int i = 0; i < ans2.size(); i++)
		cout << ans2[i] << " ";
	cout << endl;
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