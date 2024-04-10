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

struct Point {
    int x, y;

    bool operator<(const Point &other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }

    bool operator==(const Point &other) const {
        return other.x == x && other.y == y;
    }
};

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}




ll len(const Point &a) {
    return (ll)a.x * a.x + (ll)a.y * a.y;
}

int gcd(int x, int y) {
    return (y == 0 ? x : gcd(y, x % y));
}

void norm(Point &a) {
    int g = gcd(a.x, a.y);
    a.x /= g;
    a.y /= g;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    map<ll, vector<Point>> mapa;
    map<Point, int> cnt;
    // map<Point, int> online;

    int n;
    cin >> n;
    int m = 0;

    for (int q = 0; q < n; ++q) {
        int type;
        cin >> type;
        if (type == 1) {
            ++m;
            Point p;
            cin >> p.x >> p.y;
            ll l = len(p);
            vector<Point> &arr = mapa[l];
            arr.push_back(p);
            for (int i = 0; i < sz(arr) - 1; ++i) {
                Point q = arr[i] + p;
                norm(q);
                cnt[q] += 2;
            }

            norm(p);
            ++cnt[p];

            // ++online[p];

        } else if (type == 2) {
            --m;
            Point p;
            cin >> p.x >> p.y;
            ll l = len(p);
            vector<Point> &arr = mapa[l];
            int k = -1;
            for (int i = 0; i < sz(arr); ++i) {
                if (arr[i] == p) {
                    swap(arr[i], arr.back());
                    break;
                }
            }
            for (int i = 0; i < sz(arr) - 1; ++i) {
                Point q = arr[i] + p;
                norm(q);
                cnt[q] -= 2;
            }
            arr.pop_back();

            norm(p);
            --cnt[p];

            // --online[p];
        } else {
            Point p;
            cin >> p.x >> p.y;
            norm(p);
            // cout << p.x << " " << p.y << endl;

            // cout << m << " " << cnt[p] << endl;
            // cout << m - 2 * cnt[p] - online[p] << endl;
            cout << m - cnt[p] << endl;
        }
    }


}