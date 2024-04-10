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
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
string s, t;
vector<int> g[1000100];
int dp[100100];
int a[100100];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int d = *max_element(a, a + n);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= d; j += i) g[j].pb(i);
	}
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		int x = a[i];
		for(int j=g[x].size()-1; j >= 0; j--) {
			int c = g[x][j];
			dp[c] = (dp[c] + dp[c-1]) % mod;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = (ans + dp[i]) % mod;
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