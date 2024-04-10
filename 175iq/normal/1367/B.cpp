#include <bits/stdc++.h>

using namespace std;

template <class ...As> auto &read(As &...as) { return (cin >> ... >> as); }
template <class T> auto &operator>>(istream &is, vector<T> &xs) {
    for (auto &x : xs) is >> x;
    return is;
}

#define READ(...)             __VA_ARGS__; read(__VA_ARGS__)
#define READ_CTOR(name, ...)  name(__VA_ARGS__); cin >> name

auto main() -> int {
    int READ(t);
    while (t--) {
        int READ(n);
        vector<int> READ_CTOR(xs, n);

        int odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == xs[i] % 2) continue;
            (i % 2 ? odd : even) += 1;
        }

        cout << (odd == even ? odd : -1) << '\n';
    }
}