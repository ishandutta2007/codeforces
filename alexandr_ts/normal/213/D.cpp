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
const int INF = 1e9;
const int N = 1e4 + 1;
const int LOG = 30;

struct Pt {
    ld x, y;
};

ld ptDist(Pt a, Pt b) {
    return hypot(a.x - b.x, a.y - b.y);
}

Pt rot(Pt a, ld alpha) {
    return {a.x * cos(alpha) - a.y * sin(alpha),
            a.x * sin(alpha) + a.y * cos(alpha)};
}

void solve() {
    int cntStars;
    cin >> cntStars;
    vector<Pt> star = {{0, sqrt(50 / (1 - cos(2 * PI / 5)))}};
    for (int i = 0; i < 4; i++) {
        star.pb(rot(star.back(), 2 * PI / 5));
    }
    swap(star[0], star[1]);

    ld step = ptDist(star[0], star[4]);

    cout << 4 * cntStars + 1 << endl;
    for (int i = 0; i < 5; i++)
        cout << fixed << setprecision(12) << star[i].x << " " << star[i].y << "\n";

    for (int starNum = 1; starNum < cntStars; starNum++) {
        for (int i = 1; i < 5; i++) {
            cout << fixed << setprecision(12) << star[i].x + step * starNum
                << " " << star[i].y << "\n";
        }
    }

    for (int i = 0; i < cntStars; i++) {
        vector<int> nums = {0, 2, 3, 4, 1};
        for (auto x: nums)
            cout << 4 * i + x + 1 << " ";
        cout << "\n";
    }

    vector<int> seq = {0};
    for (int i = 0; i < cntStars; i++) {
        seq.pb(3 + i * 4);
        seq.pb(1 + i * 4);
        seq.pb(2 + i * 4);
        seq.pb(4 + i * 4);
    }
    for (int i = cntStars * 4 - 4; i >= 0; i -= 4)
        seq.pb(i);
    assert(seq.size() == 5 * cntStars + 1);
    for (auto x: seq)
        cout << x + 1 << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}