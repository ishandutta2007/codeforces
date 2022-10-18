#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}
ftype cross(point a, point b) {
    return (conj(a) * b).y();
}

int sign(int x) {
    return (x > 0) - (x < 0);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int x[n], y[n], vx[n], vy[n];
    point r[n], v[n];
    point dir = point(1, a);
    int pv[n], ov[n];
    map<int, vector<int>> proj;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> vx[i] >> vy[i];
        y[i] = a * x[i] + b;
        r[i] = {x[i], y[i]};
        v[i] = {vx[i], vy[i]};
        ov[i] = cross(dir, v[i]);
        pv[i] = dot(dir, v[i]);
        proj[ov[i]].push_back(pv[i]);
    }
    int ans = 0;
    for(auto it: proj) {
        map<int, int> cnt;
        int total = 0;
        for(auto jt: it.second) {
            ans += total - cnt[jt];
            cnt[jt]++;
            total++;
        }
    }
    cout << 2 * ans << endl;
    return 0;
}