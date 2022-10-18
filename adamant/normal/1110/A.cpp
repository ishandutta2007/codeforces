#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int b, k;
    cin >> b >> k;
    int a[k];
    int rem = 0;
    for(int i = 0; i < k; i++) {
		cin >> a[i];
		rem = (rem * b + a[i]) % 2;
	}
	cout << (rem % 2 == 0 ? "even" : "odd") << endl;
    return 0;
}