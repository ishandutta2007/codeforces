#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n;
string s;

void solve()
{
    cin >> n >> s;

    int len = s.size();
    for (int i = 0; i < n; ++i) {
        if ((int)s.size() < n) {
            int to_copy = min((int)(s.size() - i - 1) * (s[i] - '1'), n - (int)s.size());
            for (int j = 1; j <= to_copy; ++j) {
                s.push_back(s[i + j]);
            }
        }

        len = (len + 1LL * (len + MOD - i - 1) * (s[i] - '1')) % MOD;
    }

    printf("%d\n", len);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cases;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}