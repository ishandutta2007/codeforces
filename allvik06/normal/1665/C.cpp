#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
#define int long long
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> cnt(n);
        for (int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            ++cnt[p - 1];
        }
        multiset <int> s1, s2, tmp;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > 0) s1.insert(cnt[i]);
        }
        int answer = 0;
        bool root = false;
        while (!s1.empty() || !s2.empty() || !root) {
            ++answer;
            for (int i : s2) {
                if (i > 1) tmp.insert(i - 1);
            }
            s2.swap(tmp);
            tmp.clear();
            if (!s1.empty()) {
                int x = *s1.rbegin();
                s1.erase(s1.find(x));
                if (x > 1) s2.insert(x - 1);
            } else if (!root) {
                root = true;
            } else if (!s2.empty()) {
                int x = *s2.rbegin();
                s2.erase(s2.find(x));
                if (x > 1) s2.insert(x - 1);
            }
        }
        cout << answer << "\n";
    }
}