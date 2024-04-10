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
ll ts, tf, t;
ll a[100100];
int n;
void solve(){
	scanf("%I64d%I64d%I64d", &ts, &tf, &t);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
	}
	if(n == 0){
		cout << ts << endl;
		return;
	}

	ll x = ts;
	for(int i = 0; i < n; i++){
		x = max(x, a[i]) + t;
		if(i + 1< n){
			if(x + t <= tf && x < a[i + 1]){
				cout<<x<<endl;
				return;
			}
		}else{
			if(x + t <= tf){
				cout << x << endl;
				return;
			}
		}
	}
	
	
	vector<ll> cur;
	cur.pb(ts);
	for(int i = 0; i < n; i++){
		if(a[i]) cur.pb(a[i]-1);
		cur.pb(a[i]);
	}
	sort(all(cur));
	cur.resize(unique(all(cur)) - cur.begin());
	int ind = 0;
	x = ts;
	ll diff = (ll) 1e18;
	ll ans = 0;

	for(int i = 0; i < cur.size(); i++){
		
		while(ind < n && a[ind] <= cur[i]){
			x = max(x, a[ind]) + t;
			ind++;
		}
		if(max(x, cur[i]) + t <= tf){
			if(max(x - cur[i], 0ll) < diff){
				diff = max(x - cur[i], 0ll);
				ans = cur[i];
			}
		}
	}
	//cout << diff << endl;
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