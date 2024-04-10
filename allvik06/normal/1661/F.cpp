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
#include <iomanip>

using namespace std;
#define int long long
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n;
    n++;
    vector <int> a(n);
    for (int i = 1; i < n; ++i) cin >> a[i];
    cin >> m;
    int l = 0, r = 1e18 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2, sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            int x = a[i + 1] - a[i];
            int ll = 1, rr = x + 1;
            while (rr - ll > 1) {
                int mm = (ll + rr) / 2;
                int cnt1 = (x % mm) * (x / mm + 1) * (x / mm + 1) + (mm - x % mm) * (x / mm) * (x / mm);
                int mm1 = mm - 1;
                int cnt2 = (x % mm1) * (x / mm1 + 1) * (x / mm1 + 1) + (mm1 - x % mm1) * (x / mm1) * (x / mm1);
                if (cnt2 - cnt1 >= mid) ll = mm;
                else rr = mm;
            }
            sum += (x % ll) * (x / ll + 1) * (x / ll + 1) + (ll - x % ll) * (x / ll) * (x / ll);
        }
        if (sum > m) r = mid;
        else l = mid;
    }
    int answer = 0, sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        int x = a[i + 1] - a[i];
        int ll = 1, rr = x + 1;
        while (rr - ll > 1) {
            int mm = (ll + rr) / 2;
            int cnt1 = (x % mm) * (x / mm + 1) * (x / mm + 1) + (mm - x % mm) * (x / mm) * (x / mm);
            int mm1 = mm - 1;
            int cnt2 = (x % mm1) * (x / mm1 + 1) * (x / mm1 + 1) + (mm1 - x % mm1) * (x / mm1) * (x / mm1);
            if (cnt2 - cnt1 > l) ll = mm;
            else rr = mm;
        }
        answer += ll - 1;
        sum += (x % ll) * (x / ll + 1) * (x / ll + 1) + (ll - x % ll) * (x / ll) * (x / ll);
    }
    cout << answer + (sum - m + l - 1) / l;
}

/*

 */