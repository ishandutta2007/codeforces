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

using namespace std;
int n;
int m;
ll a[1111];
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		a[i]  = min(a[i], a[i-1] * 2ll);
	}
	for(int i = n; i < 30; i++){
		a[i] = a[i-1] * 2ll;
	}
	n = 30;
	ll cur = 0;
	ll ans = m * a[0];
	for(int i = n - 1; i >= 0; i--){
		if(m & (1<<i)) {
			ans = min(ans, cur + 2 * a[i]);
			cur += a[i];
		}
		else{
			ans = min(ans, cur + a[i]);
		}
	}
	ans = min(ans, cur);
	cout << ans << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}