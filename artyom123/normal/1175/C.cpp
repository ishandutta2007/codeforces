#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;
const long long need = (1LL << 32) - 1;

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
   		int n, k;
   		cin >> n >> k;
   		vector <int> a(n);
   		for (auto &c : a) {
   			cin >> c;
   		}
   		k++;
   		int ans = INF;
   		int x = 0;
   		for (int i = 0; i + k - 1 < n; i++) {
   			int l = a[i];
   			int r = a[i + k - 1];
   			if ((r - l + 1) / 2 < ans) {
   				ans = (r - l + 1) / 2;
   				x = l + ans;
   			}
   		}
   		cout << x << "\n";
   	}
    return 0;
}