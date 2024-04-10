#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 6e6 + 10;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 6e6 + 1;

struct pt {
    int x, y;
    pt operator + (pt const a) const {
        return {x + a.x, y + a.y};
    }
    bool operator == (pt const a) const {
        return x == a.x && y == a.y;
    }
};

ll ptDist(pt a, pt b) {
    return (abs(a.x - b.x) + abs(a.y - b.y));
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    pt s, t;
    cin >> n >> s.x >> s.y >> t.x >> t.y;
    string st;
    cin >> st;
    if (s == t) {cout << 0; return 0;}
    fr(i, n) {
        pt p;
        if (st[i] == 'W') p = {-1, 0};
        if (st[i] == 'E') p = {1, 0};
        if (st[i] == 'N') p = {0, 1};
        if (st[i] == 'S') p = {0, -1};
        if (ptDist(s, t) > ptDist(s + p, t))
            s = s + p;
        if (ptDist(s, t) == 0) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}