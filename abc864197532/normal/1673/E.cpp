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
const int mod = 1e9 + 7, N = 1 << 21, logN = 20, K = 111, M = 4e7;

int pre[N];

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m)
        return 0;
    return (pre[n] - pre[m] - pre[n - m]) > 0 ? 0 : 1;
}

int main () {
    owo;
    for (int i = 1; i < N; ++i) {
        pre[i] = pre[i - 1];
        int now = i;
        while (~now & 1)
            now >>= 1, pre[i]++;
    }
    int n, k;
    cin >> n >> k;
    vector <int> ans(1 << 20, 0);
    vv <int> len(24, 3, 0);
    for (int i = 1; i < 24; ++i) {
        for (int x = k; x < n; ++x) {
            len[i][0] ^= C(n - i, x);
            len[i][1] ^= C(n - i - 1, x - 1);
            len[i][2] ^= C(n - i - 2, x - 2);
        }
    }
    auto query = [&](int l, int r) {
        return len[r - l][(l != 0) + (r != n)];
    };
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        lli res = a[i];
        if (query(i, i + 1)) 
            ans[res] ^= 1;
        for (int j = i + 1; j < min(i + 23, n); ++j) {
            if (a[j] > 20)
                break;
            res <<= a[j];
            if (res >= 1 << 20)
                break;
            if (query(i, j + 1))
                ans[res] ^= 1;
        }
    }
    int st = (1 << 20) - 1;
    while (st > 0 && !ans[st])
        st--;
    for (int i = st; ~i; --i) {
        cout << ans[i];
    }
    cout << endl;
}