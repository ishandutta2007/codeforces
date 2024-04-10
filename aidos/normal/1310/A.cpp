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
const int maxn = (int) 3e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
pii a[200200];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].f);
	}

	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].s);
		a[i].s *= -1;
	}
	sort(a, a + n);
	multiset<pii>S;
	int x = a[0].f;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		while(S.size() > 0 && x < a[i].f) {
			pii c = *S.begin();
			S.erase(S.begin());
			//cout << x << " "<< c.s << "\n";
			ans += (-c.f) * 1ll * (x-c.s);
			x++;
		}
		x = max(x, a[i].f);
		S.insert(mp(a[i].s, a[i].f));
	}
	while(S.size() > 0) {
		pii c = *S.begin();
		S.erase(S.begin());
		ans += (-c.f) * 1ll * (x-c.s);
		x++;
	}
	cout << ans << "\n";
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