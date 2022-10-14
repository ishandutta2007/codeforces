#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

struct Node{
    int minl = INF, maxr = -INF, ok = 1;
};

vector<Node> t;

void mod(int v, int vl, int vr, int pos, int d, bool is_left) {
    if (vr - vl == 1) {
        if (is_left) t[v].minl = d;
        else t[v].maxr = d;
        t[v].ok = (t[v].minl > t[v].maxr);
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos < vm) mod(2 * v + 1, vl, vm, pos, d, is_left);
    else mod(2 * v + 2, vm, vr, pos, d, is_left);
    t[v].maxr = max(t[2 * v + 1].maxr, t[2 * v + 2].maxr);
    t[v].minl = min(t[2 * v + 1].minl, t[2 * v + 2].minl);
    t[v].ok = (t[2 * v + 1].ok & t[2 * v + 2].ok & (t[2 * v + 1].minl > t[2 * v + 2].maxr));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    t.resize(4 * (n + 1));
    map<int, map<int, int>> ma;
    vector<set<int>> left(n + 1), right(n + 1);
    while (q--) {
        int x, y;
        cin >> x >> y;
        bool is_left = (x % 2 == 1);
        if (is_left) {
            if (ma[x][y]) left[(x + 1) / 2].erase((y + 1) / 2);
            else left[(x + 1) / 2].insert((y + 1) / 2);
            ma[x][y] ^= 1;
        } else {
            if (ma[x][y]) right[(x + 1) / 2].erase((y + 1) / 2);
            else right[(x + 1) / 2].insert((y + 1) / 2);
            ma[x][y] ^= 1;
        }
        if (is_left) {
            int pos = INF;
            if (left[(x + 1) / 2].size()) pos = *left[(x + 1) / 2].begin();
            mod(0, 0, n + 1, (x + 1) / 2, pos, 1);
        } else {
            int pos = -INF;
            if (right[(x + 1) / 2].size()) pos = *right[(x + 1) / 2].rbegin();
            mod(0, 0, n + 1, (x + 1) / 2, pos, 0);
        }
        cout << (t[0].ok ? "YES\n" : "NO\n");
    }
    return 0;
}