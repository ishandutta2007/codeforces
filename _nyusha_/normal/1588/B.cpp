#include<bits/stdc++.h>

using namespace std;

#define int long long
int a[50], n, cnt;
map < pair < int, int >, int > f;

inline int ok(int x) {
    int lef = 0, righ = 1000000001;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (mid * (mid - 1) / 2 <= x) lef = mid;
        else righ = mid;
    }
    if (lef * (lef - 1) / 2 == x) return lef;
    return -1;
}

int ask(int l, int r) {
    if (f.find({l, r}) != f.end()) return f[{l, r}];
    if (l > r) return 0;
    cnt++;
    if (cnt > 40) assert(1 == 0);
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    f[{l, r}] = x;
    return x;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        //for (int i = 1; i <= n; ++i) cin >> a[i];
        cnt = 0;
        f.clear();
        int l = 1, r = n, i = -1;
        int c = ask(1, n);
        while (r - l > 1) {
            int m = (r + l) / 2;
            int x = ask(1, m);
            if (x == 0) l = m;
            else if (x == c || ok(x) == -1) r = m;
            else {
                if (i != -1) {
                    if (x != (m - i) * (m - i - 1) / 2) r = m;
                    else l = m;
                } else {
                    int len = ok(x);
                    int tmp = ask(1, m - len);
                    if (tmp == 0) {
                        int cur = ask(1, m - len + 1);
                        if (cur == 0) i = m - len, l = m;
                        else i = m - len - 1, l = m - 1;
                    }
                    else r = m;
                }
            }
        }
        int j = r;
        int gg = ask(1, j - 1);
        cout << "! " << j - ok(gg) << " " << j << " " << j + ok(c - gg) - 1 << endl;
    }
    return 0;
}