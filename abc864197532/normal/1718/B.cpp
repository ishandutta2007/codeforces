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
const int mod = 1e9 + 7, N = 60;

ll f[N];

void solve() {
    int n;
    cin >> n;
    vector <ll> need;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n == 1) {
        cout << (a[0] == 1 ? "YES\n" : "NO\n");
        return;
    }
    ll sum = accumulate(all(a), 0ll);
    while (sum) {
        if (sum < f[need.size()]) {
            cout << "NO\n";
            return;
        }
        sum -= f[need.size()];
        need.pb(f[need.size()]);
    }
    vector <int> cnt(need.size(), 0), lst(need.size(), 0);
    for (int i = 0; i < n; ++i) {
        ll now = a[i];
        for (int j = need.size() - 1; j >= 0; --j) if (now >= need[j]) {
            now -= need[j];
            cnt[j]++;
            if (!now) {
                lst[j]++;
            }
            j--;
        }
        if (now) {
            cout << "NO\n";
            return;
        }
    }
    // 1 1 2 3
    for (int j = 3; j < need.size(); j += 2) if (cnt[j] > 1) {
        int x = min(cnt[j] - 1, lst[j]);
        cnt[j] -= x;
        for (int i = 0; i < j; i += 2)
            cnt[i] += x;
    }
    if (need.size() >= 2 && cnt[1] > 1) {
        int x = cnt[1] - 1;
        cnt[1] -= x, cnt[0] += x;
    }
    for (int i = 0; i < need.size(); ++i) if (cnt[i] != 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main () {
    owo;
    f[0] = f[1] = 1;
    for (int i = 2; i < N; ++i)
        f[i] = f[i - 1] + f[i - 2];
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}