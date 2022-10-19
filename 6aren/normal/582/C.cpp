#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

int n, a[N];
vector<int> v[N];

void solve(int t, long long &res) {
    vector<int> mx(t, 0);
    for (int i = 0; i < t; i++) {
        for (int j = i; j < n; j += t) {
            mx[i] = max(mx[i], a[j]);
        }
    }
    vector<int> ok(n);
    for (int i = 0; i < n; i++) ok[i] = (a[i] == mx[i % t]);
    vector<int> segs;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ok[i]) cnt++;
        else {
            if (cnt) segs.pb(cnt);
            cnt = 0;
        }
    }
    if (cnt) segs.pb(cnt);
    vector<int> tmp = segs;
    sort(all(tmp));
    vector<int> suff = tmp;
    for (int i = (int) suff.size() - 2; i >= 0; i--) suff[i] = suff[i + 1] + suff[i];
    bool l = ok[0];
    bool r = ok.back();
    for (int e : v[t]) {
        int k = lower_bound(all(tmp), e) - tmp.begin();
        if (k != tmp.size()) res += suff[k] - (e - 1) * (suff.size() - k);
        if (l && r) {
            int lef = segs[0];
            int righ = segs.back();
            if (lef + righ >= e) res += min(righ, lef + righ - e + 1) - max(0, righ - e + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        v[__gcd(i, n)].pb(i);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (!v[i].empty()) solve(i, res);
    }
    cout << res;
    return 0;
}