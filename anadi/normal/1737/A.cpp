#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector <int> counter(26, 0);
    for (auto c: s) {
        counter[c - 'a']++;
    }

    int len = n / k;
    for (int i = 1; i <= k; ++i) {
        for (int j = 25; j >= 0; --j) {
            if (j > len) {
                continue;
            }

            bool ok = true;
            for (int l = 0; l < j; ++l) {
                ok &= counter[l] > 0;
            }

            if (!ok) {
                continue;
            }

            printf("%c", j + 'a');
            for (int l = 0; l < j; ++l) {
                counter[l]--;
            }

            break;
        }
    }

    puts("");
}

int main()
{
    int cases = 1;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}