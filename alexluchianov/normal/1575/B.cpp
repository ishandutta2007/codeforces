#include <bits/stdc++.h>

using namespace std;

#define ld long double
const ld PI = 2 * acos(0.0);

vector<pair<ld, ld>> pts;

ld angle(ld x, ld y) {
    ld ret = atan2(y, x);
    if(ret < 0.0) ret += 2 * PI;

    return ret;
}

int ok(ld rad) {
    vector<pair<ld, int>> events;

    for(auto pt : pts) {
        ld dist = sqrt(pt.first * pt.first + pt.second * pt.second);

        if(dist > 2 * rad) continue;

        ld angle_pt = angle(pt.first, pt.second);
        ld alpha = (PI - 2 * asin(dist / (2.0 * rad))) / 2.0;

        events.push_back({angle_pt - alpha, +1});
        events.push_back({angle_pt + alpha + 1e-12, -1});
        events.push_back({angle_pt - alpha + 2 * PI, +1});
        events.push_back({angle_pt + alpha + 1e-12 + 2 * PI, -1});
    }

    sort(events.begin(), events.end());
    
    int ret = 0, ret_max = 0;

    for(auto e : events) {
        ret += e.second;
        ret_max = max(ret_max, ret);
    }

    return ret_max;
}

int main() {
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int _x, _y; cin >> _x >> _y;
        ld x, y; x = _x; y = _y;
        if(_x == 0 && _y == 0) k--;
        else pts.push_back({x, y});
    }

    ld st = 1e-12, dr = 200000.0;
    ld sol = dr;
    while(dr - st > 1e-8) {
        ld mid = (st + dr) / 2;
        if(ok(mid) >= k) sol = mid, dr = mid - 1e-8;
        else st = mid + 1e-8;
    }

    cout << fixed << setprecision(12) << sol << endl;
    return 0;
}