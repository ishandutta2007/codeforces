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
typedef double ld;
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

    vector<pii> x(n);
    vector<int> y(n);


    ll sx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first;
        sx += x[i].first;
        x[i].second = i;
    }

    ll sy = 0;
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
        sy += y[i];
    }

    if (sx != sy) {
        cout << "NO" << endl;
        return 0;
    }

    sort(all(x));
    sort(all(y));

    set<pair<int, pii>> setik;

    vector<vector<int>> res;

    vector<pair<int, pii>> st;

    for (int i = 0; i < n; ++i) {
        int xx = x[i].first;
        if (xx < y[i]) {
            st.push_back({xx, {y[i], x[i].second}});
            continue;
        }

        while (xx != y[i]) {
            if (sz(st) == 0) {
                cout << "NO" << endl;
                return 0;
            }
            auto p = st.back();
            st.pop_back();

            int d = min(p.second.first - p.first, xx - y[i]);
            xx -= d;
            p.first += d;


            res.push_back({p.second.second + 1, x[i].second + 1, d});

            if (p.first != p.second.first) {
                st.push_back(p);
            }
        }
    }

    cout << "YES" << endl;
    cout << sz(res) << endl;

    for (auto arr : res) {
        for (int el : arr) {
            cout << el << " ";
        }
        cout << endl;
    }

}