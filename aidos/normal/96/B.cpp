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

void solve(){

	ll n, ans = (1ll<<50);
	cin >> n;
	for(int len = 2; len <= 10; len += 2){
		for(int j = 0; j < (1<<len); j++){
			if(__builtin_popcount(j) != len/2) continue;
			ll cur = 0;
			for(int i = 0; i < len; i++){
				if(j&(1<<i)) cur = cur * 10 + 4;
				else cur = cur * 10 + 7;
			}
			if(cur >= n) ans = min(ans, cur);
		}
	}
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