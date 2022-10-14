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
   	int n, k;
   	cin >> n >> k;
   	vector <int> a(n);
   	for (auto &c : a) {
   		cin >> c;
   	}
   	long long ans = a.back() - a[0];
   	vector <int> b;
   	for (int i = 0; i < n - 1; i++) {
   		b.pb(a[i] - a[i + 1]);
   	}
   	sort(b.begin(), b.end());
   	for (int i = 0; i < k - 1; i++) {
   		ans += b[i];
   	}
   	cout << ans;
    return 0;
}