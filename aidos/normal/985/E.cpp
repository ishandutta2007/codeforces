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
int n, k, d;
int a[500500];
int dp[500500];
int prv[500500];
int main () {
	cin >> n >> k >> d;
	for(int i = 0; i < n; i++) cin >> a[i];
	if(k == 1) {
		cout << "YES\n";
		return 0;
	}
	sort(a, a + n);
	dp[0] = 1;
	prv[k-1] = 0;
	if(a[k-1] - a[0] <= d) {
		dp[k-1] = 1;
		prv[k-1] = k;
	}

	for(int i = k; i < n; i++) {
		int last = prv[i-k];
		if(a[i] - a[last] <= d) dp[i] = 1;
		prv[i] = prv[i-1];
		if(dp[i]) prv[i] = i+1;
	}
	if(dp[n-1]) cout << "YES\n";
	else cout << "NO\n";

    return 0;
}