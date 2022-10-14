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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 2e5 + 101, logN = 18;

int main () {
    owo;
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return a[i] > a[j]; 
    });
    sort(rall(a));
    vector <pair <lli, int>> premx(n + 1, mp(0, -1));
    for (int i = 0; i < n; ++i)
        premx[i + 1] = max(premx[i], mp(1ll * a[i] * (i + 1), i + 1));
    vector <pair <int, int>> sufmn(n + 1, mp(1 << 30, -1));
    for (int i = n - 1; ~i; --i) {
        sufmn[i] = min(sufmn[i + 1], mp((x2 + a[i] - 1) / a[i] - i, i + 1));
    }
    for (int cnt = 1, i = 0; cnt < n; ++cnt) {
        int now = (x1 + cnt - 1) / cnt;
        while (i < n && a[i] >= now) {
            i++;
        }
        if (i < cnt)
            continue;
        // [0, i - cnt) + [i, n)
        if (premx[i - cnt].X >= x2) {
            // out
            cout << "Yes\n";
            int cnt2 = premx[i - cnt].Y;
            cout << cnt << ' ' << cnt2 << '\n';
            for (int j = i - cnt; j < i; ++j)
                cout << p[j] + 1 << ' ';
            cout << '\n';
            for (int j = 0; j < cnt2; ++j)
                cout << p[j] + 1 << ' ';
            cout << '\n';
            return 0;
        }
        // [i, n)
        // a[j] * (i - cnt + j - i + 1) = a[j] * (j - cnt + 1) >= x2
        // -cnt + 1 >= x2 / a[j] - j
        if (i == n)
            continue;
        auto res = sufmn[i];
        if (-cnt + 1 >= res.X) {
            cout << "Yes\n";
            int cnt2 = res.Y;
            cout << cnt << ' ' << cnt2 - cnt << '\n';
            for (int j = i - cnt; j < i; ++j)
                cout << p[j] + 1 << ' ';
            cout << '\n';
            for (int j = 0; j < i - cnt; ++j)
                cout << p[j] + 1 << ' ';
            for (int j = i; j < cnt2; ++j)
                cout << p[j] + 1 << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "No\n";
}