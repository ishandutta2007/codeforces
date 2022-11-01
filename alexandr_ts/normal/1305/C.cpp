#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <random>
#include <sstream>
#include <string>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const int N = 1e6 + 10;

int cnt[N];
ll a[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        cnt[x % m]++;
    }

    for (int i = 0; i < m; ++i) {
        if (cnt[i] > 1) {
            cout << 0 << endl;
            return;
        }
    }

    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = (ans * abs(a[i] - a[j])) % m;
        }
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //    freopen("a.in", "r", stdin);
    solve();
}