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

int a[N], b[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //    freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    solve();
}