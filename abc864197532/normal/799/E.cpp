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
const int mod = 998244353, N = 200005;

struct DS {
    multiset <int, greater <int>> in;
    multiset <int> out;
    lli sum;
    int cap;
    DS () : sum(0), cap(0) {}
    void enlarge() {
        if (!out.empty()) {
            int mx = *out.begin();
            sum += mx, in.insert(mx), out.erase(out.begin());
        }
        cap++;
    }
    void insert(int x) {
        if (!cap) {
            out.insert(x);
            return;
        }
        if (in.size() < cap) {
            in.insert(x), sum += x;
            return;
        }
        int mx = *in.begin();
        if (x < mx) {
            sum -= mx, out.insert(mx), in.erase(in.begin());
            sum += x, in.insert(x);
        } else {
            out.insert(x);
        }
    }
    void erase(int x) {
        if (out.find(x) != out.end()) {
            out.erase(out.lower_bound(x));
        } else {
            in.erase(in.lower_bound(x)), sum -= x;
            if (!out.empty()) {
                int mx = *out.begin();
                sum += mx, out.erase(out.begin()), in.insert(mx);
            }
        }
    }
} DS;

int main () {
    owo;
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    vector <int> now(n);
    int sz;
    cin >> sz;
    for (int i = 0, x; i < sz; ++i)
        cin >> x, now[--x] |= 1;
    cin >> sz;
    for (int i = 0, x; i < sz; ++i)
        cin >> x, now[--x] |= 2;
    vector <int> a[4];
    for (int i = 0; i < n; ++i) {
        a[now[i]].pb(c[i]);
    }
    for (int i : {0, 1, 2, 3})
        sort(all(a[i]));
    lli ans1 = 0, ans2 = 0, ans = 0;
    int cnt3 = 0, cnt1 = k, cnt0 = m - k - k;
    while (cnt3 <= min(k, int(a[3].size()))) {
        if (cnt0 < 0 || cnt1 > a[1].size() || cnt1 > a[2].size())
            cnt3++, cnt1--, cnt0++;
        else
            break;
    }
    if (cnt3 > min(k, int(a[3].size()))) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < cnt3; ++i)
        ans1 += a[3][i];
    for (int i = cnt3; i < a[3].size(); ++i)
        DS.insert(a[3][i]);
    for (int i = 0; i < cnt1; ++i)
        ans2 += a[1][i];
    for (int i = cnt1; i < a[1].size(); ++i)
        DS.insert(a[1][i]);
    for (int i = 0; i < cnt1; ++i)
        ans2 += a[2][i];
    for (int i = cnt1; i < a[2].size(); ++i)
        DS.insert(a[2][i]);
    for (int i = 0; i < a[0].size(); ++i)
        DS.insert(a[0][i]);
    for (int i = 0; i < cnt0; ++i)
        DS.enlarge();
    ans = ans1 + ans2 + DS.sum;
    for (; cnt3 + 1 <= min(k, int(a[3].size())); ) {
        ans1 += a[3][cnt3];
        DS.erase(a[3][cnt3]);
        if (cnt1 >= 1) {
            ans2 -= a[1][cnt1 - 1];
            DS.insert(a[1][cnt1 - 1]);
            ans2 -= a[2][cnt1 - 1];
            DS.insert(a[2][cnt1 - 1]);
        }
        DS.enlarge();
        cnt3++, cnt1--, cnt0++;
        if (cnt1 < 0)
            cnt1 = 0;
        ans = min(ans, ans1 + ans2 + DS.sum);
    }
    cout << ans << '\n';
}