/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
const int mod = 998244353, N = 300001, logN = 19, K = 1 << 9;

struct mat {
    int n;
    long long mod2;
    vector <vector <long long>> val;
    mat (int _n, int _mode = 0) : n(_n), mod2(1ll * mod * mod) {
        // mode 1 -> I, other -> O
        val.assign(n, vector<long long>(n, 0));
        if (_mode == 1) {
            for (int i = 0; i < n; ++i) val[i][i] = 1;
        }
    }
    mat (const mat& M) : n(M.n), mod2(1ll * mod * mod) {
        val.assign(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                val[i][j] = M.val[i][j];
            }
        }
    }
    mat (vector <vector <long long>> v) : n(v.size()), mod2(1ll * mod * mod), val(v) {}
    mat operator + (const mat& o) {
        mat ans(o);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans.val[i][j] += val[i][j];
                if (ans.val[i][j] >= mod) ans.val[i][j] -= mod;
            }
        }
        return ans;
    }
    mat operator * (const mat& o) {
        mat ans(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                for (int j = 0; j < n; ++j) {
                    ans.val[i][j] += val[i][k] * o.val[k][j];
                    if (ans.val[i][j] >= mod2) ans.val[i][j] -= mod2;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans.val[i][j] %= mod;
            }
        }
        return ans;
    }
    mat operator ^ (long long k) {
        mat ans(n, 1), a(*this);
        for (; k; k >>= 1, a = a * a) {
            if (k & 1) ans = ans * a;
        }
        return ans;
    }
};

int main() {
    owo;
    int n, m;
    cin >> n >> m;
    vector <string> pre;
    vector <int> fin;
    pre.pb(""), fin.pb(0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= s.length(); ++j) {
            if (find(all(pre), s.substr(0, j)) == pre.end()) {
                pre.pb(s.substr(0, j)), fin.pb(0);
            }
        }
        fin[find(all(pre), s) - pre.begin()] = 1;
    }
    vector <pii> dim;
    for (int i = 0; i < pre.size(); ++i) {
        for (int j = i; j < pre.size(); ++j) {
            string s = pre[i], t = pre[j];
            if (s.length() > t.length())
                swap(s, t);
            if (t.substr(t.length() - s.length()) == s) {
                dim.eb(i, j);
            }
        }
    }
    auto append = [&](int i, char c) {
        if (find(all(pre), pre[i] + c) != pre.end()) {
            return find(all(pre), pre[i] + c) - pre.begin();
        }
        return -1;
    };
    n = dim.size();
    vv <long long> a(n, n, 0);
    function<void(int, int, int)> add_ma = [&](int i, int l, int r) {
        if (find(all(dim), mp(l, r)) != dim.end())
            a[find(all(dim), mp(l, r)) - dim.begin()][i]++;
    };
    for (int i = 0; i < n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            int l, r;
            tie(l, r) = dim[i];
            l = append(l, c), r = append(r, c);
            if (l == -1 || r == -1)
                continue;
            if (l > r)
                swap(l, r);
            add_ma(i, l, r);
            if (fin[l])
                add_ma(i, 0, r);
            if (fin[r])
                add_ma(i, 0, l);
            if (fin[l] && fin[r])
                add_ma(i, 0, 0);
        }
    }
    mat M(a);
    M = M ^ m;
    cout << M.val[0][0] << endl;
}