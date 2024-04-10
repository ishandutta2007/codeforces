#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 2e5 + 7, B = 550;

vector <int> buildZ(string s) {
  int n = s.length();
  vector <int> Z(n);
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    Z[i] = max(min(Z[i - l], r - i), 0);
    while (i + Z[i] < s.size() && s[Z[i]] == s[i + Z[i]]) {
      l = i, r = i + Z[i], Z[i]++;
    }
  }
  return Z;
}

int sa[N], tmp[2][N], c[N], rk[N], lcp[N];
void buildSA(string s) {
  int *x = tmp[0], *y = tmp[1], m = 256, n = s.length();
  for (int i = 0; i < m; ++i) c[i] = 0;
  for (int i = 0; i < n; ++i) c[x[i] = s[i]]++;
  for (int i = 1; i < m; ++i) c[i] += c[i - 1];
  for (int i = n - 1; ~i; --i) sa[--c[x[i]]] = i;
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < m; ++i) c[i] = 0;
    for (int i = 0; i < n; ++i) c[x[i]]++;
    for (int i = 1; i < m; ++i) c[i] += c[i - 1];
    int p = 0;
    for (int i = n - k; i < n; ++i) y[p++] = i;
    for (int i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] - k;
    for (int i = n - 1; ~i; --i) sa[--c[x[y[i]]]] = y[i];
    y[sa[0]] = p = 0;
    for (int i = 1; i < n; ++i) {
      int a = sa[i], b = sa[i - 1];
      if (!(x[a] == x[b] && a + k < n && b + k < n && x[a + k] == x[b + k])) p++;
      y[sa[i]] = p;
    }
    if (n == p + 1) break;
    swap(x, y), m = p + 1;
  }
}

void buildLCP(string s) {
  // lcp[i] = LCP(sa[i - 1], sa[i])
  // lcp(i, j) = min(lcp[rk[i] + 1], lcp[rk[i] + 2], ..., lcp[rk[j]])
  int n = s.length(), val = 0;
  for (int i = 0; i < n; ++i) rk[sa[i]] = i;
  for (int i = 0; i < n; ++i) {
    if (!rk[i]) lcp[rk[i]] = 0;
    else {
      if (val) val--;
      int p = sa[rk[i] - 1];
      while (val + i < n && val + p < n && s[val + i] == s[val + p]) val++;
      lcp[rk[i]] = val;
    }
  }
}

template <typename T>
struct SparseTableMin {
    // 0-indexed, [l, r)
    vector <vector <T>> table;
    SparseTableMin () = default;
    SparseTableMin (vector <T> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        table.resize(n, vector <T> (m, 0));
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        if (l >= r)
            return 1 << 30;
        int g = __lg(r - l);
        return min(table[l][g], table[r - (1 << g)][g]);
    }
};

int to_left[N], to_right[N];
vector <array <int, 3>> rep; // l, r, len. [l, l + len), [l + 1, l + 1 + len), ..., [r, r + len)

void findRep(string &s, int l, int r) {
    if (r - l == 1)
        return;
    int m = l + r >> 1;
    findRep(s, l, m), findRep(s, m, r);
    // l1 l2 l1 | l2
    string sl = s.substr(l, m - l), sr = s.substr(m, r - m);
    {
        vector <int> Z = buildZ(sr + "#" + sl);
        for (int i = l; i < m; ++i)
            to_right[i] = Z[r - m + 1 + i - l];
    }
    {
        reverse(all(sl));
        vector <int> Z = buildZ(sl);
        for (int i = l; i < m; ++i)
            to_left[i] = Z[m - i - 1];
        reverse(all(sl));
    }
    for (int i = l; i + 1 < m; ++i) {
        int k1 = to_left[i], k2 = to_right[i + 1], len = m - i - 1;
        if (k1 < 1 || k2 < 1 || len < 2)
            continue;
        // l1 + l2 = len
        // l1 = m - i - 1 - l2
        // len - k2 <= l1 <= len - 1
        // 1 <= l1 <= k1
        int tl = max(1, len - k2), tr = min(len - 1, k1);
        if (tl <= tr) {
            rep.pb({i + 1 - tr, i + 1 - tl, len});
        }
    }
    {
        vector <int> Z = buildZ(sr);
        for (int i = m; i < r; ++i)
            to_right[i] = Z[i - m];
    }
    {
        reverse(all(sl)), reverse(all(sr));
        vector <int> Z = buildZ(sl + "#" + sr);
        for (int i = m; i < r; ++i)
            to_left[i] = Z[m - l + 1 + r - i - 1];
        reverse(all(sl)), reverse(all(sr));
    }
    for (int i = m; i + 1 < r; ++i) {
        int k1 = to_left[i], k2 = to_right[i + 1], len = i - m + 1;
        if (k1 < 1 || k2 < 1 || len < 2)
            continue;
        // l1 + l2 = len
        // l1 = len - l2
        // len - k2 <= l1 <= len - 1
        // 1 <= l1 <= k1
        int tl = max(len - k2, 1), tr = min(len - 1, k1);
        // i + tl, i + tr
        if (tl <= tr) {
            rep.pb({i + 1 - len - tr, i + 1 - len - tl, len});
        }
    }
    vector <int> Z = buildZ(sr + "#" + sl);
    for (int i = l; i < m; ++i) {
        if (Z[r - m + 1 + i - l] >= m - i) {
            rep.pb({i, i, m - i});
        }
    }
}

