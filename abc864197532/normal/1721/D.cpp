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
const int mod = 998244353, N = 200087;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector <vector <int>> A, B;
    A.pb(a), B.pb(b);
    int ans = 0;
    for (int bit = 29; ~bit; --bit) {
        bool is = true;
        for (int i = 0; i < A.size(); ++i) {
            int cnt0 = 0, cnt1 = 0, n = A[i].size();
            for (int j = 0; j < n; ++j) if (A[i][j] >> bit & 1)
                cnt0++;
            for (int j = 0; j < n; ++j) if (B[i][j] >> bit & 1)
                cnt1++;
            if (cnt0 + cnt1 != n) {
                is = false;
            }
        }
        if (is) {
            ans |= 1 << bit;
            vector <vector <int>> nxtA, nxtB;
            for (int i = 0; i < A.size(); ++i) {
                vector <int> a0, a1, b0, b1;
                int n = A[i].size();
                for (int j = 0; j < n; ++j) {
                    (A[i][j] >> bit & 1 ? a1 : a0).pb(A[i][j]);
                }
                for (int j = 0; j < n; ++j) {
                    (B[i][j] >> bit & 1 ? b1 : b0).pb(B[i][j]);
                }
                if (!a1.empty())
                    nxtA.pb(a1), nxtB.pb(b0);
                if (!a0.empty())
                    nxtA.pb(a0), nxtB.pb(b1);
            }
            A = nxtA, B = nxtB;
        }
    }
    cout << ans << '\n';
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}