#include <bits/stdc++.h>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) (iterable).begin(), (iterable).end()

constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template <typename T>
void print_vector(const vector<T>& vec, const string sep = " ", const string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}

template <typename T>
void read_vector(vector<T>& a, int begin_index, int length) {
    if (a.size() < begin_index + length) a.resize(begin_index + length);
    while (length --> 0) cin >> a[begin_index++];
}
template <typename T>
void read_vector(vector<T>& a) { read_vector(a, 0, a.size()); }

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    int n = a + b;
    vector<char> ans(a + b);
    if (a > b) {
        --a;
        ans[0] = '0';
        int c = 0;
        for (int i = 1; i < n; ++i) {
            if (i & 1) {
                ans[i] = '1';
                --b;
            } else {
                ans[i] = '0';
                --a;
            }
            if (++c == x) {
                for (int j = 0; j <= i; ++j) {
                    cout << ans[j];
                    if (ans[j] == '0') {
                        while (a --> 0) cout << '0';
                    } else {
                        while (b --> 0) cout << '1';
                    }
                }
                break;
            }
        }
    } else {
        --b;
        ans[0] = '1';
        int c = 0;
        for (int i = 1; i < n; ++i) {
            if (i & 1) {
                ans[i] = '0';
                --a;
            } else {
                ans[i] = '1';
                --b;
            }
            if (++c == x) {
                for (int j = 0; j <= i; ++j) {
                    cout << ans[j];
                    if (ans[j] == '0') {
                        while (a --> 0) cout << '0';
                    } else {
                        while (b --> 0) cout << '1';
                    }
                }
                break;
            }
        }
    }
    cout << '\n';
    return 0;
}