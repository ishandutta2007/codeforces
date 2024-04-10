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
ll a[100100];
ll t[100100];

int n;
void solve(){
	ll mid = 0;
	scanf("%d", &n);
	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		a[i] = x;
	}
	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		t[i] = x;
	}
	set<pll> S;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		ll g = sum;
		S.insert(mp(sum+a[i], i));
		sum += t[i];
		ll ans = 0;
		while(S.size() > 0 && S.begin()->f <= sum){
			ans += S.begin()->f - g;
			S.erase(S.begin());
		}
		ans += S.size() * t[i];
		printf("%lld ", ans);
	}
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