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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;
pii d[200200];
ll S;
ll a;
ll ans[200200];


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> a;
    for(int i = 0; i < n; i++){
    	cin >> d[i].f;
    	d[i].s = i;
    	S += d[i].f;
	}

	sort(d, d+n);
	int l = 1;
	
	for(int i = 0; i < n; i++){
		while(S - d[i].f < a - l) {
			l++;
		}
		ll r = min(d[i].f+0ll, a - n + 1);
//		cout << l << endl;
		ans[d[i].s] = d[i].f - r + l-1;
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}