#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define int long long
const int INF = 1e15;

signed main(){
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			a[x - 1]++;
		}
		vector <int> p(n + 1);
		for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];
		int ans = INF;
		vector <int> mp(n + 1);
		for (int i = 2; i <= n; ++i) {
			mp[i] = mp[i - 1];		
			if ((1 << mp[i - 1]) < i) mp[i]++;
		}
		for (int x = 0; x <= n; ++x) {		
			int c = (1 << mp[p[x]]) - p[x];
			//cout << c << "\n";
			if (x == n) {
				ans = min(ans, c + 2);
				break;
			}
			for (int po = 0; po < 20; ++po) {
				if (a[x] > (1 << po)) continue;			
				int l = x, r = n;
				while (r - l > 1) {
					int m = (l + r) / 2;
					if (p[m + 1] - p[x] <= (1 << po)) l = m;
					else r = m;
				}
				int cc = (1 << po) - (p[l + 1] - p[x]);
				int s = p[n] - p[l + 1];
				int ccc = (1 << mp[s]) - s;
				ans = min(ans, c + cc + ccc);
			}
		}
		cout << ans << "\n";
	}
}