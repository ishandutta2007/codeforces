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
#include <utility>

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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e6 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int a, b, q, c;
int dp[100100];
ll calc(ll x) {
	ll ans = dp[c-1] * (x/c) + dp[x % c];
	return ans;
}

void solve(){
	cin >> a >> b >> q;
	c = a * b;
	for(int i = 1; i < c; i++) {
		dp[i] = dp[i-1];
		if(i % a % b != i % b % a) dp[i]++;
	}
	for(int i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		cout << calc(r) - calc(l-1) << " ";
	}
	cout << "\n";
}
int main () {

    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}