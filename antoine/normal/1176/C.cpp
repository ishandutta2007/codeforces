#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x :a)
        cin >> x;
    {
        vector<int> v = {4, 8, 15, 16, 23, 42};
        map<int, int> mp;
        for (int i = 0; i < 6; ++i)
            mp[v[i]] = i;
        for (int &x: a)
            x = mp.at(x);
    }

    int ans = 0;
    vector<int> dp(6, 0);
    for (int &x: a)
        if (!x)
            dp[0]++;
        else {
            if (!dp[x - 1])
                ans++;
            else {
                dp[x - 1]--;
                dp[x]++;
            }
        }

    for (int i = 0; i < 5; ++i)
        ans += (i + 1) * dp[i];
    cout << ans;
    return 0;
}