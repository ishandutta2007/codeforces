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
    Point() {};
    Point(int x, int y): x(x), y(y) {}
    int x;
    int y;

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

istream &operator >> (std::istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

ostream &operator << (std::ostream &stream, const Point &a) {
    stream << a.x << " " << a.y;
    return stream;
}

ll dist2(const Point &a) {
    return (ll)a.x * a.x + (ll)a.y * a.y;
} 

const int MAXN = 120000;

Point v[MAXN];
ll d[MAXN];
set<int> s[MAXN];
int m[MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 

    int n;
    cin >> n;

    set<pair<ll, int>> setik;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s[i].insert(i);
        m[i] = 1;
        d[i] = dist2(v[i]);
        setik.insert({d[i], i});
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    while (sz(setik) > 2) {
        auto it = setik.end();

        vector<int> id(3);

        for (int i = 0; i < 3; ++i) {
            --it;
            id[i] = it->second;
        }

        bool f = false;

        if (sz(s[id[0]]) < sz(s[id[1]])) {
            swap(id[0], id[1]);
        }
        if (sz(s[id[0]]) < sz(s[id[2]])) {
            swap(id[0], id[2]);
        }
        if (sz(s[id[1]]) < sz(s[id[2]])) {
            swap(id[1], id[2]);
        }


        for (int u1 = 0; u1 < 3; ++u1) {
            for (int u2 = u1 + 1; u2 < 3; ++u2) {
                int i = id[u1], j = id[u2];

                ll mx = max(d[i], d[j]);
                if (dist2(v[i] + v[j]) <= mx) {
                    for (int e : s[j]) {
                        s[i].insert(e);
                    }
                    setik.erase({d[i], i});
                    setik.erase({d[j], j});

                    v[i] += v[j];
                    d[i] = dist2(v[i]);
                    f = true;
                    setik.insert({d[i], i});
                } else 
                if (dist2(v[i] - v[j]) <= mx) {
                    for (int e : s[j]) {
                        s[i].insert(e);
                        m[e] *= -1;
                    }
                    setik.erase({d[i], i});
                    setik.erase({d[j], j});

                    v[i] -= v[j];
                    d[i] = dist2(v[i]);
                    setik.insert({d[i], i});
                    f = true;
                }

                if (f) {
                    break;
                }
            }

            if (f) {
                break;
            }
        }
    }



    auto it = setik.end();

    vector<int> id(2);

    for (int i = 0; i < 2; ++i) {
        --it;
        id[i] = it->second;
    }

    if (dist2(v[id[0]] + v[id[1]]) > dist2(v[id[0]] - v[id[1]])) {
        for (int e : s[id[1]]) {
            m[e] *= -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << m[i] << " ";
    }
    cout << endl;





    
    return 0;
}