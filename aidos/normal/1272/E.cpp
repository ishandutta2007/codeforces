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
const int maxn = (int) 2e5 + 10;
using namespace std;
int n, k;
string s;
set<char> S;
int a[maxn];
int dp[maxn];
vector<int> g[maxn];
void solve(){    
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		dp[i] = -1;
		if(i - a[i] >= 1) {
			g[i-a[i]].pb(i);
		}
		if(i + a[i] <= n) {
			g[i+a[i]].pb(i);
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			int k = g[i][j];
			if(dp[k]!=-1) continue;
			if(a[k] % 2 == a[i] % 2) continue;
			q.push(k);
			dp[k] = 1;
		}
	}
	while(q.size() > 0) {
		int v = q.front();
		q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int k = g[v][i];
			if(dp[k]!=-1) continue;
			//if(a[k] % 2 == a[v] % 2) continue;
			q.push(k);
			dp[k] = dp[v] + 1;
		}
	}
	for(int i = 1; i <= n; i++) cout << dp[i] << " ";

}
int main () {
	int t=1;
	//cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}