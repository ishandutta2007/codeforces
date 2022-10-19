#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
#define ll long long
const int MAXC = 1e5;
const int SQ = 320;
int cnt[MAXC + MAXC * SQ + 1];

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int s = 0; s <= SQ; ++s) {
        for (int j = n - 1; j >= 0; --j) {
            int val = a[j] + s * (n - 1 - j);
            ans = max(ans, 1 + cnt[val]);
            ++cnt[val];
        }
        for (int j = n - 1; j >= 0; --j) {
            int val = a[j] + s * (n - 1 - j);
            --cnt[val];
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        for (int j = i + 1; cur <= MAXC && j < n; ++j) {
            cur += SQ;
            if (a[j] < a[i]) continue;
            int v1 = a[j] - a[i], v2 = j - i;
            if (v1 % v2 != 0) continue;
            int s = v1 / v2;
            ++cnt[s];
            ans = max(ans, cnt[s] + 1);
        }
        cur = a[i];
        for (int j = i + 1; cur <= MAXC && j < n; ++j) {
            cur += SQ;
            if (a[j] < a[i]) continue;
            int v1 = a[j] - a[i], v2 = j - i;
            if (v1 % v2 != 0) continue;
            int s = v1 / v2;
            --cnt[s];
        }
    }
    for (int& i : a) i = MAXC - i;
    for (int s = 0; s <= SQ; ++s) {
        for (int j = n - 1; j >= 0; --j) {
            int val = a[j] + s * (n - 1 - j);
            ans = max(ans, 1 + cnt[val]);
            ++cnt[val];
        }
        for (int j = n - 1; j >= 0; --j) {
            int val = a[j] + s * (n - 1 - j);
            --cnt[val];
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        for (int j = i + 1; cur <= MAXC && j < n; ++j) {
            cur += SQ;
            if (a[j] < a[i]) continue;
            int v1 = a[j] - a[i], v2 = j - i;
            if (v1 % v2 != 0) continue;
            int s = v1 / v2;
            ++cnt[s];
            ans = max(ans, cnt[s] + 1);
        }
        cur = a[i];
        for (int j = i + 1; cur <= MAXC && j < n; ++j) {
            cur += SQ;
            if (a[j] < a[i]) continue;
            int v1 = a[j] - a[i], v2 = j - i;
            if (v1 % v2 != 0) continue;
            int s = v1 / v2;
            --cnt[s];
        }
    }
    cout << n - ans;
}