#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<sstream>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

typedef long long ll;

struct Point {
    ll x;
    ll y;
    Point(ll _x, ll _y) : x(_x), y(_y) {}
    Point() : x(0), y(0) {}
    bool operator <(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

bool left_turn(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.y - p1.y) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.y - p1.y) > 0;
}

// Returns list of points of convex hull in counter clockwise
// The last point and first point will be equal
vector<Point> convex_hull(vector<Point> p) {
    vector<Point> ret;
    sort(p.begin(), p.end());
    // build lower hull
    for (int i = 0; i < p.size(); ++i) {
        while (ret.size() >= 2 &&
               left_turn(ret[ret.size() - 2], ret[ret.size() - 1], p[i])) {
            ret.pop_back();
        }
        ret.push_back(p[i]);
    }
    int lower_hull_size = ret.size();
    // build upper hull
    for (int i = p.size() - 2; i >= 0; --i) {
        while (ret.size() - lower_hull_size >= 1 &&
               left_turn(ret[ret.size() - 2], ret[ret.size() - 1], p[i])) {
            ret.pop_back();
        }
        ret.push_back(p[i]);
    }
    return ret;
}

ll triangle_area (const Point& p1, const Point& p2, const Point& p3) {
    return abs( p1.x * p2.y +
                p2.x * p3.y +
                p3.x * p1.y -
                p1.y * p2.x -
                p2.y * p3.x -
                p3.y * p1.x);
}

int main (void)
{
//	freopen("input.txt", "r", stdin);

    int n; ll S;
    scanf("%d %I64d", &n, &S);
        vector<Point> p;
        for (int i = 0; i < n; ++i) {
            ll x, y;
            scanf("%I64d %I64d", &x, &y);
            p.push_back(Point(x, y));
        }
        p = convex_hull(p); p.pop_back();
        n = p.size();
        int i = 0;
        int j = i + 1;
        int k = j + 1;
        ll res = 0;
        int resi, resj, resk;
        while (true) {
            ll area = triangle_area(p[i], p[j], p[k]);
            while (true) {
                while (true) {
                    int nk = (k + 1) % n;
                    ll narea = triangle_area(p[i], p[j], p[nk]);
                    if (narea >= area) {
                        k = nk;
                        area = narea;
                    } else {
                        break;
                    }
                }
                int nj = (j + 1) % n;
                ll narea = triangle_area(p[i], p[nj], p[k]);
                if (narea >= area) {
                    j = nj;
                    area = narea;
                } else {
                    break;
                }
            }
            if (area > res) {
            	res = area;
            	resi = i, resj = j, resk = k;
            }
            i++;
            if (i == j) j = (j + 1) % n;
            if (j == k) k = (k + 1) % n;
            if (i == n) break;
        }
    
    Point A = p[resi], B = p[resj], C = p[resk];

    printf("%I64d %I64d\n", A.x + B.x - C.x, A.y + B.y - C.y);
    printf("%I64d %I64d\n", A.x + C.x - B.x, A.y + C.y - B.y);
    printf("%I64d %I64d\n", B.x + C.x - A.x, B.y + C.y - A.y);
    return 0;
}