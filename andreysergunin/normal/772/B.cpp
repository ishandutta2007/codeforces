#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const ll INF = 1e18 + 10;
const int OPS = 100;

struct Point {
    Point() {};
    Point(ll x, ll y): x(x), y(y) {}
    ll x, y;

    Point operator += (const Point &other) {
        x = x + other.x;
        y = y + other.y;
        return *this;
    }

    Point operator + (const Point &other) const {
        Point temp = *this;
        return temp += other;
    }

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

ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

ll dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

double dist(const Point &a) {
    return sqrt(dot(a, a));
}


istream &operator >> (std::istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

int n;
int nxt(int k) {
    return (k == n - 1 ? 0 : k + 1);
}

int prv(int k) {
    return (k == 0 ? n - 1 : k - 1);
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
        
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) 
        cin >> p[i];

    cout.precision(12);
    cout << fixed;
    double ans = INF;
    for (int i = 0; i < n; ++i) {
        int l = (i == n - 1 ? 0 : i + 1);
        for (int j = l; j != i; j = nxt(j)) {
            for (; nxt(l) != i && cross(p[l] - p[i], p[j] - p[i]) < cross(p[nxt(l)] - p[i], p[j] - p[i]); l = nxt(l));
            if (l != j)
                ans = min(ans, (double)cross(p[l] - p[i], p[j] - p[i]) / dist(p[i] - p[j]) / 2);
        }
    }
    cout << ans << endl;

}