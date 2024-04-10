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

int n;
vector<pii> res;
vector<int> a;

void swapp(int i, int j) {
    // cout << i << " " << j << endl;
    swap(a[i], a[j]);
    if (i > j) {
        swap(i, j);
    }

    if (j < n / 2) {
        res.push_back({i, n - 1});
        res.push_back({j, n - 1});
        res.push_back({i, n - 1});
    } else if (i >= n / 2) {
        res.push_back({i, 0});
        res.push_back({j, 0});
        res.push_back({i, 0});
    } else {

        if (i == 0 || j == n - 1) {
            res.push_back({i, j});
        } else {
            res.push_back({i, n - 1});
            res.push_back({j, 0});
            res.push_back({0, n - 1});
            res.push_back({j, 0});
            res.push_back({i, n - 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    
    vector<int> b = a;

    for (int i = 0; i < n; ++i) {
        while (a[i] != i) {
            swapp(a[i], i);
        }
    }

    // for (int i = 0; i < 10; ++i) {
    //     
    // }

    cout << sz(res) << endl;
    for (pii p : res)  {
        // swap(b[p.first], b[p.second]);
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }

    // for (int el : b) {
    //     cout << el << " ";
    // }
    // cout << endl;
}