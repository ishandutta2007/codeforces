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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n;
int a[maxn];
vector<int> g[maxn];
int t[maxn];
void upd(int p, int v) {
	while(p <= n) {
		t[p] += v;
		p |= (p + 1);
	}
}
int get(int p) {
	int res = 0;
	for(int i = p; i >= 0; i = (i&(i+1)) - 1) {
		res += t[i];
	}
	return res;
}
int get(int l, int r) {
	return get(r) - get(l-1);
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		g[a[i]].pb(i);
		upd(i, 1);
	}
	int last = 1;
	ll ans = 0;
	for(int i = 0; i < maxn; i++) {
		if(g[i].size() == 0) continue;
		int L = g[i][0];
		int R = g[i].back();

		if(last <= L) {
			ans += get(last, L);
			ans += get(L+1, R);
			last = R;
		} else if(last > R){
			ans += get(last, n);
			ans += get(1, R);
			last = R;
		} else {
			int pos = lower_bound(all(g[i]), last) - g[i].begin();
			ans += get(last, n);
			ans += get(1, g[i][pos-1]);
			last = g[i][pos-1];
		}
		for(const int &id: g[i]) {
			upd(id, -1);
		}
	}
	cout << ans << "\n";
}
int main () {

	int t = 1;
	//scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}