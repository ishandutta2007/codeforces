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
const int mod = 998244353, N = 1002, logN = 19, K = 111, M = 1000006, INF = 1e9 + 87;

vector <int> gen(vector <int> p) {
    vector <int> ans;
    for (int i = 0; i < p.size(); ++i) {
        ans.pb(0);
        for (int j = 0; j < i; ++j)
            ans.back() += p[j] > p[i];
    }
    return ans;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector <int> l(n), r(n);
        bool fail = false;
        {
            int cnt = 0;
            while (cnt < k) {
                if (a.back() > 0)
                    fail = true;
                a.pop_back();
                cnt++;
            }
        }
        if (fail) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                l[i] = 0, r[i] = i;
            } else {
                // [l, r]
                if (a[i - k] == -1)
                    l[i] = 0, r[i] = i;
                else if (a[i - k] == 0)
                    l[i] = 0, r[i] = min(k, i);
                else {
                    l[i] = a[i - k] + k, r[i] = a[i - k] + k;
                    if (l[i] > i)
                        fail = true;
                }
            }
        }
        if (fail) {
            cout << 0 << '\n';
            continue;
        }
        lli ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = ans * (r[i] - l[i] + 1) % mod;
        }
        cout << ans << '\n';
    }
}