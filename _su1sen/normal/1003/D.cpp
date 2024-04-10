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

constexpr int M = 32;
constexpr int inf = numeric_limits<int>::max();

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> cnt(M);
    rep(i, n) {
        int a;
        cin >> a;
        int p = 0;
        while (1 << p != a) ++p;
        ++cnt[p];
    }
    while (q --> 0) {
        int b;
        cin >> b;
        int c = 0;
        for (int i = M - 1; i >= 0; --i) {
            int x = min(b >> i, cnt[i]);
            c += x;
            b -= x << i;
        }
        if (b) cout << -1 << '\n';
        else cout << c << '\n';
    }
    return 0;
}