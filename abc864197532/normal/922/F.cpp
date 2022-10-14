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
const int mod = 998244353, N = 300005, logN = 20, M = 6e6;

int d[N];
bool p[N];

int main () {
    owo;
    fill(p + 2, p + N, true);
    for (int i = 1; i < N; ++i) for (int j = i + i; j < N; j += i) 
        d[j]++, p[j] &= (i == 1);
    int n, k;
    cin >> n >> k;
    if (accumulate(d + 2, d + n + 1, 0) < k) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        int now = accumulate(d + 2, d + m + 1, 0);
        for (int i = 2; i <= m; ++i) if (p[i])
            now -= m / i;
        if (now <= k)
            l = m;
        else
            r = m;
    }
    n = l;
    vector <int> ans(n + 1, true); ans[0] = false;
    int now = accumulate(d + 2, d + n + 1, 0);
    for (int i = 2; i <= n; ++i) if (p[i] && now - n / i >= k) {
        now -= n / i;
        ans[i] = false;
    }
    cout << count(all(ans), true) << endl;
    for (int i = 1; i <= n; ++i) if (ans[i]) {
        cout << i << ' ';
    }
    cout << endl;
}