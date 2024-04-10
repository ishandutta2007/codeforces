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
int a, b, c;
int p[2020];
int D[4000400];
int sgn[2020];
int dp[2020];
void solve(){
	cin >> a >> b >> c;
	sgn[1] = 1;
	for(int i = 2; i <= 2010; i++){
		if(p[i] == 0){
			for(int j = i * i; j <= 2010; j += i) {
				if(p[j] == 0) p[j] = i;
			}
			p[i] = i;
		}
		if(i % (p[i] * p[i]) == 0) sgn[i] = 0;
		else sgn[i]=-sgn[i/p[i]];
	}
	for(int i = 1; i <= c; i++){
		for(int j = 1; j <= i; j++) dp[i] += i/j;
	}
	for(int i = 1; i <= c; i++){
		if(sgn[i] == 0) continue;
		int val = dp[c/i] * sgn[i];
		for(int j = i; j <= a * b; j += i) {
			D[j] += val;
		}
	}
	ll ans = 0;
	for(ll i = 1; i <= a; i++){
		for(ll j = 1; j <= b; j++){
			if(__gcd(i, j) == 1) {
				ans += (a/i) * (b/j) * D[i * j];
			}
		}
	}
	cout << ans % (1<<30) << "\n";
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