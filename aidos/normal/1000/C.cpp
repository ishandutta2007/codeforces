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
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
ll ans[200100];
void solve(){
	cin >> n;
	vector<pll> v;
	for(int i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		v.pb(mp(l, +1));
		v.pb(mp(r+1, -1));
	}
	sort(all(v));
	ll cur = 0;
	for(int i = 0; i < v.size(); ) {
		ll x = v[i].f;
		while(i < v.size() && v[i].f == x) {
			cur += v[i].s;
			i++;
		}
		if(cur) {
			ans[cur] += v[i].f-x;
		}
	}
	for(int i = 1; i <= n; i++) cout<<ans[i] << " ";
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