pair <vector <int>, vector <int>> buildRep(string s) {
    int n = s.length();
    vector <int> tol(n, -1), tor(n, -1);
    findRep(s, 0, n);
    vector <vector <int>> event1(n + 1), event2(n + 1);
    multiset <int> S1, S2;
    for (auto i : rep) {
        event1[i[0]].pb(i[2]), event1[i[1] + 1].pb(-i[2]);
        event2[i[0] + i[2] + i[2] - 1].pb(i[2]), event2[i[1] + i[2] + i[2]].pb(-i[2]);
    }
    for (int i = 0; i < n; ++i) {
        for (int x : event1[i]) {
            if (x > 0)
                S1.insert(x);
            else
                S1.erase(S1.lower_bound(-x));
        }
        for (int x : event2[i]) {
            if (x > 0)
                S2.insert(x);
            else
                S2.erase(S2.lower_bound(-x));
        }
        if (!S1.empty())
            tol[i] = *S1.begin();
        if (!S2.empty())
            tor[i] = *S2.begin();
    }
    return make_pair(tol, tor);
}

void solve() {
    int n, q; string s;
    cin >> n >> s >> q;
    vector <int> rep_l, rep_r;
    tie(rep_l, rep_r) = buildRep(s);
    vv <int> pre(n + 1, 26);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j)
            pre[i][j] = pre[i - 1][j] + (s[i - 1] - 'a' == j);
    }
    buildSA(s), buildLCP(s);
    vector <int> tmp(n);
    for (int i = 1; i < n; ++i)
        tmp[i] = lcp[i];
    vector <int> rep_len(n);
    for (int i = 0; i < n; ++i) {
        if (rep_l[i] == -1)
            rep_len[i] = n + 5;
        else
            rep_len[i] = i + rep_l[i] * 2;
    }
    SparseTableMin <int> STlcp(tmp), STrep(rep_len);
    auto query_lcp = [&](int a, int b) {
        a = rk[a] + 1, b = rk[b] + 1;
        if (a > b) swap(a, b);
        return STlcp.query(a, b);
    };
    auto query_no = [&](int l, int r) {
        bool ok = true;
        for (int i = 0; i < 26; ++i) if (pre[r][i] - pre[l][i] > 1)
            ok = false;
        return ok;
    };
    auto query_1 = [&](int l, int r) {
        int len = r - l;
        for (int i = 2; i * i <= len; ++i) if (len % i == 0) {
            int gap = (r - l) / i;
            if (query_lcp(l, l + gap) >= r - l - gap)
                return true;
            while (len % i == 0)
                len /= i;
        }
        if (len > 1) {
            int gap = (r - l) / len;
            if (query_lcp(l, l + gap) >= r - l - gap)
                return true;
        }
        return false;
    };
    auto query_2 = [&](int l, int r) {
        if (rep_l[l] != -1 && rep_l[l] + rep_l[l] <= r - l)
            return true;
        if (rep_r[r - 1] != -1 && rep_r[r - 1] + rep_r[r - 1] <= r - l)
            return true;
        for (int i = 1; i < B; ++i) {
            int m1 = l + i, m2 = r - i;
            if (m1 <= m2 && query_lcp(l, r - i) >= i)
                return true;
        }
        int p = rk[l], cur = 1 << 30;
        for (int i = 1; i < B; ++i) {
            if (p + i >= n)
                break;
            cur = min(cur, lcp[p + i]);
            if (l <= sa[p + i] && sa[p + i] < r && cur >= r - sa[p + i])
                return true;
        }
        p = rk[l], cur = 1 << 30;
        for (int i = 1; i < B; ++i) {
            if (p - i < 0)
                break;
            cur = min(cur, lcp[p - i + 1]);
            if (l <= sa[p - i] && sa[p - i] < r && cur >= r - sa[p - i])
                return true;
        }
        return false;
    };
    auto query_3 = [&](int l, int r) {
        int c = s[r - 1] - 'a';
        if (pre[r - 1][c] - pre[l][c] > 0)
            return true;
        c = s[l] - 'a';
        if (pre[r][c] - pre[l + 1][c] > 0)
            return true;
        if (STrep.query(l, r) <= r)
            return true;
        return false;
    };
    while (q--) {
        int l, r; cin >> l >> r, --l;
        if (query_no(l, r)) {
            cout << "-1\n";
        } else if (query_1(l, r)) {
            cout << "1\n";
        } else if (query_2(l, r)) {
            cout << "2\n";
        } else if (query_3(l, r)) {
            cout << "3\n";
        } else {
            cout << "4\n";
        }
    }
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}