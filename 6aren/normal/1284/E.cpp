#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define double long double
#define int long long

const double PI = acos(-1.0);

const int N = 2505;

int n;
ii a[N];

int part(ii a) {
    if (a.x > 0 && a.y >= 0) return 1;
    if (a.x <= 0 && a.y > 0) return 2;
    if (a.x < 0 && a.y <= 0) return 3;
    if (a.x >= 0 && a.y < 0) return 4;
    return 0; 
}

bool cmp(ii a, ii b) {
    int u = part(a);
    int v = part(b);
    if (u != v) return (u < v);
    if (u == 1 || u == 3) {
        a.x = abs(a.x);
        a.y = abs(a.y);
        b.x = abs(b.x);
        b.y = abs(b.y);
        return (1LL * a.x * b.y > 1LL * a.y * b.x);
    } else {
        a.x = abs(a.x);
        a.y = abs(a.y);
        b.x = abs(b.x);
        b.y = abs(b.y);
        return (1LL * a.x * b.y < 1LL * a.y * b.x);
    }
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("in", "r", stdin);
    //cout << acos(0.5) << ' ' << acos(-0.5) << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long tempAns = 0;
        vector<ii> v;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            int xx = a[j].x - a[i].x;
            int yy = a[j].y - a[i].y;
            v.pb({xx, yy});
        }
        sort(all(v), cmp);
        for (int j = 0; j < (int) v.size(); j++) {
            ii u = v[j];
            int k;
            if (part(u) > 2) k = n - 2 - j; 
            else {
                u.x = -u.x;
                u.y = -u.y;
                k = upper_bound(all(v), u, cmp) - v.begin();
                k -= j + 1;
                u = v[j];
            }
            if (part(u) > 2) {
                u.x = -u.x;
                u.y = -u.y;
                int t = upper_bound(all(v), u, cmp) - v.begin();
                k += t;
            }
            if (k < 3) continue;
            tempAns += 1LL * k * (k - 1) * (k - 2) / 6;
        }
        ans += (1LL * (n - 4) * (n - 1) * (n - 2) * (n - 3)) / 24 - tempAns;
    }
    cout << ans;
    return 0;
}