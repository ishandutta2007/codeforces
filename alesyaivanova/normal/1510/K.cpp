#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int INF = 1e9 + 239;

void make(vector<int> &p, int tp) {
    if (tp == 0) {
        for (int i = 0; i + 1 < (int)p.size(); i += 2) {
            swap(p[i], p[i + 1]);
        }
    } else {
        for (int i = 0; i < (int)p.size() / 2; i++) {
            swap(p[i], p[i + (int)p.size() / 2]);
        }
    }
}

int solve(vector<int> p, int st) {
    for (int i = 0; i < 10 * (int)p.size(); i++) {
        if (is_sorted(p.begin(), p.end())) {
            return i;
        }
        make(p, (i + st) % 2);
    }
    return INF;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (auto &t : a) {
        cin >> t;
    }
    int ans = min(solve(a, 0), solve(a, 1));
    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}