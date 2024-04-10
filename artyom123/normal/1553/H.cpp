#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

struct Node {
    int mn = INF, mx = -INF, ans = INF;
};

vector<vector<Node>> t;

void add(int x, int k) {
    int v = 0;
    for (int i = k - 1; i >= 0; i--) {
        if (x & (1 << i)) v = 2 * v + 2;
        else v = 2 * v + 1;
    }
    t[v][0].mn = t[v][0].mx = 0;
}

void build(int v, int h) {
    if (h == 0) return;
    build(2 * v + 1, h - 1);
    build(2 * v + 2, h - 1);
    t[v].resize(1 << h);
    for (int x = 0; x < (1 << h); x++) {
        if (x & (1 << (h - 1))) {
            t[v][x].ans = min(t[2 * v + 1][x ^ (1 << (h - 1))].ans, t[2 * v + 2][x ^ (1 << (h - 1))].ans);
            if (t[2 * v + 1][x ^ (1 << (h - 1))].mn != INF && t[2 * v + 2][x ^ (1 << (h - 1))].mn != INF) t[v][x].ans = min(t[v][x].ans, t[2 * v + 1][x ^ (1 << (h - 1))].mn + (1 << (h - 1)) - t[2 * v + 2][x ^ (1 << (h - 1))].mx);
            if (t[2 * v + 2][x ^ (1 << (h - 1))].mn != INF) t[v][x].mn = t[2 * v + 2][x ^ (1 << (h - 1))].mn;
            else if (t[2 * v + 1][x ^ (1 << (h - 1))].mn != INF) t[v][x].mn = (1 << (h - 1)) + t[2 * v + 1][x ^ (1 << (h - 1))].mn;
            if (t[2 * v + 1][x ^ (1 << (h - 1))].mn != INF) t[v][x].mx = (1 << (h - 1)) + t[2 * v + 1][x ^ (1 << (h - 1))].mx;
            else if (t[2 * v + 2][x ^ (1 << (h - 1))].mn != INF) t[v][x].mx = t[2 * v + 2][x ^ (1 << (h - 1))].mx;
        } else {
            t[v][x].ans = min(t[2 * v + 1][x].ans, t[2 * v + 2][x].ans);
            if (t[2 * v + 1][x].mn != INF && t[2 * v + 2][x].mn != INF) t[v][x].ans = min(t[v][x].ans, t[2 * v + 2][x].mn + (1 << (h - 1)) - t[2 * v + 1][x].mx);
            if (t[2 * v + 1][x].mn != INF) t[v][x].mn = t[2 * v + 1][x].mn;
            else if (t[2 * v + 2][x].mn != INF) t[v][x].mn = (1 << (h - 1)) + t[2 * v + 2][x].mn;
            if (t[2 * v + 2][x].mn != INF) t[v][x].mx = (1 << (h - 1)) + t[2 * v + 2][x].mx;
            else if (t[2 * v + 1][x].mn != INF) t[v][x].mx = t[2 * v + 1][x].mx;
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    t.resize(1 << (k + 1), vector<Node>(1));
    for (auto &c : a) add(c, k);
    build(0, k);
    for (int x = 0; x < (1 << k); x++) cout << t[0][x].ans << " ";
    return 0;
}