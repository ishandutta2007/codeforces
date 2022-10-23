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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) {
        ++cnt[c - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] <= k) {
            k -= cnt[i];
        } else {
            char x = (char) ('a' + i);
            for (char c : s) {
                if (c > x) {
                    cout << c;
                } else if (x == c) {
                    if (--k < 0) cout << c;
                }
            }
            cout << '\n';
            return 0;
        }
    }
    return 0;
}