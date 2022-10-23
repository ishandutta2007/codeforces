#include <bits/stdc++.h>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) iterable.begin(), iterable.end()

template <typename T>
void print_vector(vector<T>& vec, string sep = " ", string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n, w;
        cin >> n >> w;
        vector<int> c(32);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int p = 0;
            while (1 << p < x) ++p;
            ++c[p];
        }
        int ans = 0;
        int rest = n;
        while (rest > 0) {
            int rw = w;
            for (int p = 31; p >= 0; --p) {
                while (c[p] and 1 << p <= rw) {
                    --c[p];
                    --rest;
                    rw -= 1 << p;
                }
            }
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}