#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += 2 * (n - 4 * i) + (m - 4 * i) * 2 - 4;
    }
    cout << ans;
	return 0;
}