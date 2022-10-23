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
        int d = n / 3;
        string s;
        cin >> s;
        int t_sum = 0;
        int lt = 0, m = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'T') {
                if (t_sum == d) {
                    ok &= --m >= 0;
                } else {
                    ++t_sum;
                    ++lt;
                }
            } else {
                ok &= --lt >= 0;
                ++m;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}