#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;

bool ask(int x, int y) {
    cout << 1 << " " << x + 1 << " " << y + 1 << endl;
    string s;
    cin >> s;
    return s == "TAK";
}

int find(int l, int r) {
    if (l == r) {
        return l;
    }
    if (l + 1 == r) {
        bool p = ask(l, r);
        return p ? l : r;
    }
    int y = (l + r + 2) >> 1;
    int x = y - 1;
    bool p = ask(x, y);
    if (p) {
        return find(l, x);
    }
    return find(y, r);
}

int main() {
#ifdef JLOCAL
//    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    int a1 = find(0, n - 1);
    int b1;
    if (a1 == 0) {
        b1 = find(1, n - 1);
    } else if (a1 == n - 1) {
        b1 = find(0, n - 2);
    } else {
        b1 = find(0, a1 - 1);
        if (!ask(b1, a1)) {
            b1 = find(a1 + 1, n - 1);
        }
    }

    cout << "2 " << a1 + 1 << " " << b1 + 1 << endl;

    return 0;
}