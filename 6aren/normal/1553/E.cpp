#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int p[N];
int cnt_comp;

int root(int x) {
    return (p[x] == x ? x : p[x] = root(p[x]));
}

void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    cnt_comp--;
    p[x] = y;
}

void solve() {  
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n), cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[i] = (i - a[i] + n) % n;
        cnt[b[i]]++;
    }

    vector<int> cand;
    for (int i = 0; i < n; i++) {
        if (cnt[i] >= n / 3) cand.push_back(i);
    }
    // cout << cnt[1] << endl;
    vector<int> res;
    for (int e : cand) {
        // cout << e << endl;
        for (int i = 0; i < n; i++) p[i] = i;
        cnt_comp = n;
        for (int i = 0; i < n; i++) {
            int foo = (a[i] + e) % n;
            merge(foo, i);
            // cout << foo << ' ' << i << endl;
        }
        if (cnt_comp + m >= n) res.push_back(e);
    }
    cout << res.size() << ' ';
    for (int e : res) cout << e << ' ';
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) solve();

    return 0;
}