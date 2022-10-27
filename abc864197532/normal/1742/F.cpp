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
const int mod = 998244353, N = 1 << 20, K = 250;

void solve() {
    int q; cin >> q;
    vv <ll> cnt(26, 2, 0);
    vector <ll> len(2);
    cnt[0][0]++, cnt[0][1]++;
    len[0] = 1, len[1] = 1;
    while (q--) {
        int d, k; string s;
        cin >> d >> k >> s, --d;
        for (char c : s) {
            cnt[c - 'a'][d] += k;
            len[d] += k;
        }
        bool ans = false;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) if (cnt[i][0] && cnt[j][1]) {
                ans = true;
            }
        }
        for (int i = 0; i < 26; ++i) if (len[0] == cnt[i][0] && len[1] == cnt[i][1]) {
            if (len[0] < len[1])
                ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}