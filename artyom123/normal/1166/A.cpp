#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

mt19937 gen(time(0));

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    map <char, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s[0]]++;
    }
    int ans = 0;
    for (auto &c : m) {
        int a = c.second / 2;
        int b = (c.second + 1) / 2;
        ans += a * (a - 1) / 2;
        ans += b * (b - 1) / 2;
    }
    cout << ans;
    return 0;
}