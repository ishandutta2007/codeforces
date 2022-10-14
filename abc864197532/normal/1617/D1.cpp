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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    if (a.empty())
        return o << "{}";
    bool is = false;
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
const int mod = 1e9 + 7, N = 1100005, logN = 18;

int main () {
    // owo;
    /*
    vector <int> v;
    for (int s = 0; s < 1 << 4; ++s) if (__builtin_popcount(s) == 3) {
        v.pb(s);
    }
    map <vector <int>, vector <int>> m1;
    for (int s = 0; s < 1 << 4; ++s) {
        vector <int> res;
        for (int i : v) {
            int cnt = 0;
            for (int j = 0; j < 4; ++j) if (i >> j & 1) {
                if (s >> j & 1)
                    cnt++;
                else
                    cnt--;
            }
            if (cnt > 0)
                res.pb(1);
            else
                res.pb(0);
        }
        m1[res].pb(s);
    }
    for (auto A : m1)
        test(A.Y);
        */
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto ask = [&](int i, int j, int k) {
            cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
            cin >> i;
            return i;
        };
        vector <int> ans(n, -1);
        int pre = ask(0, 1, 2), a = -1, b = -1;
        for (int i = 1; i + 2 < n; ++i) {
            int now = ask(i, i + 1, i + 2);
            // i - 1 & i + 2 dif
            if (pre != now) {
                a = i - 1, b = i + 2;
                break;
            }
        }
        if (a == -1 && b == -1) {
            for (int i = 0; i + 3 < n; ++i) {
                int x = ask(i, i + 3, i + 1);
                ans[i] = ans[i + 3] = x;
            }
        } else {
            for (int i = 0; i < n; ++i) if (i != a && i != b) {
                ans[i] = ask(i, a, b);
            }
            int c = -1, d = -1;
            for (int i = 0; i < n; ++i) if (i != a && i != b) {
                if (ans[i] == 0)
                    c = i;
                else
                    d = i;
            }
            ans[a] = ask(a, c, d);
            ans[b] = ask(b, c, d);
        }
        vector <int> v;
        for (int i = 0; i < n; ++i) if (ans[i] == 0)
            v.pb(i + 1);
        cout << "! " << v.size();
        for (int i : v)
            cout << ' ' << i;
        cout << endl;
    }
}
// 6 
// 0 1 0 0 1 0