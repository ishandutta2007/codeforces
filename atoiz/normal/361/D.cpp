#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define int long long

const int INF = 1e9;
int n, k;
bool check(vector<int> a, int c)
{
    vector<int> nxt[n];
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (abs(a[j] - a[i]) <= c * (j - i)) nxt[i].push_back(j);
        }
    }

    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j : nxt[i]) {
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    int maxlen = 0;
    for (int i = 0; i < n; ++i) maxlen = max(maxlen, dp[i]);
    return (n - maxlen) <= k;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

	long long l = 0, r = 2e9;
    while (l < r) {
    	int m = l + ((r - l) >> 1);
        if (check(a, m)) r = m;
        else l = m + 1;
    }
    cout << l << endl;
}