#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], dp[MAXN];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = n - 1; i >= 0; i--) {
        int p = upper_bound(v.begin(), v.end(), -a[i]) - v.begin();
        dp[a[i]] = (int)v.size() - p;
        while((int)v.size() > p) {
            dp[a[i]] = max(dp[a[i]], dp[-v.back()] + (int)v.size() - p - 1);
            v.pop_back();
        }
        v.push_back(-a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}