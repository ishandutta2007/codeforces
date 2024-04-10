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
const int mod = 998244353, N = 300005, logN = 20, K = 111, C = 1e9;

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

lli hsh[N], len[N];

int main () {
    owo;
    for (int i = 1; i < N; ++i) {
        hsh[i] = uniform_int_distribution<lli>(0, (1ll << 60) - 1)(rng);
        len[i] = len[i - 1] ^ hsh[i];
    }
    int n;
    cin >> n;
    vector <int> a(n);
    vector <lli> pre;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int t : {0, 1}) {
        pre.assign(n + 1, 0);
        for (int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] ^ hsh[a[i]];
        for (int i = 0; i < n; ++i) {
            while (i < n && a[i] != 1)
                i++;
            if (i == n)
                break;
            int mx = a[i];
            for (int j = i + 1; j < n && a[j] != 1; ++j) {
                mx = max(mx, a[j]);
                int l = j + 1 - mx;
                if (l >= 0)
                    ans += (pre[j + 1] ^ pre[l]) == len[mx];
            }
        }
        reverse(all(a));
    }
    cout << ans + count(all(a), 1) << endl;
}