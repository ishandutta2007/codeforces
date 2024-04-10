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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int d = 1; d <= n; ++d) {
        if (n % d) continue;
        for (int l = 0, r = d - 1; l < r; ++l, --r) {
            swap(s[l], s[r]);
        }
    }
    cout << s << '\n';
    return 0;
}