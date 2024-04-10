#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    Point(){}
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct line {
    int a, b, c;
    line() {};
    line(Point &p1, Point &p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p1.x - b * p1.y;
        int ab = __gcd(abs(c), __gcd(abs(a), abs(b)));
        if (a < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        }
        if (a == 0 && b < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        }
        a /= ab;
        c /= ab;
        b /= ab;
    }
    bool operator< (const line &l) const {
        if (a != l.a) {
            return a < l.a;
        }
        if (b != l.b) {
            return b < l.b;
        }
        return c < l.c;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<Point> a(n);
    for (auto &c : a) {
    	cin >> c.x >> c.y;
    }
    map<line, int> cnt1;
    map<pair<int, int>, int> cnt2;
    long long k = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            line l = line(a[i], a[j]);
            cnt1[l]++;
        }
    }
    for (auto &u : cnt1) {
        cnt2[{u.first.a / __gcd(abs(u.first.a), abs(u.first.b)), u.first.b / __gcd(abs(u.first.b), abs(u.first.a))}]++;
        k++;
    }
    long long ans1 = k * (k - 1) / 2;
    long long ans2 = 0;
    for (auto &u : cnt2) {
        ans2 += (u.second * (u.second - 1)) / 2;
    }
    cout << ans1 - ans2;
    return 0;
}