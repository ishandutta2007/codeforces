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
const int mod = 998244353, N = 1e5 + 7, logN = 18, C = 350;

int cnt[N * 2];

int solve(int n, vector <int> a) {
    int ans = 0;
    for (int d = 1; d < C; ++d) {
        vector <vector <int>> r(d);
        for (int i = 0; i < n; ++i) {
            r[a[i] % d].pb(i);
        }
        for (int rr = 0; rr < d; ++rr) {
            for (int i : r[rr]) {
                cnt[a[i] / d - i + N]++;
                ans = max(ans, cnt[a[i] / d - i + N]);
            }
            for (int i : r[rr]) {
                cnt[a[i] / d - i + N]--;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= i + C && j < n; ++j) {
            if (a[i] < a[j] && (a[j] - a[i]) % (j - i) == 0) {
                cnt[(a[j] - a[i]) / (j - i)]++;
                ans = max(ans, cnt[(a[j] - a[i]) / (j - i)] + 1);
            }
        }
        for (int j = i + 1; j <= i + C && j < n; ++j) {
            if (a[i] < a[j] && (a[j] - a[i]) % (j - i) == 0) {
                cnt[(a[j] - a[i]) / (j - i)]--;
            }
        }
    }
    return ans;
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> cnt(N);
    for (int i = 0; i < n; ++i) {
        cin >> a[i], cnt[a[i]]++;
    }
    int ans = *max_element(all(cnt));
    ans = max(ans, solve(n, a));
    reverse(all(a));
    ans = max(ans, solve(n, a));
    cout << n - ans << '\n';
}