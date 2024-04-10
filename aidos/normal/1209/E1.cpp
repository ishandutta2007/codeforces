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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
int dp[(1<<12)];
int d[(1<<12)];
int a[2020][22];
int s[(1<<12)];
int fi[(1<<12)];

void calc(int p) {
	for(int i = 0; i < n; i++) {
		for(int mask = 1; mask < (1<<n); mask++) {
			s[mask] = 0;
		}
		for(int mask = 1; mask < (1<<n); mask++) {
			int en = fi[mask];
			s[mask] = s[mask^(1<<en)] + a[p][(i+en) % n];
		}
		for(int mask = 0; mask < (1<<n); mask++) d[mask] = max(d[mask], s[mask]);
	}
}
void solve(){
	cin>>n >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) cin>>a[j][i];
	}
	for(int j =0; j < (1<<n); j++) {
		d[j] = 0;
		dp[j] = 0;
	}
	for(int mask = 1; mask < (1<<n); mask++) {
		fi[mask] = 0;
		while(!(mask & (1<<fi[mask]))) fi[mask]++;
	}
	vector<pii> p;
	for(int i=0; i < k; i++) {
		int mx=0;
		for(int j = 0; j < n; j++) mx = max(a[i][j], mx);
		p.pb(mp(-mx, i));
	}
	sort(all(p));
	for(int j = 0; j < p.size(); j++) {
		if(j > 2 * n) break;
		for(int mask = 0; mask < (1<<n); mask++) d[mask] = 0;
		calc(p[j].s);
		for(int mask = (1<<n)-1; mask > 0; mask--) {
			for(int nmask=mask; nmask > 0; nmask = (nmask - 1) & mask) {
				dp[mask] = max(dp[mask^nmask]+d[nmask], dp[mask]);
			}
		}
	}
	cout << dp[(1<<n)-1] << "\n";
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