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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 100100;

int a[2 * MAXN];
int b[2 * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<pair<char, int>> req;

    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        req.push_back({c, x});
    }

    int lim = 320;

    int k = 100001;

    for (int i = -k; i <= k; ++i) {
        a[i + k] = i;
    }


    for (int l = 0; l < m; ) {
        int r = min(m, l + lim);

        vector<int> x = {-k, k + 1};

        for (int i = l; i < r; ++i) {
            int xx = req[i].second;
            if (req[i].first == '>') { 
                x.push_back(xx + 1);
                x.push_back(- xx);
            } else {
                x.push_back(xx);
                x.push_back(- xx + 1);
            }
        }

        sort(all(x));
        x.resize(unique(all(x)) - x.begin());

        for (int i = 0; i < sz(x) - 1; ++i) {
            int cur = x[i];
            for (int j = l; j < r; ++j) {
                if (req[j].first == '<') {
                    if (cur < req[j].second) {
                        cur = -cur;
                    }
                } else {
                    if (cur > req[j].second) {
                        cur = -cur;
                    }
                }
            }
            if (cur == x[i]) {
                for (int j = x[i] + k; j < x[i + 1] + k; ++j) {
                    b[j] = 1;
                } 
            } else {
                for (int j = x[i] + k; j < x[i + 1] + k; ++j) {
                    b[j] = -1;
                } 
            }
        }

        for (int i = 0; i <= 2 * k; ++i) {
            a[i] = a[i] * b[a[i] + k];
        }

        l = r;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[arr[i] + k] << " ";
    }
    cout << endl;
}