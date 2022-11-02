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
int n, k;
int cnt[10500];
int bi[20500];
void solve(){
	scanf("%d%d", &n, &k);
	ll ans = 0;
	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		cnt[x]++;
	}
	int lim = 10100;
	for(int i = 0; i < 2 * lim; i++){
		bi[i] = __builtin_popcount(i);
	}
	if(k == 0){
		for(int i = 0; i < lim; i++){
			//if(cnt[i]){
			ans += (cnt[i] - 1) * 1ll * cnt[i]/2;
			
		}
	}
	else {
		for(int i = 0; i < lim; i++){
			for(int j = i + 1; j < lim; j++){
				if(bi[i ^ j]==k) {
					ans += cnt[i] * 1ll * cnt[j];
				}
			}
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