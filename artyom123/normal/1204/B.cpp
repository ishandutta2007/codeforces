#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	int n, l, r;
   	cin >> n >> l >> r;
   	long long ans1 = 0, ans2 = 0;
   	for (int i = 0; i < l; i++) {
   		ans1 += (1 << i);
   	}
   	ans1 += (n - l);
   	for (int i = 0; i < r; i++) {
   		ans2 += (1 << i);
   	}
   	ans2 += (1 << (r - 1)) * (n - r);
   	cout << ans1 << " " << ans2;
    return 0;
}