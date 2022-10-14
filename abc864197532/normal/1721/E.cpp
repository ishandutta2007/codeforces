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

int main () {
    owo;
    string s;
    cin >> s;
    int n = s.length();
    vector <int> f(n + 87, 0);
    vv <int> to(n + 87, 26, 0);
    int k = 0;
    for (int i = 1; i < n; ++i) {
        k = to[k][s[i] - 'a'];
        if (s[k] == s[i])
            k++;
        f[i + 1] = k;
        for (int j = 0; j < 26; ++j) {
            if (s[i] - 'a' == j)
                to[i][j] = i;
            else
                to[i][j] = to[f[i]][j];
        }
    }
    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        s += t;
        int now = k;
        for (int i = n; i < s.length(); ++i) {
            now = to[now][s[i] - 'a'];
            if (s[now] == s[i])
                now++;
            f[i + 1] = now;
            for (int j = 0; j < 26; ++j) {
                if (s[i] - 'a' == j)
                    to[i][j] = i;
                else
                    to[i][j] = to[f[i]][j];
            }
        }
        for (int i = n + 1; i <= s.length(); ++i) {
            cout << f[i] << ' ';
        }
        cout << '\n';
        while (s.size() > n)
            s.pop_back();
    }
}