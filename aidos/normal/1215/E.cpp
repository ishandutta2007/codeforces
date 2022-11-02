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
int n;
int a[400400];
ll b[22][22];
ll dp[(1<<20)];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int t = 1; t <= 20; t++) {
		ll s = 0, c = 0;
		for(int i = 0; i < n; i++) {
			s += c;
			if(a[i] == t) c++;
			else {
				b[t-1][a[i]-1] += c;
			}
		}
	}
	n = 20;
	for(int mask = 1; mask < (1<<n); mask++) {
		dp[mask] = 1ll<<50;
		vector<int> c;
		for(int i = 0; i < n; i++) {
			if(mask & (1<<i)) {
				c.pb(i);
			}
		}
		for(int t=0; t < c.size(); t++) {
			ll g = 0;
			for(int k = 0; k < c.size(); k++) {
				g += b[c[k]][c[t]];
			}
			dp[mask] = min(dp[mask], dp[mask^(1<<c[t])] + g);
		}
	}
	cout << dp[(1<<n)-1] << "\n";
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