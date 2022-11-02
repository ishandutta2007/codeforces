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
string s[55];
ll d[1<<20];
int m;
double dp[1<<20];
int u[1<<20];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	m = s[0].size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			int mask = 0;
			for(int t = 0; t < m; t++) if(s[i][t] == s[j][t]) mask |= 1<<t;
			d[mask] |= (1ll<<i) | (1ll<<j);
		}
	}
	for(int i = (1<<m)-2; i >= 0; i--) {
		for(int j = 0 ;j < m; j++)
			d[i] |= d[i|(1<<j)];
	}
	for(int i = (1<<m)-2; i >= 0;i--) {
		int cnt = m - __builtin_popcount(i);
		ll x = __builtin_popcountll(d[i]);
		for(int j = 0; j < m; j++) {
			if((1<<j) & i) {
			
			}else{
				if(d[i]){
					dp[i] += (dp[i|(1<<j)] + x)/cnt;
				}
			}
		}
	}
	printf("%.12lf", dp[0]/n);
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