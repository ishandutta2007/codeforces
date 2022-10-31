#include<bits/stdc++.h>

using namespace std;

int a[2005], cnt[1005], used[2005], lst[1005];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector < int > primes;
    for (int i = 2; i <= 1000; ++i) {
        int ok = 1;
        for (int j = 2; j < i; ++j) if (i % j == 0) ok = 0;
        if (ok) primes.push_back(i);
    }
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; ++i) used[i] = 0;
        for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
        for (auto key : primes) {
            for (int j = 0; j < key; ++j) cnt[j] = 0;
            for (int i = 1; i <= 2 * n; ++i) cnt[a[i] % key]++;
            int sum = 0;
            for (int i = 0; i < key; ++i) {
                if (i == 0) sum += cnt[i] / 2;
                else if (i <= key - i) sum += min(cnt[i], cnt[key - i]);
            }
            if (sum >= n - 1) {
                for (int t = 1; t <= n - 1; ++t) {
                    for (int j = 0; j < key; ++j) lst[j] = 0;
                    for (int i = 1; i <= 2 * n; ++i) {
                        if (used[i]) continue;
                        int val = (key - a[i] % key) % key;
                        if (lst[val] != 0) {
                            cout << i << " " << lst[val] << '\n';
                            used[i] = 1;
                            used[lst[val]] = 1;
                            break;
                        }
                        lst[a[i] % key] = i;
                    }
                }
                break;
            }
        }
    }
    return 0;
}