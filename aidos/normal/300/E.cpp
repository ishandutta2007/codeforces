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
const int maxn = (int) 1e7 + 10;
const int mod = (int) 1e9 + 7;
const int maxd = (int) 700700;
using namespace std;
int k;
int lp[maxn];
int cnt[maxn];
ll c[maxd];
vector<int> p;
ll get(ll x, ll p) {
	ll ans = 0;
	while(x > 0) {
		x/=p;
		ans += x;
	}
	return ans;
}
bool ok(ll x) {
	for(int i = 0; i < p.size(); i++) {
		if(get(x, p[i]) < c[i]) return 0;
	}
	return 1;
}
void solve(){
	for(int i = 2; i < maxn; i++) {
		if(lp[i] == 0) {
			p.push_back(i);
			for(int j = i; j < maxn; j+=i) {
				if(!lp[j]) lp[j] = p.size();
			}
		}
	}
	scanf("%d", &k);
	int mx = 0;
	for(int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
		mx = max(x, mx);
	}
	for(int i = maxn-1; i > 1; i--) {
		int j = i;
		while(j > 1) {
			int t = lp[j]-1;
			c[t]+=cnt[i];
			j/=p[t];
		}
		cnt[i-1] += cnt[i];
	}
	if(mx < 2) {
		cout << 1 << "\n";
		return;
	}
	ll l=2, r = 1e15;
	ll res = 1;
	while(l <= r) {
		ll mid = (l+r)/2;
		if(ok(mid)) {
			r = mid-1;
			res = mid;
		}else l = mid+1;
	}
	cout << res << "\n";
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