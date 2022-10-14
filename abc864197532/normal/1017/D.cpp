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
const int mod = 998244353, N = 2e6 + 5, logN = 20, M = 6e6;

int pre[1 << 6][1 << 6][101];

int get() {
    string s; cin >> s; reverse(all(s));
    int val = 0;
    for (char c : s)
        val = val * 2 + c - '0';
    return val;
}

int main () {
    owo;
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> w(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    if (n <= 6) {
        vector <int> cnt(1 << n);
        for (int i = 0; i < m; ++i) {
            int val = get();
            cnt[val]++;
        }
        while (q--) {
            int val = get(), k;
            cin >> k;
            int ans = 0;
            for (int s = 0; s < 1 << n; ++s) {
                int now = 0, x = val ^ s;
                for (int i = 0; i < n; ++i) if (~x >> i & 1)
                    now += w[i];
                if (now <= k)
                    ans += cnt[s];
            }
            cout << ans << '\n';
        }
    } else {
        for (int i = 0; i < m; ++i) {
            int val = get();
            for (int j = 0; j < 1 << 6; ++j) {
                int now = 0, x = val ^ j;
                for (int i = 0; i < 6; ++i) if (~x >> i & 1)
                    now += w[i];
                if (now <= 100)
                    pre[j][val >> 6][now]++;
            }
        }
        for (int i = 0; i < 1 << 6; ++i) for (int j = 0; j < 1 << 6; ++j) {
            for (int x = 1; x <= 100; ++x)
                pre[i][j][x] += pre[i][j][x - 1];
        }
        while (q--) {
            int val = get(), k;
            cin >> k;
            int ans = 0;
            for (int s = 0; s < 1 << n - 6; ++s) {
                int now = 0, x = (val >> 6) ^ s;
                for (int i = 0; i < n - 6; ++i) if (~x >> i & 1)
                    now += w[i + 6];
                if (now <= k)
                    ans += pre[val & 63][s][k - now];
            }
            cout << ans << '\n';
        }
    }
}