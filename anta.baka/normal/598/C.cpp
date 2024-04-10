#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct point {
    ld x,y,a;
    int idx;
    point(){}
    void calc() {
        a = atan2((ld)y,(ld)x);
    }
    bool operator < (const point &p) const {
        return a < p.a;
    }
};

int main() {
    int n;
    cin >> n;
    vector<point> pts(n);
    for(int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].calc();
        pts[i].idx = i;
    }
    sort(pts.begin(),pts.end());
    pts.push_back(pts[0]);
    pts.back().a+=(ld)2*acos((ld)-1.0);
    ld lo=100;
    int fi, se;
    for(int i = 0; i < n; i++) {
        ld angle = pts[i+1].a - pts[i].a;
        if(angle < lo) {
            lo = angle;
            fi = pts[i+1].idx;
            se = pts[i].idx;
        }
    }
    cout << fi+1 << ' ' << se+1;
}