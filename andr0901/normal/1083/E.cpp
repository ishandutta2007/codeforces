#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

struct Node{
    int x, y, a;
};

#define b first
#define k second

vector <pii> l;
vector <int> p;

int intersect(pii a, pii b) {
    return (b.b - a.b) / (a.k - b.k);
}

void add(pii a) {
    if (l.empty()) {
        l.pb(a), p.pb(1e18);
        return;
    }
    if (a.k == l.back().k) {
        if (a.b <= l.back().b)
            return;
        l.pop_back(), p.pop_back();
        add(a);
        return;
    }
    if (intersect(a, l.back()) > p.back()) {
        l.pop_back(), p.pop_back();
        add(a);
    } else {
        p.pb(intersect(a, l.back())), l.pb(a);
    }
}

int get(int x) {
    int L = 0, R = p.size();
    while (R - L > 1) {
        int m = L + R >> 1;
        if (p[m] >= x)
            L = m;
        else
            R = m;
    }
    return l[L].k * x + l[L].b;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <Node> a(n);
    forn (i, 0, n)
        cin >> a[i].x >> a[i].y >> a[i].a;
    sort(all(a), [&](Node a, Node b) {return a.x < b.x;});
    ll ans = 0;
    vector <int> dp(n);
    forn (i, 0, n) {
        dp[i] = a[i].x * a[i].y - a[i].a;
        if (!l.empty())
            dp[i] = max(dp[i], dp[i] + get(a[i].y));
        ans = max(ans, dp[i]);
        add({dp[i], -a[i].x});
    }
    cout << ans;
    return 0;
}