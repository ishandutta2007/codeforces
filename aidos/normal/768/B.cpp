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

map<ll, ll> t, tt;
ll getsz(ll x){
	if(x == 0 || x == 1) return 1;
	if(t.count(x)) return t[x];
	t[x] = getsz(x/2) * 2 + 1;
	return t[x];
}
ll getans(ll x){
	if(x == 0 || x == 1) return x;
	if(tt.count(x)) return tt[x];
	tt[x] = getans(x/2) * 2 + x%2;
	return tt[x];
}
ll get(ll n, ll x){
	if(n == 0) return 0;
	if(n == 1) return 1;
	ll cur = getsz(n/2);
	ll ans = 0;
	if(cur <= x) ans += getans(n/2);
	if(cur + 1 <= x) ans += n % 2;
	if(cur + 2 <= x) ans += get(n/2, x-cur-1);
	if(cur > x) ans += get(n/2, x);
	return ans;
}

void solve(){
	ll n,l, r;
	cin >> n >> l >> r;
	ll ans = get(n, r);
	if(l>1) ans -= get(n, l-1);
	cout << ans<<endl;
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