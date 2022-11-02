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
int n;
ll a[5050];
ll dp[5050];
ll b[5050];
ll d[5050];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int m = unique(b, b + n) - b;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			d[j] = dp[j];
			dp[j] = (1ll<<50);
		}
		for(int j = 0; j < m; j++) dp[j] = d[j] + abs(b[j] - a[i]);
		for(int j = 1; j < m; j++) dp[j] = min(dp[j-1], dp[j]);
	}
	cout << dp[m-1]<<"\n";
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