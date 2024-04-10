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
   		long long n, k;
   		cin >> n >> k;
   		if (k == 1) {
   			cout << n << "\n";
   			continue;
   		}
   		long long ans = 0;
   		while (n != 0) {
   			if (n % k == 0) {
   				n /= k;
   				ans++;
   				continue;
   			}
   			long long p = n / k * k;
   			ans += n - p;
   			n = p;
   		}
   		cout << ans << "\n";
   	}
    return 0;
}