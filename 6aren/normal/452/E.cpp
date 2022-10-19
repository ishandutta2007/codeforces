#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

// Source: http://codeforces.com/contest/452/submission/7269543
// Efficient Suffix Array O(N*logN)

// String index from 0
// Usage:
// string s;  (s[i] > 0)
// SuffixArray sa(s);
// Now we can use sa.SA and sa.LCP
// sa.LCP[i] = max common prefix suffix of sa.SA[i-1] and sa.SA[i]
struct SuffixArray {
    string a;
    int N, m;
    vector<int> SA, LCP, x, y, w, c;

    SuffixArray(string _a, int m = 256) : a(" " + _a), N(a.length()), m(m),
            SA(N), LCP(N), x(N), y(N), w(max(m, N)), c(N) {
        a[0] = 0;
        DA();
        kasaiLCP();
        #define REF(X) { rotate(X.begin(), X.begin()+1, X.end()); X.pop_back(); }
        REF(SA); REF(LCP);
        a = a.substr(1, a.size());
        for(int i = 0; i < (int) SA.size(); ++i) --SA[i];
        #undef REF
    }

    inline bool cmp (const int a, const int b, const int l) { return (y[a] == y[b] && y[a + l] == y[b + l]); }

    void Sort() {
        for(int i = 0; i < m; ++i) w[i] = 0;
        for(int i = 0; i < N; ++i) ++w[x[y[i]]];
        for(int i = 0; i < m - 1; ++i) w[i + 1] += w[i];
        for(int i = N - 1; i >= 0; --i) SA[--w[x[y[i]]]] = y[i];
    }

    void DA() {
        for(int i = 0; i < N; ++i) x[i] = a[i], y[i] = i;
        Sort();
        for(int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
            for(p = 0, i = N - j; i < N; i++) y[p++] = i;
            for (int k = 0; k < N; ++k) if (SA[k] >= j) y[p++] = SA[k] - j;
            Sort();
            for(swap(x, y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)
                x[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
        }
    }

    void kasaiLCP() {
        for (int i = 0; i < N; i++) c[SA[i]] = i;
        for (int i = 0, j, k = 0; i < N; LCP[c[i++]] = k)
            if (c[i] > 0) for (k ? k-- : 0, j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++);
            else k = 0;
    }
};

string s[3];

int stringId(int id) {
    if (id >= 0 && id < s[0].size()) return 0;
    if (id > s[0].size() && id < s[0].size() + s[1].size() + 1) return 1;
    if (id > s[0].size() + s[1].size() + 1 && id < s[0].size() +s[1].size() + s[2].size() + 2) return 2;
    return -1;
}

const int N = 300005;
const int MOD = 1000000007;

int cnt[N][3];
int p[N];
vector<int> v[N];
int l;
int ans[N];

int root(int x) {
    return ((p[x] == x) ? x : p[x] = root(p[x]));
}

void merge(int u, int v, int &plus) {
    if ((u = root(u)) == (v = root(v))) return;
    long long temp = 0;
    temp -= 1LL * cnt[u][0] * cnt[u][1] * cnt[u][2] % MOD;
    temp -= 1LL * cnt[v][0] * cnt[v][1] * cnt[v][2] % MOD;
    p[v] = u;
    for (int i = 0; i < 3; i++) cnt[u][i] += cnt[v][i];
    temp += 1LL * cnt[u][0] * cnt[u][1] * cnt[u][2] % MOD;
    temp = (temp % MOD + MOD) % MOD;
    plus += temp;
    plus %= MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> s[0] >> s[1] >> s[2];
    l = min(s[0].size(), min(s[1].size(), s[2].size()));
    string t = s[0] + "$" + s[1] + "&" + s[2];
    SuffixArray sa = SuffixArray(t);
    int n = t.size();
    for (int i = 0; i < n; i++) {
        p[i] = i;
        int foo = stringId(sa.SA[i]);
        if (foo != -1) cnt[i][foo] = 1;
        v[sa.LCP[i]].pb(i);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << sa.SA[i] << ' ';
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << sa.LCP[i] << ' ';
    // }
    // cout << endl;
    int plus = 0;
    for (int i = n; i >= 1; i--) {
        for (int e : v[i]) {
            merge(e - 1, e, plus);
        }
        ans[i] = (ans[i + 1] + plus) % MOD;
        plus = 0;
    }
    for (int i = 1; i <= l; i++) cout << ans[i] << ' ';
    return 0;
}