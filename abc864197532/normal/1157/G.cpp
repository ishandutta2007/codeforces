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
    int n, m;
    cin >> n >> m;
    vv <int> a(n, m, 0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) 
        cin >> a[i][j];
    if (n == 1) {
        cout << "YES\n0\n";
        for (int i = 0; i < m; ++i) {
            cout << a[0][i];
        }
        cout << endl;
        return 0;
    }
    for (int row = 0; row < n; ++row) {
        vv <int> b = a;
        vector <int> ans_row(n, 0), ans_col(m, 0);
        for (int i = 0; i < row; ++i) {
            if (b[i][0]) {
                ans_row[i] = 1;
                for (int j = 0; j < m; ++j) {
                    b[i][j] ^= 1;
                }
            }
        }
        for (int i = row + 1; i < n; ++i) {
            if (!b[i][0]) {
                ans_row[i] = 1;
                for (int j = 0; j < m; ++j) {
                    b[i][j] ^= 1;
                }
            }
        }
        bool correct_sol = true;
        for (int j = 1; j < m; ++j) {
            bool is0 = true, is1 = true;
            for (int i = 0; i < row; ++i) {
                is0 &= b[i][j] == 0;
                is1 &= b[i][j] == 1;
            }
            for (int i = row + 1; i < n; ++i) {
                is0 &= b[i][j] == 1;
                is1 &= b[i][j] == 0;
            }
            if (!is0 && !is1) {
                correct_sol = false;
            }
            if (is1) {
                ans_col[j] = true;
                for (int i = 0; i < n; ++i) {
                    b[i][j] ^= 1;
                }
            }
        }
        if (!correct_sol)
            continue;
        if (b[row][0] == 1) {
            ans_row[row] = 1;
            for (int j = 0; j < m; ++j) {
                b[row][j] ^= 1;
            }
        }
        for (int j = 1; j < m; ++j) {
            if (b[row][j - 1] == 1 && b[row][j] == 0) {
                correct_sol = false;
            }
        }
        if (correct_sol) {
            cout << "YES\n";
            for (int i : ans_row)
                cout << i;
            cout << endl;
            for (int i : ans_col)
                cout << i;
            cout << endl;
            return 0;
        }
    }
    cout << "NO\n";
}