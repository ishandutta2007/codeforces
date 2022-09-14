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
    int n;
    cin >> n;

    vector<pair<int, int>> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i].first;
        s[i].second = i;;
    }

    sort(all(s));

    vector<int> a(n);
    vector<int> b(n);
    int k = (n - (n % 3)) / 3;
    for (int i = 0; i < k; ++i) {
        int id = s[i].second;
        a[id] = i;
        b[id] = s[i].first - a[id];
    }

    for (int i = k; i < 2 * k; ++i) {
        int id = s[i].second;
        b[id] = i;
        a[id] = s[i].first - b[id];
    }

    for (int i = 2 * k; i < 3 * k; ++i) {
        int id = s[i].second;
        b[id] = 3 * k - i - 1;
        a[id] = s[i].first - b[id];
    }

    for (int i = 3 * k; i < n; ++i) {
        int id = s[i].second;
        if (i & 1) {
            a[id] = s[i].first;
            b[id] = 0;
        } else {
            b[id] = s[i].first;
            a[id] = 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}