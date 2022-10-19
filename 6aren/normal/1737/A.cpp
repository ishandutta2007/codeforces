#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        k = n / k;
        vector<int> cnt(26);
        string s;
        cin >> s;
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        for (int i = 0; i < n / k; i++) {
            int best = 0;
            for (int j = 0; j < k; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--;
                    best = j + 1;
                } else break;
            }
            cout << (char)('a' + best);
        }
        cout << '\n';
    }
    return 0;
}