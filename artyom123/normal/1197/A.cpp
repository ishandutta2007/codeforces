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
   		int n;
   		cin >> n;
   		vector <int> a(n);
   		for (auto &c : a) {
   			cin >> c;
   		}
   		sort(a.begin(), a.end());
   		cout << min(n - 2, min(a.back(), a[n - 2]) - 1) << "\n";
   	}
    return 0;
}