#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool ask1(int x, int y) {
    cout << 1 << ' ' << x << ' ' << y << endl;
    int res;
    cin >> res;
    return res;
}

bool ask2(int x, vector<int> a) {
    cout << 2 << ' ' << x << ' ' << a.size() << ' ';
    for (int e : a) cout << e << ' ';
    cout << endl;
    int res;
    cin >> res;
    return res;
}

vector<int> quicksort(const vector<int> &a) {
    if (a.size() < 2) return a;
    int pivot = rng() % a.size();
    vector<int> l, r;
    for (int i = 0; i < a.size(); i++) {
        if (i == pivot) continue;
        if (ask1(a[i], a[pivot])) l.push_back(a[i]);
        else r.push_back(a[i]);
    }
    // cout << l.size() << ' ' << r.size() << endl;
    l = quicksort(l);
    r = quicksort(r);
    // cout << l.size() << ' ' << r.size() << endl;
    vector<int> res;
    for (int e : l) res.push_back(e);
    res.push_back(a[pivot]);
    for (int e : r) res.push_back(e);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = i;
        a = quicksort(a);
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                res[a[i]][a[j]] = 1;
            }
        }
        int cur = n - 2; 
        vector<int> l(n);
        for (int i = n - 1; i > 0; i--) {
            if (cur == i) cur--;
            while (true) {
                if (cur == -1) {
                    l[i] = 0;
                    break;
                }
                vector<int> tmp;
                for (int j = 0; j <= cur; j++) {
                    tmp.push_back(a[j]);
                }
                if (ask2(a[i], tmp)) {
                    cur--;
                } else {
                    l[i] =  cur + 1;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = l[i]; j <= i; j++) {
                l[i] = min(l[i], l[j]);
            }
            for (int j = l[i]; j <= i; j++) {
                res[a[i]][a[j]] = 1;
            }
        }
        cout << 3 << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j];
            }
            cout << endl;
        }
        int rr;
        cin >> rr;
    }

    return 0;
}