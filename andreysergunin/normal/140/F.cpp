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

struct Point {
    int x, y;

    bool operator<(const Point &other) const {
        return tie(x, y) < tie(other.x, other.y);
    }

    bool operator==(const Point &other) const {
        return tie(x, y) == tie(other.x, other.y);
    }

    Point operator+=(const Point &other) {
        x = x + other.x;
        y = y + other.y;
        return *this;
    }

    Point operator+(const Point &other) const {
        Point tmp = *this;
        return tmp += other;
    }

    Point operator*=(int c) {
        x *= c;
        y *= c;
        return *this;
    }

    Point operator*(int c) const{
        Point tmp = *this;
        return tmp *= c;
    }

    Point operator/(int c) const{
        return Point{x / c, y / c};
    }
};

istream &operator>>(std::istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int n, k;
    cin >> n >> k;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] *= 2;
    }
    sort(all(p));

    if (n <= k) {
        cout << -1 << endl;
        return 0;
    }

    vector<Point> res;

    for (int i = 0; i <= k; ++i) {
        for (int j = 0; i + j <= k; ++j) {
            int lf = i, rg = n - 1 - j;
            Point center = (p[lf] + p[rg]) / 2;
            int bad = i + j;
            while (lf <= rg) {
                if (p[lf] + p[rg] == center * 2) {
                    ++lf;
                    --rg;
                } else if (p[lf] + p[rg] < center * 2)  {
                    ++lf;
                    ++bad;
                } else {
                    --rg;
                    ++bad;
                }
                if (bad > k) {
                    break;
                }
            }   
            if (bad <= k) {
                res.push_back(center);
            }
        }
    }
    sort(all(res));
    res.resize(unique(all(res)) - res.begin());

    cout << sz(res) << endl;

    cout.precision(1);
    cout << fixed;

    for (Point pt : res) {
        cout << (double)pt.x / 2 << " " << (double)pt.y / 2 << endl;
    }

    return 0;
}