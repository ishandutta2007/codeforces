#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 1;

struct segment{
    int l, r, ind;
    segment(){}
    segment(int _l, int _r, int _ind) {
        l = _l;
        r = _r;
        ind = _ind;
    }
    bool operator< (const segment &s) {
        return l < s.l;
    }
};

vector<int> t;

void mod(int v, int vl, int vr, int ind, int val) {
    if (vr - vl == 1) {
        t[v] = val;
        return;
    }
    int vm = (vl + vr) / 2;
    if (ind < vm) {
        mod(2 * v + 1, vl, vm, ind, val);
    } else {
        mod(2 * v + 2, vm, vr, ind, val);
    }
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

int get(int v, int vl, int vr, int l, int r) {
    if (vl == l && vr == r) {
        return t[v];
    }
    int vm = (vl + vr) / 2;
    if (r <= vm) {
        return get(2 * v + 1, vl, vm, l, r);
    } else if (l >= vm) {
        return get(2 * v + 2, vm, vr, l, r);
    } else {
        return min(get(2 * v + 1, vl, vm, l, vm), get(2 * v + 2, vm, vr, vm, r));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<segment> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        l.pb(a[i], b[i], i);
    }
    sort(all(l));
    set<pair<int, int>> s;
    vector<int> ans(n);
    vector<int> pos(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        s.insert({l[i].r, l[i].ind});
        while ((j < n) && (i == n - 1 || l[i + 1].l > j)) {
            ans[s.begin()->se] = j;
            pos[j] = s.begin()->se;
            s.erase(s.begin());
            j++;
        }
    }
    t.assign(4 * n, INF);
    for (int i = n - 1; i >= 0; i--) {
        int mn = get(0, 0, n, 0, i + 1);
        if (mn <= b[pos[i]]) {
            vector<int> ans1 = ans;
            swap(ans1[pos[i]], ans1[pos[mn]]);
            cout << "NO" << "\n";
            for (auto &c : ans) {
                cout << c + 1 << " ";
            }
            cout << "\n";
            for (auto &c : ans1) {
                cout << c + 1 << " ";
            }
            return 0;
        }
        mod(0, 0, n, a[pos[i]], i);
    }
    cout << "YES" << "\n";
    for (auto &c : ans) {
        cout << c + 1 << " ";
    }
    return 0;
}