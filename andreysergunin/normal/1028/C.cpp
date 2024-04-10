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
typedef long double ld;
typedef unsigned int uint;
typedef complex<double> Complex;

mt19937 rnd(random_device{}());

template<class T>
void print(const vector<T> &arr) {
    for (T a : arr)  {
        cout << a << " ";
    }
    cout << endl;
}

const int INF = 1.1e9;

void precalc() {

}

struct Rect {
    int x1, y1, x2, y2;
};

bool inside(const Rect &a, int x, int y) {
    return a.x1 <= x && x <= a.x2 && a.y1 <= y && y <= a.y2;
}

bool check(const vector<Rect> &r, int x, int y) {
    int n = sz(r);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += inside(r[i], x, y);
    }
    return n - cnt <= 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<Rect> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
    }

    vector<int> x = {INF, -INF};
    vector<int> y = {INF, -INF};
    for (int i = 0; i < n; ++i) {
        x[0] = min(x[0], r[i].x2);
        x[1] = max(x[1], r[i].x1);
        y[0] = min(y[0], r[i].y2);
        y[1] = max(y[1], r[i].y1);
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (check(r, x[i], y[j])) {
                cout << x[i] << " " << y[j] << endl;
                return 0;
            }
        }
    }
    assert(false);

}