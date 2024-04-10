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
int n, m, s, e;
vector<int> g[100100];
int ind[100100];
int dp[100100];
int d[100100];
int b[100100];
int a[100100];
void solve(){
	cin >> n >> m >> s >> e;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int j = 1; j <= m; j++) {
		cin >> b[j];
	}
	for(int j = 1; j <= m; j++) {
		g[b[j]].pb(j);
	}
	int ans = 0;
	for(int i = 1; i <= s/e; i++) {
		int cur = (i == 1) ? 0 : m+1;
		for(int j = 1; j < 100100; j++) {
			ind[j] = g[j].size();
		}
		for(int j = 1; j <= n; j++) {
			int &h = ind[a[j]];
			while(h > 0 && g[a[j]][h-1] > cur) {
				h--;
			}
			cur = min(cur, dp[j]);
			if(h < g[a[j]].size()) {
				dp[j] = g[a[j]][h];
				if(j + dp[j] + i*e <= s) {
					ans = i;
				}
			}
			else dp[j] = m+1;
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