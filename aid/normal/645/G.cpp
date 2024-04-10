#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;

    Point () {}

    Point(double _x, double _y): x(_x), y(_y) {}
};

const int MAXN = 100 * 1000 + 5;
Point p[MAXN];

bool solve(int n, double a, double c) {
    double b = sqrt(c * c - a * a);
    vector< pair<double, double> > ev;
    for(int i = 0; i < n; i++) {
        double x = p[i].x / a, y = p[i].y / b, invr = fabs(x) / sqrt(1. + y * y);
        if(invr > 1)
            continue;
        double phi = atan2(y, 1.);
        if(x < 0) {
            phi += M_PI;
            if(phi > M_PI)
                phi -= 2 * M_PI;
        }
        double d = acos(invr), l = phi - d, r = phi + d;
        if(r > M_PI) {
            l -= 2 * M_PI;
            r -= 2 * M_PI;
        }
        ev.push_back(make_pair(l, r));
        ev.push_back(make_pair(l + 2 * M_PI, r + 2 * M_PI));
    }
    sort(ev.begin(), ev.end());
    vector<double> st;
    for(size_t i = 0; i < ev.size(); i++) {
        while(!st.empty() && st.back() < ev[i].first)
            st.pop_back();
        if(!st.empty() && st.back() < ev[i].second)
            return true;
        st.push_back(ev[i].second);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    double c;
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    double l = 0, r = c;
    for(int it = 0; it < 50; it++) {
        double m = (l + r) / 2;
        if(solve(n, m, c))
            r = m;
        else
            l = m;
    }
    cout << 2 * l << '\n';
    return 0;
}