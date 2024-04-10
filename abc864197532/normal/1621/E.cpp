#include <bits/stdc++.h>
using namespace std;
#define lli long long int
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
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200001, logN = 20, K = 48763;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <lli> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(rall(a));
        a.resize(m);
        reverse(all(a));
        vector <vector <int>> group(m);
        vector <pair <lli, int>> fac(m);
        vector <int> pre(m + 1);
        for (int i = 0, sz; i < m; ++i) {
            cin >> sz;
            group[i].resize(sz);
            for (int &j : group[i])
                cin >> j, fac[i].X += j;
            fac[i].Y = sz;
            pre[i + 1] = pre[i] + sz;
        }
        vector <pair <lli, int>> for_bin = fac;
        sort(all(for_bin), [&](pair <lli, int> i, pair <lli, int> j) {
            return i.X * j.Y < j.X * i.Y;
        });
        vector <int> p(m);
        iota(all(p), 0);
        sort(all(p), [&](int i, int j) {
            return fac[i].X * fac[j].Y < fac[j].X * fac[i].Y;
        });
        vector <int> pre_same(m + 1, 0), pre_dif_1(m + 1, 0), pre_dif_neg1(m + 1, 0);
        // dif = teacher pos - group pos
        // group index
        for (int i = 0; i < m; ++i) {
            pre_same[i + 1] = pre_same[i] + (fac[p[i]].X <= a[i] * fac[p[i]].Y);
        }
        for (int i = 0; i < m - 1; ++i) {
            pre_dif_1[i + 1] = pre_dif_1[i] + (fac[p[i]].X <= a[i + 1] * fac[p[i]].Y);
        }
        for (int i = 1; i < m; ++i) {
            pre_dif_neg1[i + 1] = pre_dif_neg1[i] + (fac[p[i]].X <= a[i - 1] * fac[p[i]].Y);
        }
        string ans(pre[m], '0');
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < group[p[i]].size(); ++j) {
                pair <lli, int> new_fac = mp(fac[p[i]].X - group[p[i]][j], fac[p[i]].Y - 1);
                int to = lower_bound(all(for_bin), new_fac, [&](pair <lli, int> i, pair <lli, int> j) {
                    return i.X * j.Y < j.X * i.Y;
                }) - for_bin.begin();
                int from = i;
                // from -> to
                if (from == to) {
                    bool is = true;
                    is &= pre_same[from] == from;
                    is &= pre_same[m] - pre_same[from + 1] == m - from - 1;
                    is &= new_fac.X <= a[from] * new_fac.Y;
                    if (is)
                        ans[pre[p[i]] + j] = '1';
                } else if (from < to) {
                    to--;
                    bool is = true;
                    is &= pre_same[from] == from;
                    is &= pre_same[m] - pre_same[to + 1] == m - to - 1;
                    is &= pre_dif_neg1[to + 1] - pre_dif_neg1[from + 1] == to - from;
                    is &= new_fac.X <= a[to] * new_fac.Y;
                    if (is)
                        ans[pre[p[i]] + j] = '1';
                } else {
                    bool is = true;
                    is &= pre_same[to] == to;
                    is &= pre_same[m] - pre_same[from + 1] == m - from - 1;
                    is &= pre_dif_1[from] - pre_dif_1[to] == from - to;
                    is &= new_fac.X <= a[to] * new_fac.Y;
                    if (is)
                        ans[pre[p[i]] + j] = '1';
                }
            }
        }
        cout << ans << endl;
    }
}