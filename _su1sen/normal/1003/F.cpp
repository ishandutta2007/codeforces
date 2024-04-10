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

template <typename T>
void z_algorithm(vector<T>& v, vector<size_t>& z) {
    size_t n = v.size();
    z.resize(n);
    z[0] = v.size();
    size_t i = 1, j = 0;
    while (i < n) {
        while (i + j < n && v[j] == v[i + j]) ++j;
        z[i] = j;
        if (j == 0) { ++i; continue; }
        int k = 1;
        while (i + k < n && k + z[k] < j) z[i + k] = z[k], ++k;
        i += k; j -= k;
    }
}

int main() {
    size_t n;
    cin >> n;
    map<string, size_t> mp;
    vector<size_t> l, a(n);
    size_t idx = 0;
    size_t ans = n - 1;
    rep(i, n) {
        string s;
        cin >> s;
        if (mp.count(s) == 0) {
            mp[s] = idx++;
            l.push_back(s.size());
        }
        a[i] = mp[s];
        ans += l[a[i]];
    }
    vector<size_t> s(n + 1, 0);
    rep(i, n) s[i + 1] = s[i] + l[a[i]];
    size_t dec_max = 0;
    vector<size_t> b, z;
    rep(l, n) {
        b.clear();
        repl(i, l, n) b.push_back(a[i]);
        z_algorithm(b, z);
        // z[i] = cp_len(a[l:], a[l+i:])
        repl(r, l + 1, n + 1) {
            size_t c = 1;
            size_t w = r - l;
            for (int x = r; x < n;) {
                if (z[x - l] >= w) {
                    x += w;
                    ++c;
                } else {
                    ++x;
                }
            }
            if (c >= 2) {
                int L = s[r] - s[l] + w - 1;
                dec_max = max(dec_max, c * (L - w));
            }
        }
    }
    cout << ans - dec_max << '\n';
    return 0;
}