#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;

int v[NMAX];
int freq[NMAX];

void test() {
    int n;
    cin >> n;
    int buckets = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        ++freq[v[i]];
        if (freq[v[i]] == 1) {
            ++buckets;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // First try to use this.
        ans = max(ans, min(buckets, freq[i] - 1));
        // Then don't use this.
        ans = max(ans, min(buckets - 1, freq[i]));
    }

    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        freq[v[i]] = 0;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    cin >> t;
    while (t--) {
        test();
    }
    return 0;
}