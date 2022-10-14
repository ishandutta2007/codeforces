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
const int mod = 1e9 + 7, N = 200087, logN = 20, M = 1000010;

lli fac[N], facp[N];

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

lli C(int n, int m) {
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

int main () {
    owo;
    fac[0] = facp[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        facp[i] = modpow(fac[i], mod - 2);
    }
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    lli ans = 1;
    for (int i = 0; i < n; ++i) {
        ans += ans;
        if (ans >= mod)
            ans -= mod;
    }
    ans--;
    vector <int> cnt(30, 0);
    for (int i = 0; i < n; ++i) {
        int b = 0;
        while (a[i] & 1 ^ 1)
            b++, a[i] >>= 1;
        cnt[b]++;
    }
    for (int i = 1; i < 30; ++i) {
        int after = accumulate(cnt.begin() + i + 1, cnt.end(), 0);
        lli pw = modpow(2, after);
        for (int j = 1; j <= cnt[i]; j += 2) {
            ans -= pw * C(cnt[i], j) % mod;
            if (ans < 0)
                ans += mod;
        }
    }
    cout << ans << endl;
}