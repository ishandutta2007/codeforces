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
    int n;
    cin >> n;
    vector <int> a(n), cnt(n), mn(n, -1), mx(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i], --a[i];
        cnt[a[i]]++;
        if (!~mn[a[i]])
            mn[a[i]] = i;
        mx[a[i]] = i;
    }
    int ans = 0;
    vector <pii> seg;
    for (int i = 0; i < n; ++i) if (cnt[i]) {
        if (cnt[i] == 1)
            seg.eb(mx[i], -1);
        else {
            seg.eb(mn[i], mx[i]);
        }
    }
    sort(all(seg));
    {
        int mx = -1;
        vector <pii> stk;
        for (auto [l, r] : seg) {
            if (r == -1) {
                if (mx < l)
                    ans++;
                continue;
            }
            if (mx != -1 && mx < l) {
                ans += int(stk.size()) + 1;
                stk.clear();
                stk.eb(l, r);
                mx = r;
            } else {
                if (r > mx) {
                    while (stk.size() >= 2 && l < stk[stk.size() - 2].Y)
                        stk.pop_back();
                    stk.eb(l, r), mx = r;
                }
            }
        }
        if (mx != -1)
            ans += int(stk.size()) + 1;
    }
    cout << n - ans << endl;
}