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
        int n;
        cin >> n;
        string s, t, u;
        cin >> s >> t >> u;
        int s0 = 0, t0 = 0, u0 = 0;
        for (char c : s) s0 += c == '0';
        for (char c : t) t0 += c == '0';
        for (char c : u) u0 += c == '0';
        int cnt = (s0 >= n) + (t0 >= n) + (u0 >= n);
        string x, y;
        char p, q;
        if (cnt < 2) {
            p = '1', q = '0';
            if (s0 >= n) {
                x = t; y = u;
            } else if (t0 >= n) {
                x = s; y = u;
            } else {
                x = s; y = t;
            }
        } else {
            p = '0', q = '1';
            if (s0 < n) {
                x = t; y = u;
            } else if (t0 < n) {
                x = s; y = u;
            } else {
                x = s; y = t;
            }
        }
        int lx = 0, ly = 0;
        for (int i = 0; i < 3 * n; ++i) {
            if (lx < 2 * n and x[lx] == q) {
                cout << q;
                ++lx;
                if (ly < 2 * n and y[ly] == q) {
                    ++ly;
                }
            } else if (ly < 2 * n and y[ly] == q) {
                cout << q;
                ++ly;
            } else {
                cout << p;
                ++lx; ++ly;
            }
        }
        cout << '\n';
    }
    return 0;
}