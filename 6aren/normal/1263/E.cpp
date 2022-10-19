#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 1000005;

int n, lazy[4 * N], it[2][4 * N];

void lazy_down(int k) {
    if (lazy[k] == 0) return;
    int val = lazy[k];
    it[0][2 * k] += val;
    it[1][2 * k] += val;
    it[0][2 * k + 1] += val;
    it[1][2 * k + 1] += val;
    lazy[2 * k] += val;
    lazy[2 * k + 1] += val;
    lazy[k] = 0;
    return; 
}

void update(int k, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        lazy[k] += val;
        it[0][k] += val;
        it[1][k] += val;
        return;
    }
    lazy_down(k);
    int mid = (l + r) / 2;
    update(2 * k, l, mid, u, v, val);
    update(2 * k + 1, mid + 1, r, u, v, val);
    it[0][k] = min(it[0][2 * k], it[0][2 * k + 1]);
    it[1][k] = max(it[1][2 * k], it[1][2 * k + 1]);
}

int getMin(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return 1e9;
    if (l >= u && r <= v) return it[0][k];
    lazy_down(k);
    int mid = (l + r) / 2;
    int g1 = getMin(2 * k, l, mid, u, v);
    int g2 = getMin(2 * k + 1, mid + 1, r, u, v);
    return min(g1, g2);
}

int getMax(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return -1e9;
    if (l >= u && r <= v) return it[1][k];
    lazy_down(k);
    int mid = (l + r) / 2;
    int g1 = getMax(2 * k, l, mid, u, v);
    int g2 = getMax(2 * k + 1, mid + 1, r, u, v);
    return max(g1, g2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int cur = 1;
    string t;
    for (int i = 0; i < n + 10; i++) {
        t += " ";
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'L') {
            cur = max(cur - 1, 1);
        } else if (s[i] == 'R') {
            cur = cur + 1;
        } else if (s[i] == '(') {
            if (t[cur] == '(') {
                update(1, 1, n + 2, cur, n + 2, -1);
            } else if(t[cur] == ')') {
                update(1, 1, n + 2, cur, n + 2, 1);
            }
            update(1, 1, n + 2, cur, n + 2, 1);
            t[cur] = '(';
        } else if (s[i] == ')') {
            if (t[cur] == '(') {
                update(1, 1, n + 2, cur, n + 2, -1);
            } else if(t[cur] == ')') {
                update(1, 1, n + 2, cur, n + 2, 1);
            }
            update(1, 1, n + 2, cur, n + 2, -1);
            t[cur] = ')';
        } else {
            if (t[cur] == '(') {
                update(1, 1, n + 2, cur, n + 2, -1);
            } else if(t[cur] == ')') {
                update(1, 1, n + 2, cur, n + 2, 1);
            }
            t[cur] = s[i];
        }
        int u = getMax(1, 1, n + 2, n + 2, n + 2);
        int v = getMin(1, 1, n + 2, 1, n + 2);
        int t = getMax(1, 1, n + 2, 1, n + 2);
        //if (i == 7) cout << u << ' ' << v << ' ' << t << endl;
        if (u == 0 && v >= 0) {
            cout << t << ' ';
        } else cout << -1 << ' ';
    }
    return 0;
}