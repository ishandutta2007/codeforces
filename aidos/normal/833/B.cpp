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


int dp[35100];
int d[35100];
int n, k;
int a[35100];
int last[35100];
int t[100100 * 4];
int ad[100100*4];

void build(int v, int l, int r){
	ad[v] = 0;
	if(l == r){
		t[v] = d[l];
		ad[v] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid+1, r);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void push(int v){
	t[v * 2] += ad[v];
	t[v * 2 +1] += ad[v];
	ad[v *2] +=ad[v];
	ad[v * 2 + 1] += ad[v];
	ad[v] = 0;
}

int get(int v, int l, int r, int tl, int tr){
	if(tl > tr) return -inf;
	if(l == tl && tr == r) return t[v];
	push(v);
	int mid = (l + r) >> 1;
	return max(get(v * 2, l, mid, tl, min(tr, mid)), get(v * 2 + 1, mid + 1, r, max(mid+1, tl), tr));
}

void add(int v, int l, int r, int tl, int tr, int val){
	if(tl > tr) return;
	if(l == tl && tr == r){
		t[v] += val;
		ad[v] += val;
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	add(v * 2, l, mid, tl, min(tr, mid), val);
	add(v * 2 + 1, mid + 1, r, max(tl, mid+1), tr, val);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}


void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i <= n; i++)
		dp[i] = -inf;
	dp[0] = 0;
	for(int i = 0; i < k; i++){
		for(int j = 0; j <= n; j++){
			d[j] = dp[j];
			dp[j] = -inf;
		}
		build(1, 0, n);
		for(int j = 1; j <= n; j++)
			last[j] = -1;
		for(int j = 0; j < n; j++){
			add(1,0, n, last[a[j]] + 1, j, 1);
			last[a[j]] = j;
			dp[j+1] = get(1, 0, n, 0, j);
		}
		for(int j = 0; j <= i; j++)
			dp[j] = -inf;
	}
	int ans = 0;
	for(int i = k; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}