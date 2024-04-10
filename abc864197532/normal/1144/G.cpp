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
const int mod = 998244353, N = 60, logN = 18, K = 1 << 9, G = 3;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n);
    vv <int> st(n, logN, 0);
    vector <int> pre1(n), pre2(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            pre1[i] = pre1[i - 1] + (a[i - 1] < a[i]);
            pre2[i] = pre2[i - 1] + (a[i - 1] > a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        st[i][0] = i;
    }
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            if (a[st[i][j - 1]] < a[st[i + (1 << j - 1)][j - 1]]) {
                st[i][j] = st[i][j - 1];
            } else {
                st[i][j] = st[i + (1 << j - 1)][j - 1];
            }
        }
    }
    auto queryMnPos = [&](int l, int r) {
        int g = __lg(r - l);
        if (a[st[l][g]] < a[st[r - (1 << g)][g]]) {
            return st[l][g];
        }
        return st[r - (1 << g)][g];
    };
    auto increasing = [&](int l, int r) {
        if (r - l <= 1)
            return true;
        return pre1[r - 1] - pre1[l] == r - l - 1;
    };
    auto decreasing = [&](int l, int r) {
        if (r - l <= 1)
            return true;
        return pre2[r - 1] - pre2[l] == r - l - 1;
    };
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <int> ans(n, -1);
    function<bool(int, int, int, int, int, int)> solve = [&](int l, int r, int de_l, int de_r, int in_l, int in_r) {
        if (l == r)
            return true;
        if (r - l == 1) {
            if (de_l > a[l] && a[l] > de_r) {
                ans[l] = 1;
                return true;
            }
            if (in_l < a[l] && a[l] < in_r) {
                ans[l] = 0;
                return true;
            }
            return false;
        }
        int p = queryMnPos(l, r);
        if (l == p) {
            // de
            if (increasing(l + 1, r) && in_l < a[l + 1] && a[r - 1] < in_r && de_l > a[l] && a[l] > de_r) {
                ans[p] = 1;
                for (int i = p + 1; i < r; ++i) 
                    ans[i] = 0;
                return true;
            } 
            // in
            if (in_l < a[p] && a[p] < in_r) {
                ans[p] = 0;
                return solve(l + 1, r, de_l, de_r, a[p], in_r);
            }
            return false;
        }
        if (r == p + 1) {
            // in
            if (decreasing(l, r - 1) && de_l > a[l] && a[r - 2] > de_r && in_l < a[r - 1] && a[r - 1] < in_r) {
                ans[p] = 0;
                for (int i = l; i < p; ++i)
                    ans[i] = 1;
                return true;
            }
            // de
            if (de_l > a[p] && a[p] > de_r) {
                ans[p] = 1;
                return solve(l, p, de_l, a[p], in_l, in_r);
            }
            return false;
        }
        bool lok = decreasing(l, p) && de_l > a[l] && a[p - 1] > de_r && in_l < a[p] && a[p] < in_r;
        bool rok = increasing(p + 1, r) && in_l < a[p + 1] && a[r - 1] < in_r && de_l > a[p] && a[p] > de_r;
        if (lok && rok) {
            for (int i = l; i < p; ++i)
                ans[i] = 1;
            for (int i = p; i < r; ++i)
                ans[i] = 0;
            return true;
        } else if (lok) {
            for (int i = l; i < p; ++i)
                ans[i] = 1;
            ans[p] = 0;
            return solve(p + 1, r, a[p - 1], de_r, a[p], in_r);
        } else if (rok) {
            ans[p] = 1;
            for (int i = p + 1; i < r; ++i)
                ans[i] = 0;
            return solve(l, p, de_l, a[p], in_l, a[p + 1]);
        } 
        return false;
    };
    if (solve(0, n, 200001, -1, -1, 200001)) {
        cout << "YES\n";
        printv(all(ans));
    } else {
        cout << "NO\n";
    }
}