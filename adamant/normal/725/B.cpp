#include <bits/stdc++.h>

using namespace std;

#define int uint64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t;
    cin >> t;
    int n = atoll(t.substr(0, t.size() - 1).c_str());
    int ans = (n - 1) / 4 * 16;
    n = (n - 1) % 4 + 1;
    map<char, int> check = {{'f', 1}, {'e', 2}, {'d', 3}, {'a', 4}, {'b', 5}, {'c', 6}};
    ans += (n == 2 || n == 4) * 7 + check[t.back()];
    cout << ans << endl;
    return 0;
}