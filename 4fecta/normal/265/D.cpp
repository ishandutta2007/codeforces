#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, a[MN], dp[MN], len[MN];

vector<int> fct(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) ans.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans.push_back(n);
    return ans;
}

int main() {
    boost();

    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vector<int> v = fct(a[i]);
        int mx = 0;
        for (int j : v) {
            mx = max(mx, len[j]);
        }
        dp[i] = mx + 1;
        for (int j : v) len[j] = dp[i];
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);

    return 0;
}