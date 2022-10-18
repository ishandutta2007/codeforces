#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int query(int i, int j, int k) {
    if (i == j || j == k || i == k)
        assert(0);
    cout << "? " << i << " " << j << " " << k << endl;
    int rt;
    cin >> rt;
    if (rt == -1)
        exit(0);
    return rt;
}

void report(int i, int j) {
    cout << "! " << i << " " << j << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, nw, cur, flag = 1;
        cin >> n;
        cur = 3;
        nw = query(1, 2, cur);
        for (int i = 4; i <= n; ++i) {
            int val = query(1, 2, i);
            if (val != nw)
                flag = 0;
            if (val > nw)
                nw = val, cur = i;
        }
        if (flag) {
            int a = 1, b = 2;
            for (int i = 3; i < n; ++i) {
                int val = query(1, i, i + 1);
                if (val > nw)
                    val = nw, a = i, b = i + 1;
            }
            report(a, b);
            continue;
        }
        int a = cur;
        cur = 2, flag = 1;
        nw = query(a, 1, cur);
        for (int i = 3; i <= n; ++i) {
            if (i == a) continue;
            int val = query(a, 1, i);
            if (val != nw)
                flag = 0;
            if (val > nw)
                nw = val, cur = i;
        }
        if (flag) {
            report(a, 1);
            continue;
        }
        report(a, cur);
    }
}