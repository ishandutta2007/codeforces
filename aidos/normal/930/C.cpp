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
int n, m;
int d[100100];
int l[100100], r[100100];
int dp[100100];
int t[100100];
int get(int pos){
	int res = 0;
	while(pos>=0){
		res = max(res, t[pos]);
		pos = (pos&(pos+1)) - 1;
	}
	return res;
}
void upd(int pos, int val){
	while(pos <= n){
		t[pos]=max(t[pos], val);
		pos |= pos+1;
	}

}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &l[i], &r[i]);
		d[l[i]]++;
		d[r[i]+1]--;
	}
	for(int i = 1; i <= m; i++){
		d[i] += d[i-1];
	}
	int cur = 0;
	int ans = 0;
	for(int i = 1; i <= m; i++){
		dp[i] = get(d[i]) + 1;
		upd(d[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	for(int i = 0; i <= n; i++) t[i] = 0;
	for(int i = m; i > 0; i--){
		int c = get(d[i]) + 1;
		dp[i] += c - 1;
		upd(d[i], c);
		ans = max(ans, dp[i]);
	}

	/*
	for(int i = 1; i <= m; i++) cout << d[i] << " ";
	cout << endl;
	for(int i = 1; i <= m; i++) cout << dp[i] << " ";

	cout << endl;*/

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