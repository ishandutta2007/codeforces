#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int left = 0, right = 1e9;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        /// 0, 2,...
        bool f = false;
        int id = 0, lol = 0;
        for (int i = 0; id < n && i < k; i++) {
            if (i % 2 == 1) {
                lol++, id++;
            } else {
                while (id < n && a[id] > mid) id++;
                if (id == n) break;
                lol++;
                id++;
            }
        }
        if (lol == k) f = true;
        /// 1, 3, ...
        id = 0, lol = 0;
        for (int i = 0; i < k && id < n; i++) {
            if (i % 2 == 0) {
                lol++, id++;
            } else {
                while (id < n && a[id] > mid) id++;
                if (id == n) break;
                lol++;
                id++;
            }
        }
        if (lol == k) f = true;
        if (f) right = mid;
        else left = mid;
    }
    cout << right;
    return 0;
}