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
const int mod = 1e9 + 7, N = 100000, logN = 20, K = 48763;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vv <int> idx(n, n, -1);
        vector <int> w(m);
        vv <int> basis(m, m + 1, 0);
        vector <bool> basis_empty(m, true);
        bool fail = false;
        auto add = [&](vector <int> vec) {
            for (int i = 0; i < m; ++i) if (vec[i]) {
                if (basis_empty[i]) {
                    basis[i] = vec;
                    basis_empty[i] = false;
                    return;
                }
                while (vec[i] != 0) {
                    for (int j = 0; j <= m; ++j) {
                        vec[j] -= basis[i][j];
                        if (vec[j] < 0)
                            vec[j] += 3;
                    }
                }
            }
            if (vec[m] != 0)
                fail = true;
        };
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v >> w[i], --u, --v;
            if (w[i] == 3)
                w[i] = 0;
            idx[u][v] = idx[v][u] = i;
            if (w[i] != -1) {
                vector <int> vec(m + 1, 0);
                vec[i] = 1, vec[m] = w[i];
                add(vec);
            }
        }
        for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) for (int k = j + 1; k < n; ++k) {
            if (idx[i][j] != -1 && idx[j][k] != -1 && idx[k][i] != -1) {
                vector <int> vec(m + 1, 0);
                vec[idx[i][j]] = 1, vec[idx[j][k]] = 1, vec[idx[k][i]] = 1;
                add(vec);
            }
        }
        if (fail) {
            cout << -1 << endl;
        } else {
            for (int i = m - 1; ~i; --i) if (!basis_empty[i]) {
                for (int j = 0; j < m; ++j) if (w[j] != -1) {
                    basis[i][m] -= basis[i][j] * w[j] % 3;
                    basis[i][j] = 0;
                    if (basis[i][m] < 0)
                        basis[i][m] += 3;
                }
                int cnt = 0;
                for (int j = 0; j < m; ++j) if (basis[i][j]) {
                    cnt++;
                }
                for (int j = 0; j < m; ++j) if (basis[i][j]) {
                    if (cnt > 1) {
                        w[j] = 1;
                        basis[i][m] -= basis[i][j];
                        if (basis[i][m] < 0)
                            basis[i][m] += 3;
                    } else {
                        for (int k = 0; k < 3; ++k) if (basis[i][j] * k % 3 == basis[i][m])
                            w[j] = k;
                    }
                    cnt--;
                }
            }
            for (int &i : w) {
                if (i == 0)
                    i = 3;
                if (i == -1)
                    i = 1;
            }
            printv(all(w));
        }
    }
}