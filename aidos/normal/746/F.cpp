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
int n, w, k;
int a[200200];
int t[200200];

set<pair<pll, int> > S1, S2;

	ll ans = 0;
	ll cur = 0;
	int last = 0;
	ll ti = 0;
void good(){
	if(S2.size() > w){
		pair<pll, int> xx = *S2.begin();
		S2.erase(S2.begin());
		ti -= xx.f.f;
		ti += xx.f.s;
		S1.insert(xx);
	}
	if(S1.size() == 0) return;
	if(S2.size() == w) return;

		pair<pll, int> xx = *(--S1.end());
		S1.erase(--S1.end());
		ti -= xx.f.s;
		ti += xx.f.f;
		S2.insert(xx);
}
void solve(){
	scanf("%d%d%d", &n, &w, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &t[i]);
	}
	last = n;
	for(int i = n; i > 0; i--){
		ll x=(t[i] + 1)/2;
		if(x > k){
			cur = 0;
			ti = 0;
			S1.clear();
			S2.clear();
			last = i-1;
			continue;
		}
		S2.insert(mp(mp(x, t[i]), i));
		cur += a[i];
		ti += x;
		good();
		while(ti > k){
			ll xx = (t[last] + 1)/2;
			if(S2.count(mp(mp(xx, t[last]), last))){
				S2.erase(mp(mp(xx, t[last]), last));
				ti -= xx;
				cur -= a[last];
			}
			else{
				S1.erase(mp(mp(xx, t[last]), last));
				ti -= t[last];
				cur -= a[last];
			}
			last--;
			good();
		}
		ans = max(ans, cur);
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