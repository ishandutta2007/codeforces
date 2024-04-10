#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

struct Point {
    int x, y;
};

bool operator < (const Point &a, const Point &b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

bool operator == (const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

vector<Point> p;
vector<Point> q;

void solve(int l, int r) {
    if (r - l > 1) {
        int mid = (l + r) / 2;
        solve(l, mid);
        solve(mid, r);
        for (int i = l; i < r; ++i)
            q.push_back({p[mid].x, p[i].y});
    } 
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;

    sort(all(p));
    q = p;
    solve(0, n);

    sort(all(q));
    int m = unique(all(q)) - q.begin();

    cout << m << endl;
    for (int i = 0; i < m; ++i) 
        cout << q[i].x << " " << q[i].y << endl;
    
    return 0;
}