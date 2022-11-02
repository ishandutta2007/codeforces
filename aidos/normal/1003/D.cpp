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

const int inf = (1ll << 25) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int cnt[40];
int n, q;

void solve(){
	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		for(int j = 0; j < 31; j++) {
			if(x == (1<<j)) cnt[j]++;
		}
	}
	for(int i = 0; i < q; i++) {
		int x;
		int ans = 0;
		scanf("%d", &x);
		for(int j = 30; j >= 0; j--) {
			int z = min(x/(1<<j), cnt[j]);
			ans += z;
			x -= z * (1<<j);
		}

		if(x != 0) ans = -1;
		printf("%d\n", ans);
	}
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