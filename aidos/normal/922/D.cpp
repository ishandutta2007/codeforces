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
const int maxn = (int) 1e5 + 10;

using namespace std;
char c[100200];
string t;

bool cmp(pii a, pii b) {
	if (a.first * 1ll * b.second != b.first * 1ll * a.second) return a.first * 1ll * b.second > b.first * 1ll * a.second;
	return a.first > b.first;
}
void solve() {
	int n;
	cin >> n;
	ll ans = 0;
	vector<pii> li;
	for (int i = 0; i < n; i++) {
		cin >> c;
		int len = strlen(c);
		int cur = 0;
		for (int j = 0; j < len; j++) {
			if (c[j] == 's') cur++;
			else ans += cur;
		}
		li.pb(mp(cur, len - cur));
	}
	sort(all(li), cmp);
	ll cur = 0;
	for (int i = 0; i < li.size(); i++) {
		ans += cur * li[i].second;
		cur += li[i].first;
	}
	cout << ans << endl;

}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int t = 1;
	
	for (int i = 1; i <= t; i++) {
		//printf("Case #%d\n", i);
		solve();
	}
	char c;
	//cin >> c;
	return 0;

}