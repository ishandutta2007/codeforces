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

set<ll> S;
int n;
int a[100100];
int b[100100];
int m, q;
void solve(){
	scanf("%d%d%d", &n, &m, &q);
	ll val = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(i&1) val -= a[i];
		else val += a[i];
	}
	int cnt = 0;
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	ll sum = 0;
	b[m] = 0;
	for(int i = m-1; i >= 0; i--){
		sum *= -1;
		sum += b[i];
		cnt++;
		if(cnt >= n){
			if(n & 1) sum += b[i + n];
			else sum -= b[i + n];
			S.insert(sum);
		}
	}

		set<ll> :: iterator it = S.lower_bound(val);
		ll ans = (1ll<<50);
		if(it != S.end()){
			ans = min(ans, abs(val - *it));
		}
		if(it != S.begin()){
			it--;
			ans = min(ans, abs(val - *it));
		}
		printf("%I64d\n", ans);
	for(int i = 0, l, r, x; i < q; i++){
		scanf("%d%d%d", &l, &r, &x);
		if((r-l) & 1){
		
		}else if(l&1) val += x;
		else val -= x;
		set<ll> :: iterator it = S.lower_bound(val);
		ll ans = (1ll<<50);
		if(it != S.end()){
			ans = min(ans, abs(val - *it));
		}
		if(it != S.begin()){
			it--;
			ans = min(ans, abs(val - *it));
		}
		printf("%I64d\n", ans);
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