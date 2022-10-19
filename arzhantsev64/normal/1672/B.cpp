#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

void solve() {
    string s2;
    cin >> s2;
    int b = 0;
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] == 'A')
            b++;
        else
            b--;
        if (b < 0) {
            cout << "NO\n";
            return;
        }
    }
    if (s2[(int)s2.size() - 1] == 'B')
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
         solve();

    return 0;
}