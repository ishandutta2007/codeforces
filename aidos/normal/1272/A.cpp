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
int a[3];
int b[3];
ll ans;
void rec(int p) {
	if(p == 3) {
		ll cur = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < i; j++) cur += abs(b[j] - b[i]);
		}
		ans = min(ans, cur);
		return;
	}
	b[p] = a[p];
	rec(p+1);
	b[p] = a[p] - 1;
	rec(p+1);
	b[p] = a[p] + 1;
	rec(p+1);
}
void solve(){
	cin >> a[0] >> a[1] >> a[2];
	ans = 1e10;
	rec(0);
	cout << ans << "\n";
}
int main () {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}