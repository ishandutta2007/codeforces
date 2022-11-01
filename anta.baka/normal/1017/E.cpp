#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<ll, ll>;
using vi = vector<int>;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
const int maxn = 1e6, mod = 1e9 + 7;

bool cw(pii a, pii b, pii c) {
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) < 0;
}
bool ccw(pii a, pii b, pii c) {
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) > 0;
}

int n, m;

vector<pii> conv(int n, vector<pii> a) {
    sort(all(a));
    pii p1 = a[0], p2 = a.back();
    vector<pii> up = {a[0]}, down = {a[0]};
    for(int i = 1; i < sz(a); i++) {
        if(i == sz(a) - 1 || cw(p1, a[i], p2)) {
            while(sz(up) >= 2 && !cw(up[sz(up) - 2], up[sz(up) - 1], a[i])) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if(i == sz(a) - 1 || ccw(p1, a[i], p2)) {
            while(sz(down) >= 2 && !ccw(down[sz(down) - 2], down[sz(down) - 1], a[i])) {
                down.pop_back();
            }
            down.push_back(a[i]);
        }
    }
    a.clear();
    for(int i = 0; i < sz(up); i++) a.push_back(up[i]);
    for(int i = sz(down) - 2; i > 0; i--) a.push_back(down[i]);
    return a;
}
ld len(pii v) {
    return sqrt(1.0*v.x*v.x+v.y*v.y);
}
const ld eps = 1e-6;
bool same(pair<ld,ld> a, pair<ld,ld> b) {
    return abs(a.x-b.x)<eps && abs(a.y-b.y)<eps;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    a = conv(n, a);
    vector<pii> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i].x >> b[i].y;
    }
    b = conv(m, b);
    n = sz(a);
    m = sz(b);
    if(n != m) return cout << "NO", 0;
    //for(int i = 0; i < n; i++) cout << a[i].x << ' ' << a[i].y << endl;
    //cout << endl;
    //for(int i = 0; i < m; i++) cout << b[i].x << ' ' << b[i].y << endl;
    vector<pair<ld, ld>> c(n), d(n);
    a.push_back(a[0]);
    a.push_back(a[1]);
    b.push_back(b[0]);
    b.push_back(b[1]);
    for(int i = 0; i < n; i++) {
        pii v1 = {a[i+1].x-a[i].x, a[i+1].y-a[i].y};
        pii v2 = {a[i+2].x-a[i+1].x, a[i+2].y-a[i+1].y};
        c[i] = {1.0*(v1.x*v2.x + v1.y*v2.y)/len(v1)/len(v2), len(v1)};
    }
    for(int i = 0; i < n; i++) {
        pii v1 = {b[i+1].x-b[i].x, b[i+1].y-b[i].y};
        pii v2 = {b[i+2].x-b[i+1].x, b[i+2].y-b[i+1].y};
        d[i] = {1.0*(v1.x*v2.x + v1.y*v2.y)/len(v1)/len(v2), len(v1)};
    }
    c.reserve(3 * n + 1);
    c.push_back({-1, -1});
    for(int i = 0; i < n; i++) c.push_back(d[i]);
    for(int i = 0; i < n; i++) c.push_back(d[i]);
    vector<int> p(sz(c), 0);
    for(int i = 1; i < sz(c); i++) {
        int k = p[i - 1];
        while(k > 0 && !same(c[i], c[k])) k = p[k - 1];
        if(same(c[i], c[k])) k++;
        p[i] = k;
        if(p[i] == n) return cout << "YES", 0;
    }
    cout << "NO";
}