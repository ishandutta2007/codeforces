#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int MAXN = 3e5 + 5;

int t[4 * MAXN];
int tadd[4 * MAXN];

void mod(int v, int vl, int vr, int l, int r, int d) {
    if (vl == l && vr == r) {
        tadd[v] += d;
        return;
    }
    int vm = (vl + vr) / 2;
    if (r <= vm) {
        mod(2 * v + 1, vl, vm, l, r, d);
    } else if (l >= vm) {
        mod(2 * v + 2, vm, vr, l, r, d);
    } else {
        mod(2 * v + 1, vl, vm, l, vm, d);
        mod(2 * v + 2, vm, vr, vm, r, d);
    }
    t[v] = max(t[2 * v + 1] + tadd[2 * v + 1], t[2 * v + 2] + tadd[2 * v + 2]);
}

bool not_ans(int x) {
    if (t[0] + tadd[0] > 0) {
        return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> p(n);
    for (auto &c : p) {
        cin >> c;
    }
    vector <int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }
    vector <int> q(n);
    for (auto &c : q) {
        cin >> c;
        c--;
    }
    int x = n;
    mod(0, 0, n, 0, pos[n] + 1, 1);
    for (int i = 0; i < n; i++) {
        while (not_ans(x)) {
            x--;
            mod(0, 0, n, 0, pos[x] + 1, 1);
        }
        cout << x << " ";
        mod(0, 0, n, 0, q[i] + 1, -1);
    }
    return 0;
}