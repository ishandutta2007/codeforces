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
ll dp[5];
ll b[5];
ll a[100100];
void solve(){
	cin >> n;
	for(int i = 1; i <= 3; i++){
		dp[i] = -4e18;
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		for(int j = 1; j <= 3; j++) {
			dp[j] = max(dp[j], x * b[j] + dp[j-1]);
		}
	}
	cout << dp[3] << "\n";
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