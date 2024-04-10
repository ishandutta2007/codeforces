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
pii a[100100];
int n;
char tmp[2222];
map<string, int> D;
int d[234][234];
int M[234];
int dp[(1<<20) + 10];
int MM[234];
int m;
void solve(){
	scanf("%d%d", &n, &m);
	int cc = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].f);
		if(a[i].f == 2) {
			scanf("%s", tmp);
			if(D.count(tmp) == 0) {
				D[tmp] = cc++;
			}
			a[i].s = D[tmp];
		}
	}
	a[n++]=mp(1, 0);
	vector<int> g;
	for(int i = 0; i < n; i++) {
		if(a[i].f == 1){
			sort(all(g));
			g.resize(unique(all(g)) - g.begin());
			int t = g.size();
			for(int j = 0; j < t; j++)
				for(int k=0;k<t; k++) {
					if( j!=k)
					d[g[j]][g[k]] = 1;
				}
			g.clear();
		}
		else g.pb(a[i].s);
	}
	n = m;
	if(n == 1) {
		cout << 1 << "\n";
		return;
	}
	int k = n/2;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++){
			if(d[i][j]) M[i] |= (1<<j);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = k; j < n; j++){
			if(d[i][j]) MM[i] |= (1<<(j-k));
		}
	}
	
	for(int i = 0; i < (1<<k); i++){
		dp[i] = 0;
		int mask = 0;
		for(int j = 0; j < k; j++){
			if(i&(1<<j)) {
				dp[i] = max(dp[i], dp[i^(1<<j)]);
				mask |= M[j];
			}
		}
		if(i&mask) {
		
		}
		else dp[i] = __builtin_popcount(i);
	}
	int len = n - k;
	int ans = 0;
	for(int i = 0; i < (1<<len); i++){
		ll mask = 0;
		int c = 0;
		for(int j = 0; j < len; j++){
			if(i&(1<<j)) {
				mask |= MM[j+k];
				c |= M[j+k];
			}
		}
		if(i&mask) {
					
		}
		else {
			int cur = ((1<<k)-1)^c;
			ans = max(ans, dp[cur] + __builtin_popcount(i));
		}
	}
	cout << ans << "\n";
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