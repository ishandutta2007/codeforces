#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

int ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    int r;
    cin >> r;
    return r;
}

int main(int argc, char** argv) {
#ifdef VSE
    // if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    int n;
    cin >> n;
    bool f = true;

    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        int x = ask(0, i, n - 1, n - 1);
        a[i] = x;
    }

    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1 && p1 == -1) {
            p1 = i - 1;
        } else if (a[i] % 2 == 0 && p1 != -1 && p2 == -1) {
            p2 = i - 1;
        }
    }

    if (p1 == -1) {
        f = false;
        for (int i = 1; i < n; i++) {
            int x = ask(i, 0, n - 1, n - 1);
            a[i] = x;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1 && p1 == -1) {
                p1 = i - 1;
            } else if (a[i] % 2 == 0 && p1 != -1 && p2 == -1) {
                p2 = i - 1;
            }
        }
    }

    if (p2 == -1) {
        p2 = n - 1;
    }

    int l = -1, r = n;

    while (l + 1 < r) {
        int m = (l + r) >> 1;
        int x = -1;
        if (f) {
            x = ask(0, p1, m, p1);
        } else {
            x = ask(p1, 0, p1, m);
        }
        if (x % 2 == 1) {
            r = m;
        } else {
            l = m;
        }
    }

    int a1 = r;

    l = -1, r = n;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        int x = -1;
        if (f) {
            x = ask(0, p2, m, p2);
        } else {
            x = ask(p2, 0, p2, m);
        }
        if (x % 2 == 1) {
            r = m;
        } else {
            l = m;
        }
    }

    int a2 = r;

    cout << "! ";

    if (f) {
        cout << a1 + 1 << " " << p1 + 1 << " " << a2 + 1 << " " << p2 + 1 << endl;
    } else {
        cout << p1 + 1 << " " << a1 + 1 << " " << p2 + 1 << " " << a2 + 1 << endl;
    }


    return 0;
}