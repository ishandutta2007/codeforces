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
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> used(n);

    int q;
    cin >> q;
    vector<int> t(q);
    vector<int> x(q);
    vector<int> id(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i];
        if (t[i] == 1) {
            cin >> id[i];
            --id[i];
        }
        cin >> x[i];
    }

    int maxx = 0;

    vector<int> res(n);

    for (int i = q - 1; i >= 0; --i) {
        if (t[i] == 2) {
            maxx = max(maxx, x[i]);
        } else {
            if (used[id[i]]) {
                continue;
            }
            used[id[i]] = 1;
            res[id[i]] = max(maxx, x[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            res[i] = max(a[i], maxx);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

}