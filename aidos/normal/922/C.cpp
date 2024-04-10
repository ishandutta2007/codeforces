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
ll n, k;//
int used[10000100];
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= min(k, 10000000ll); i++) {
		if (used[n % i]) {
			cout << "No";
			return;
		}
		used[n % i] = 1;
	}
	if (n == 1) {
		cout << "Yes";
		return;
	}
	if (n <= k) {
		cout << "No";
		return;
	}
	cout << "Yes";
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