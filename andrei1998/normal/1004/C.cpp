#include <bits/stdc++.h>

using namespace std;

const int kMaxN =  1e5;

int first[kMaxN], last[kMaxN];

int main() {
    ios_base :: sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (auto& it : a) {
        cin >> it; it--;
    }

    memset(first, -1, sizeof first);
    memset(last, -1, sizeof last);
    for (int i = 0; i < n; ++i) {
        if (first[a[i]] == -1) {
            first[a[i]] = i;
        }
    }

    int num_right = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (last[a[i]] == -1) {
            last[a[i]] = i;
            ++num_right;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (last[a[i]] == i) {
            --num_right;
        }

        if (first[a[i]] == i) {
            ans += num_right;
        }
    }

    cout << ans << endl;

    return 0;
}