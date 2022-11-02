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
#include <bitset>

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
int pl, pr, vl, vr, k;
vector<ll> d, c;
ll lim = (ll)(1e10) + 1;

long double get(ll a, ll b, ll c, ll d) {
	long double len = d-c+1;
	long double cur = min(b, d) - max(a, c) + 1;
	if(cur < 0) cur = 0;
	return cur/len;
}
void solve(){
	cin >> pl >> pr >> vl >> vr >> k;
	d.pb(4);
	d.pb(7);
	c.pb(0);
	while(d.size() > 0) {
		vector<ll> dd;
		for(int i = 0; i < d.size(); i++){
			c.pb(d[i]);
			if(d[i] * 10 + 4 <= lim) dd.pb(d[i] * 10 + 4);
			if(d[i] * 10 + 7 <= lim) dd.pb(d[i] * 10 + 7);
		}
		d = dd;
	}
	long double ans = 0;
	for(int i = 1; i + k < c.size(); i++) {
		ans += get(c[i-1]+1, c[i], pl, pr) * get(c[i+k-1], c[i+k] - 1, vl, vr);
		ans += get(c[i-1]+1, c[i], vl, vr) * get(c[i+k-1], c[i+k] - 1, pl, pr);
	}
	if(k == 1) {
		for(int i = 1; i < c.size(); i++) {
			ans -= get(c[i], c[i], pl, pr) * get(c[i], c[i], vl, vr);
		}
	}
	printf("%.16lf\n",(double)ans);
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