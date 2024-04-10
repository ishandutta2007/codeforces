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

struct Point {
    int x, y;

    Point operator -= (const Point &other) {
        x = x - other.x;
        y = y - other.y;
        return *this;
    }
    
    Point operator - (const Point &other) const {
        Point temp = *this;
        return temp -= other;
    }

};

istream &operator >> (std::istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

int cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

int dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

bool inside(const vector<Point> &a, const Point &b) {
    int n = sz(a);
    int s1 = 0, s2 = 0;
    for (int i = 1; i < n - 1; ++i) {
        s1 += abs(cross(a[i] - a[0], a[i + 1] - a[0]));
    }
    for (int i = 0; i < n; ++i) {
        s2 += abs(cross(a[i] - b, a[(i + 1) % n] - b));
    }

    return s1 == s2;
       
}


ostream &operator << (std::ostream &stream, const Point &a) {
    stream << a.x << " " << a.y;
    return stream;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("input.txt", "w", stdout);

    vector<Point> p(4), q(4);
    for (int i = 0; i < 4; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> q[i];
    }

    for (int x = -100; x <= 100; ++x) {
        for (int y = -100; y <= 100; ++y) {
            Point a = {x, y};
            if (inside(p, a) && inside(q, a)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}