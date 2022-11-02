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
int c[maxn];
int d[maxn];
void solve(){    
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > a[i-1]) c[i] = c[i-1] + 1;
		else c[i] = 1;
	}
	for(int i = n; i > 0; i--) {
		if(a[i+1] > a[i]) d[i] = d[i+1] + 1;
		else d[i] = 1;
		ans = max(ans, d[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(a[i-1] < a[i+1]) ans = max(ans, c[i-1] + d[i+1]);
	}
	cout << ans << "\n";
}
int main () {
	int t=1;
	//cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}