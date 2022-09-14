#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    vector<int> b(m);
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    sort(all(a));
    sort(all(b));
    // if (a.back() > b.back()) {
    //     cout << "YES" << endl;
    //     return 0;
    // }

    // for (int i = 0; i < n; ++i) {
    //     a[i] = *lower_bound(all(b), a[i]);
    // }

    reverse(all(a));
    reverse(all(b));

    int it = 0;
    for (int i = 0; i < n; ++i) {
        for (; it < m && b[it] >= a[i]; ++it);
        if (it <= i) {
            cout << "YES" << endl;
            return 0;
        }
    }

    // int it = 0;

    // for (int i = 0; i < n; ) {
    //     int j = i;
    //     for (; j < n && a[j] == a[i]; ++j);

    //     for (; it < m && b[it] < a[i]; ++it);
    //     int l = it;
    //     for (; it < m && b[it] == a[i]; ++it);
    //     int r = it;

    //     if (j - i > r - l) {
    //         cout << "YES" << endl;
    //         return 0;
    //     }
    //     i = j;
    // }

    cout << "NO" << endl;
    return 0;
}