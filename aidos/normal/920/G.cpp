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

int pr[2000100];
const int N = 2000*1000;

void precalc(){
	for(int i = 2; i <= N; i++){
		for(int j = i; j <= N; j += i){
			if(pr[j] == 0) pr[j] = i;
		}
	}
}
int x, p, k;
int calc(vector<pii>&G, int x){
	ll ans = 0;
	forit(it, G){
		ans += (x/it->f) * it->s;
	}
	return ans;
}
void solve(){
	scanf("%d%d%d", &x, &p, &k);
	if(p == 1){
		printf("%d\n", x + k);
		return;
	}
	int r = 1e9;
	int l = x + 1;
	int res = -1;
	vector<int> a;
	while(p > 1){
		int d = pr[p];
		while(p % d == 0) p/=d;
		a.pb(d);
	}
	int C = a.size();
	vector<pii> G;
	for(int i = 0; i < (1<<C); i++){
		int t = 1;
		int sgn = 1;
		for(int j = 0; j < C; j++){
			if(i&(1<<j)) {
				t *= a[j];
				sgn *= -1;
			}
		}
		G.pb(mp(t, sgn));
	}
	k += calc(G, x);
	while(l <= r){
		int mid = (l + r)>>1;
		if(calc(G, mid) >= k){
			res = mid;
			r = mid-1;
		}
		else l = mid + 1;
	}
	printf("%d\n", res);
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
	precalc();
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}