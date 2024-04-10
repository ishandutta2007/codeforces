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
#include <cassert>

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
const int maxn = (int)1e5+100;
const int mod = (int) 1e9 + 9;
using namespace std;
int n, m;
pii a[maxn];
int ans[maxn];
int calc(int x) {
	set<int>c, d;
	for(int i = -3; i <= 3; i++) {
		if(i>=0 && i < x) c.insert(i);
		if(i+x>=0 && i+x< x) c.insert(i+x);	
	}

	for(int i = -3; i <= 3; i++) {
		if(i+x>=x && i+x < n) d.insert(i+x);
		if(i+n<n && i+n>= x) d.insert(i+n);	
	}
	int mx = 0;
	int mi = inf;
	vector<int> cc, dd;
	for(int t: c) cc.pb(a[t].f);
	for(int t: d) dd.pb(a[t].f);
	if(cc.size() > 1) {
		mx = max(mx, cc[cc.size()-1] + cc[cc.size()-2]);
		mi = min(mi, cc[0] + cc[1]);
	}
	if(dd.size() > 1) {
		mx = max(mx, dd[dd.size()-1] + dd[dd.size()-2]);
		mi = min(mi, dd[0] + dd[1]);
	}
	if(cc.size() > 0 && dd.size()>0) {
		mx = max(mx, dd[dd.size()-1] + cc[cc.size()-1] + m);
		mi = min(mi, cc[0] + dd[0] + m);
	}
	return mx - mi;
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i].f;
		a[i].s = i;
	}
	sort(a, a + n);
	int val = inf;
	int best = -1;
	calc(0);
	for(int i = 0; i <= n; i++) {
		int cur = calc(i);
		if(cur < val) {
			val = cur;
			best = i;
		}
	}
	for(int i = 0; i < n; i++) {
		if(i < best) ans[a[i].s] = 1;
		else ans[a[i].s] = 2;
	}
	cout << val << "\n";
	for(int i = 0; i < n; i++) cout << ans[i] << " ";

}
int main () {
    int t=1;
    solve();
   	
    return 0;
}