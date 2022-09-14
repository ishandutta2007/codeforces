#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

struct point {
    point() : x(0), y(0) {};
    point(long long x, long long y) : x(x), y(y) {};
    long long x;
    long long y;
};

bool operator < (point a, point b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool operator == (point a, point b) {
    return (a.x == b.x && a.y == b.y);
}

point operator + (point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}

point operator - (point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

point operator * (point a, long long c) {
    return point (a.x * c, a.y * c);
}

long long crossProduct(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

bool angleComp(point a, point b) {
    if (crossProduct(a, b) > 0)
        return true;
    return false;
}

bool inside(point a, point b, point c, point d) {
    long long S1 = abs(crossProduct(b - a, c - a));
    long long S2 = abs(crossProduct(c - a, d - a));
    long long S3 = abs(crossProduct(d - a, b - a));
    long long S = abs(crossProduct(c - b, d - b));
    return (S == S1 + S2 + S3);
}

int main() {
    int n[3];
    point cur;
    vector<point> a[3];
    for (int i = 0; i < 3; i++) {
        point minX(1e9, 1e9);
        cin >> n[i];
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j].x >> a[i][j].y;
            if (a[i][j] < minX)
                minX = a[i][j];
        }
        cur = cur + minX;
    }
    
    vector<point> p, v[2];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n[i]; j++) {
            point b = a[i][(j + 1) % n[i]] - a[i][j];
            if (b < point(0, 0))
                v[1].push_back(b);
            else
                v[0].push_back(b);
        }
    
    point start = cur;
    for (int i = 0; i < 2; i++) {
        sort(v[i].begin(), v[i].end(), angleComp);
        for (int j = 0; j < (int)v[i].size(); j++) {
            p.push_back(cur - start);
            cur = cur + v[i][j];
        }
    }
    
    int m;
    cin >> m;
    int l0 = 1;
    for ( ; crossProduct(p[l0], p[l0 + 1]) == 0; l0++);
    for (int i = 0; i < m; i++) {
        int n = (int)p.size();
        point q;
        cin >> q.x >> q.y;
        q = (q * 3) - start;
        
        if (q == p[0]) {
            cout << "YES" << endl;
            continue;
        }
        if (q < p[0]) {
            cout << "NO" << endl;
            continue;
        }
        
        int l = l0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (crossProduct(p[mid], q) > 0)
                l = mid;
            else
                r = mid;
        }
        if (inside(q, p[0], p[l], p[l + 1]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}