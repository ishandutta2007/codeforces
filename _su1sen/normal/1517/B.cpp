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
    int t;
    cin >> t;
    while (t --> 0) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> b(n, vector<int>(m));
        rep(i, n) read_vector(b[i]);
        auto cmp = [&](pair<int, int> p, pair<int, int> q) {
            auto [i1, j1] = p;
            auto [i2, j2] = q;
            return b[i1][j1] > b[i2][j2];
        };
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            decltype(cmp)
        > pq(cmp);
        rep(i, n) rep(j, m) pq.push({i, j});
        vector<pair<int, int>> asg(m);
        set<int> rest;
        rep(j, m) rest.insert(j);
        rep (k, m) {
            asg[k] = pq.top();
            pq.pop();
            rest.erase(asg[k].second);
        }
        vector<bool> used(m, false);
        for (auto &[i, j] : asg) {
            if (used[j]) {
                int k = *rest.begin();
                swap(b[i][j], b[i][k]);
                rest.erase(k);
                used[k] = true;
            } else used[j] = true;
        }
        for (auto &r : b) {
            print_vector(r);
        }
    }
    return 0;
}