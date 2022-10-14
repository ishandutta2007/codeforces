#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
const int mod = 1e9 + 7, N = 1 << 20, K = 250;

void solve() {
    int n;
    cin >> n;
    vector <int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    if (accumulate(all(vec), 0) - n >= 3) {
        cout << "-1\n";
        return;
    }
    // 3, 2 2, 2
    int p = find(all(vec), 3) - vec.begin();
    vector <vector <int>> ans;
    if (p != n) {
        {
            vector <int> v(n, 0);
            v[p] = 3;
            ans.pb(v);
            v[p] = 1;
            ans.pb(v);
            v[p] = 2;
            ans.pb(v);
        }
        for (int i = 0; i < n; ++i) if (i != p) {
            auto res = ans;
            int m = res.size();
            vector <int> v(n);
            v[i] = 1;
            ans.pb(v);
            for (auto i : res)
                ans.pb(i);
            for (int j = 0; j < m; j += 2)
                ans[j][i] = 1;
            for (int j = m + 2; j <= m * 2; j += 2)
                ans[j][i] = 1;
            swap(ans[m / 2], ans[m]);
        }
    } else {
        vector <int> tmp;
        for (int i = 0; i < n; ++i) if (vec[i] == 2) {
            tmp.pb(i);
        }
        if (tmp.empty()) {
            for (int i = 0; i < n; ++i) {
                auto res = ans;
                reverse(all(res));
                for (auto i : res)
                    ans.pb(i);
                for (int j = 1; j < ans.size(); j += 2)
                    ans[j][i] = 1;
                vector <int> v(n);
                v[i] = 1;
                ans.pb(v);
            }
        } else {
            if (tmp.size() == 1) {
                vector <int> v(n);
                v[tmp[0]] = 2;
                ans.pb(v);
                v[tmp[0]] = 1;
                ans.pb(v);
            } else {
                vector <int> v(n);
                vector <int> a = {1, 2, 0, 2, 0, 1, 2, 1};
                vector <int> b = {0, 2, 1, 1, 2, 1, 0, 2};
                reverse(all(a)), reverse(all(b));
                for (int i = 0; i < 8; ++i) {
                    v[tmp[0]] = a[i], v[tmp[1]] = b[i];
                    ans.pb(v);
                }
            }
            for (int i = 0; i < n; ++i) if (vec[i] == 1) {
                auto res = ans;
                reverse(all(res));
                for (auto i : res)
                    ans.pb(i);
                for (int j = 1; j < ans.size(); j += 2)
                    ans[j][i] = 1;
                vector <int> v(n);
                v[i] = 1;
                ans.pb(v);
            }
        }
    }
    for (auto i : ans) {
        for (int j = 0; j < n; ++j) {
            cout << i[j] << " \n"[j == n - 1];
        }
    }
    int m = ans.size();
    for (int i = 1; i < m; ++i) {
        int res = 0;
        for (int j = 0; j < n; ++j)
            res += min(ans[i][j], ans[i - 1][j]);
        assert(res == 1);
    }
    map <vector <int>, int> m1;
    for (int i = 0; i < m; ++i) {
        assert(!m1.count(ans[i]));
        m1[ans[i]] = 1;
        for (int j = 0; j < n; ++j)
            assert(ans[i][j] <= vec[j]);
    }
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}