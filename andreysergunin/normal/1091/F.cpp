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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef pair<ll, int> pli;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 6e17;

struct Point {
    ll x, y;
};

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

Point operator/(const Point &a, ll c) {
    return {a.x / c, a.y / c};
}

Point operator*(const Point &a, ll c) {
    return {a.x * c, a.y * c};
}

bool operator==(const Point &a, const Point &b) {
    return (a.x == b.x && a.y == b.y);
}

bool operator!=(const Point &a, const Point &b) {
    return (a.x != b.x || a.y != b.y);
}

Point norm(const Point &a) {
    return a / a.x;
}

vector<Point> add(vector<Point> p1, vector<Point> p2) {
    // for (int i = 0; i < sz(p1); ++i) {
    //     cout << p1[i].x << " " << p1[i].y << endl;
    // }
    // cout << endl;    
    // for (int i = 0; i < sz(p2); ++i) {
    //     cout << p2[i].x << " " << p2[i].y << endl;
    // }
    // cout << endl;



    vector<Point> p = {p1[0] + p2[0]};

    int i = 0, j = 0;
    while (i < sz(p1) - 1 && j < sz(p2) - 1) {
        ll x = (p1[i + 1].y - p1[i].y) / (p1[i + 1].x - p1[i].x);
        ll y = (p2[j + 1].y - p2[j].y) / (p2[j + 1].x - p2[j].x);

        if (x < y) {
            p.push_back(p.back() + p1[i + 1] - p1[i]);
            ++i;
        } else {
            p.push_back(p.back() + p2[j + 1] - p2[j]);
            ++j;
        }
    }

    while (i < sz(p1) - 1) {
        p.push_back(p.back() + p1[i + 1] - p1[i]);
        ++i;
    }

    while (j < sz(p2) - 1) {
        p.push_back(p.back() + p2[j + 1] - p2[j]);
        ++j;
    }

    // for (int i = 0; i < sz(p); ++i) {
    //     cout << p[i].x << " " << p[i].y << endl;
    // }


    vector<Point> res = {p[0]};

    for (int i = 1; i < sz(p) - 1; ++i) {
        if (norm(p[i] - p[i - 1]) != norm(p[i + 1] - p[i])) {
            res.push_back(p[i]);
        }
    }

    res.push_back(p.back());

    return res;
}

vector<Point> cut(vector<Point> p) {
    vector<Point> res; 
    for (int i = 0; i < sz(p); ++i) {
        if (0 <= p[i].x && p[i].x <= INF) {
            res.push_back(p[i]);
        }
        if (i + 1 < sz(p) && p[i].x < 0 && 0 < p[i + 1].x) {
            res.push_back(p[i] + norm(p[i + 1] - p[i]) * (0 - p[i].x));
        }
        if (i + 1 < sz(p) && p[i].x < INF && INF < p[i + 1].x) {
            res.push_back(p[i] + norm(p[i + 1] - p[i]) * (INF - p[i].x));
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> l(n);

    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    string s;
    cin >> s;

    vector<Point> p;
    p.push_back({0, 0}); 
    p.push_back({INF, 5 * INF});

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            vector<Point> q;
            q.push_back({-l[i], l[i]});
            q.push_back({l[i], 5 * l[i]});
            q.push_back({INF, 5 * INF});
            p = cut(add(p, q));
        } else if (s[i] == 'W') {
            vector<Point> q;
            q.push_back({-l[i], l[i]});
            q.push_back({l[i], 3 * l[i]});
            q.push_back({INF, 3 * INF});
            p = cut(add(p, q));
        } else {
            vector<Point> q;
            q.push_back({-l[i], l[i]});
            p = cut(add(p, q));
        }
    }

    cout << p[0].y << endl;
}