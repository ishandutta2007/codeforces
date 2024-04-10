#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t;
    cin >> t;
    while (t--) {
    	int b, p, f;
    	cin >> b >> p >> f;
    	int h, c;
    	cin >> h >> c;
    	int ans = 0;
    	for (int ha = 0; ha <= 100; ha++) {
    		for (int ch = 0; ch <= 100; ch++) {
    			if (ha > p || ch > f || (ha + ch) * 2 > b) {
    				continue;
    			}
    			ans = max(ans, ha * h + ch * c);
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}