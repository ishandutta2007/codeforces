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
ll t[4*300300];
int g[4*300300];
int a[300300];
int pr[2000100];
const int N = 2000*1000;
int dp[2000200];

void precalc(){
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j += i){
			++pr[j];
		}
	}
	int c = 0;
	for(int i = 1; i <= N; i++){
		if(pr[i] == i) dp[i] = 0;
		else dp[i] = dp[pr[i]] + 1;
		c = max(dp[i], c);
	}
	//cout << c << endl;
}
int n, m;

void build(int v, int l, int r){
	if(l == r){
		t[v] = a[l];
		g[v] = (pr[a[l]] != a[l]);
	}
	else{
		int mid = (l + r)>>1;
		build(v * 2, l, mid);
		build(v * 2+1, mid+1, r);
		g[v] = g[v*2] + g[v*2+1];
		t[v] = t[v*2] + t[v*2+1];
	}
}
void upd(int v, int l, int r, int tl, int tr){
	if(l > tr || r < tl) return;
	if(g[v] == 0) return;
	if(l == r){
		t[v] = pr[t[v]];
		g[v] = t[v] != pr[t[v]];
	}
	else {
		int mid = (l + r)>>1;
		upd(v * 2, l, mid, tl, tr);
		upd(v * 2+1, mid+1, r, tl, tr);
		g[v] = g[v*2] + g[v*2+1];
		t[v] = t[v*2] + t[v*2+1];
	}
}
ll get(int v, int l, int r, int tl ,int tr){
	if(l > tr || r < tl) return 0;
	if(tl <= l && r <= tr){
		return t[v];
	}
	int mid = (l + r)>>1;
	return get(v * 2, l, mid, tl, tr) + get(v * 2+1, mid+1, r, tl, tr);
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for(int i = 0, x, l, r; i < m; i++){
		scanf("%d%d%d", &x, &l, &r);
		if(x == 1){
			upd(1, 1, n, l, r);
		}
		else {
			printf("%I64d\n", get(1, 1, n, l, r));
		}
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
	precalc();
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}