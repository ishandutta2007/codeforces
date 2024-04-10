#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

pair<int, ii> que[N];
int q;
set<ii> vec[N];

ii perpen(ii a, ii b) {
    ii res;
    res.x = (a.x + b.x);
    res.y = (a.y + b.y);
    int gcd = __gcd(abs(res.x), abs(res.y));
    res.x /= gcd;
    res.y /= gcd;
    if (res.x < 0) res = {-res.x, -res.y};
    if (res.x == 0 && res.y < 0) res = {0, -res.y};
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> q;
    set<long long> s;
    map<long long, int> mp;
    int sz = 0;

    for (int i = 1; i <= q; i++) {
        cin >> que[i].x >> que[i].y.x >> que[i].y.y;
        if (que[i].x == 1) {
            s.insert(1LL * que[i].y.x * que[i].y.x + 1LL * que[i].y.y * que[i].y.y);
        }
    }

    int cur = 0;
    for (long long e : s) mp[e] = ++cur;

    unordered_map<long long, int> ans;

    for (int i = 1; i <= q; i++) {
        if (que[i].x == 1) {
            sz++;
            long long foo = 1LL * que[i].y.x * que[i].y.x + 1LL * que[i].y.y * que[i].y.y;
            int id = mp[foo];
            for (auto e : vec[id]) {
                ii t = perpen(que[i].y, e);
                ans[1LL * t.x * 1000000000 + t.y] -= 2;
            }
            ii baz = perpen(que[i].y, que[i].y);
            ans[1LL * baz.x * 1000000000 + baz.y]--;
            vec[id].insert(que[i].y);
        } else if (que[i].x == 2) {
            sz--;
            long long foo = 1LL * que[i].y.x * que[i].y.x + 1LL * que[i].y.y * que[i].y.y;
            int id = mp[foo];
            vec[id].erase(que[i].y);
            for (auto e : vec[id]) {
                ii t = perpen(que[i].y, e);
                ans[1LL * t.x * 1000000000 + t.y] += 2;
            }
            ii baz = perpen(que[i].y, que[i].y);
            ans[1LL * baz.x * 1000000000 + baz.y]++;
        } else {
            ii foo = perpen(que[i].y, que[i].y);
            cout << sz + ans[1LL * foo.x * 1000000000 + foo.y] << '\n';
        }
    }

    return 0;
}