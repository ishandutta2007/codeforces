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
#include <cassert>

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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e6 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int dp[17][1<<17];
int P[17][1<<17];
int a[17];
vector<int> b, c;
int sum[1<<17];
int T;
int n;
int updmin(int &v, int u) {
	if(v > u) {
		v = u;
		return 1;
	}
	return 0;
}
ll cnt = 0;
int calc() {
	int m = c.size();
	for(int j = 0; j < (1<<m); j++) {
		dp[0][j] = inf;
		for(int k = 0; k < m; k++) {
			if(j &(1<<k)) sum[j] = sum[j^(1<<k)] + c[k];
		}
	}
	for(int j = 0; j < (1<<m); j++) {
		dp[0][j] = sum[j];
		P[0][j]=j;
	}
	for(int i = 1; i < b.size(); i++) {
		for(int mask = 0; mask < (1<<m); mask++) {
			dp[i][mask] = inf;
		}
		for(int mask = 0; mask < (1<<m); mask++) {
			for(int j = mask; ; j = (j-1) & mask) {
				if(dp[i-1][mask^j] <= b[i] + sum[j]) {
					if(updmin(dp[i][mask], b[i] + sum[j])) {
						P[i][mask] = j;
					}
				}
				cnt++;
				if(j == 0) break;
			}
		}
	}
	return dp[b.size()-1][(1<<m)-1] < inf;
}
void restore(int nmask){
	b.clear();
	c.clear();
	vector<int> A, B, C;
	for(int j = 0; j < n; j++) {
		C.pb(j);
		if(nmask & (1<<j)) {
			b.pb(a[j]);
			A.pb(j);
		}
		else {
			c.pb(a[j]);
			B.pb(j);
		}
	}
	for(int j = b.size()-1; j > 0; j--) {
		b[j] -= b[0];
	}
	b[0] = 0;
	for(int j = 0; j < b.size(); j++) {
		b[j] -= j;
	}
	calc();
	int m = B.size();
	int M = (1<<m)-1;
	vector<pii> ans;
	for(int i = A.size()-1; M>0; i--) {
		int cur = P[i][M];
		for(int j = 0; j < m; j++) {
			if(cur & (1<<j)) {
				int t = 0;
				while(C[t] != A[i]) t++;
				int t2 = 0;
				while(C[t2] != B[j]) t2++;
				ans.pb(mp(t2, t));

				C.erase(C.begin() + t2);
			}
		}
		M^=cur;
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) cout << ans[i].f+1 << " "<<ans[i].s+1 << "\n";
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		//a[i] = 1;
	}
	int x = 1;
	while(x * (x+1)/2 <= n) x++;
	int ans = x-2;
	int ans_m = -1;
	for(int mask = 0; mask < (1<<n); mask++) {
		if(__builtin_popcount(mask) <= ans) continue;
		b.clear();
		c.clear();
		for(int j = 0; j < n; j++) {
			if(mask & (1<<j)) {
				b.pb(a[j]);
			}
			else c.pb(a[j]);
		}
		for(int j = b.size()-1; j > 0; j--) {
			b[j] -= b[0];
		}
		b[0] = 0;
		for(int j = 0; j < b.size(); j++) {
			b[j] -= j;
		}
		if(calc()) {
			ans = __builtin_popcount(mask);
			ans_m = mask;
		}
	}
	if(ans_m == -1) {
		cout << "asdg\n";
		return;
		//assert(false);
	}
	restore(ans_m);
	
}
int main () {
	/*
	for(int i = 0; i < 5000; i++) {
		solve(5);
	}
	for(int i = 0; i < 500; i++) {
		solve(8);
	}
	for(int i = 0; i < 100; i++) {
		solve(10);
	}
	for(int i = 0; i < 50; i++) {
		solve(11);
	}

	for(int i = 0; i < 25; i++) {
		solve(12);
	}
	for(int i = 0; i < 10; i++) {
		solve(13);
	}
	for(int i = 0; i < 3; i++) {
		solve(14);
	}
	solve(15);
	cout << cnt << "\n"; */
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
    	//int n;
    	//scanf("%d", &n);
      	solve();
    }
    
    return 0;
}