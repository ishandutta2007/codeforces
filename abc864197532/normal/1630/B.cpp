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
const int mod = 1e9 + 7, N = 1e5 + 87, logN = 20, K = 111, M = N * 20;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> cnt(n), a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i], cnt[--a[i]]++;
        int sum = -n, ans = 1 << 30, pl = -1, pr = -1;
        for (int l = 0, r = 0; l < n; ++l) {
            while (sum < k && r < n) {
                sum += cnt[r++] * 2;
                if (sum >= k)
                    break;
            }
            if (ans > r - l && sum >= k)
                ans = r - l, pl = l, pr = r;
            sum -= cnt[l] * 2;
        }
        cout << pl + 1 << ' ' << pr << endl;
        if (k == 1) {
            cout << 1 << ' ' << n << endl;
            continue;
        }
        vector <int> split;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            if (pl <= a[i] && a[i] < pr)
                sum++;
            else
                sum--;
            if (sum > 0)
                split.pb(i), sum = 0;
        }
        while (split.size() > k - 1)
            split.pop_back();
        cout << 1 << ' ' << split[0] + 1 << endl;
        for (int i = 1; i < split.size(); ++i)
            cout << split[i - 1] + 2 << ' ' << split[i] + 1 << endl;
        cout << split.back() + 2 << ' ' << n << endl;
    }
}