#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const ll INF = 2e9;
const int N = 1001;
const int MAX = 1e6;

struct Pt {
    ll x, y;
    Pt(int x, int y): x(x), y(y) {}
    Pt(ll x, ll y): x(x), y(y) {}
    Pt() {}
    bool operator == (const Pt& a) const {
        return x == a.x && y == a.y;
    }
    bool operator < (const Pt& a) const {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
};

ll crPr(Pt a, Pt b) {
    return a.x * b.y - a.y * b.x;
}

ll dotPr(Pt a, Pt b) {
    return a.x * b.x + a.y * b.y;
}

struct Ln {
    ll a, b, c;
    Ln() {}
    Ln(ll a, ll b, ll c): a(a), b(b), c(c) {}
    Ln(Pt p1, Pt p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p1.y * p2.x - p1.x * p2.y;
    }
};

Pt interLines(Ln l1, Ln l2) {
    if (crPr(Pt(l1.a, l1.b), Pt(l2.a, l2.b)) == 0)
        return {INF, INF};
    ll t1 = -l1.c * l2.b + l1.b * l2.c;
    ll b1 = l1.a * l2.b - l2.a * l1.b;

    ll t2 = -l1.a * l2.c + l1.c * l2.a;
    ll b2 = b1;

    if (t1 % b1 == 0 && t2 % b2 == 0 && abs(t1 / b1) <= MAX && abs(t2 / b2) <= MAX)
        return {t1 / b1, t2 / b2};
    return {INF, INF};
}

bool ptOnSeg(Pt a, pair<Pt, Pt> seg) {
    Pt a1 = seg.first;
    Pt a2 = seg.second;
    return a.x >= min(a1.x, a2.x) && a.x <= max(a1.x, a2.x) &&
            a.y >= min(a1.y, a2.y) && a.y <= max(a1.y, a2.y);
}

pair<Pt, Pt> a[N];

Pt interSegs(pair<Pt, Pt> seg1, pair<Pt, Pt> seg2) {
    Pt a1 = seg1.first;
    Pt a2 = seg1.second;
    Pt b1 = seg2.first;
    Pt b2 = seg2.second;
    if (a1 == b1 || a1 == b2)
        return a1;
    if (a2 == b1 || a2 == b2)
        return a2;
    Ln l1(a1, a2);
    Ln l2(b1, b2);

    auto t = interLines(l1, l2);
    if (t.x == INF) return t;

    if (ptOnSeg(t, seg1) && ptOnSeg(t, seg2))
        return t;
    else
        return {INF, INF};
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first.x >> a[i].first.y >> a[i].second.x >> a[i].second.y;

    map<Pt, set<int> > inters;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int dx = abs(a[i].first.x - a[i].second.x);
        int dy = abs(a[i].first.y - a[i].second.y);
        int g = __gcd(dx, dy);
        ans += (g + 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto t = interSegs(a[i], a[j]);
            if (t.x != INF) {
                inters[t].insert(i);
                inters[t].insert(j);
                //cout << i << " " << j << " " << t.x << " " << t.y << endl;
            }
        }
    }

    for (auto& x: inters)
        ans -= ((int)x.second.size() - 1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}