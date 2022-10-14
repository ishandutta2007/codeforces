/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
const int mod = 998244353, N = 100001, logN = 18, K = 1 << 9, G = 3;

struct item {
    int a, b, m, id;
    bool operator < (const item &o) {
        return a + b - m < o.a + o.b - o.m;
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <item> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i].a >> v[i].b >> v[i].m, v[i].id = i;
        sort(all(v));
        vector <int> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            if (v[i].a >= v[i].m) {
                l[i] = v[i].a - v[i].m;
            } else {
                l[i] = 0;
            }
            if (v[i].b >= v[i].m) {
                r[i] = v[i].a;
            } else {
                r[i] = v[i].a + v[i].b - v[i].m;
            }
        }
        int ans = 0;
        vector <pii> tans(n);
        for (int i = 0, j = 0; i < n; i = j) {
            vector <int> tmp;
            while (j < n && v[i].a + v[i].b - v[i].m == v[j].a + v[j].b - v[j].m) {
                tmp.pb(j);
                j++;
            }
            sort(all(tmp), [&](int i, int j) {
                return r[i] < r[j];
            });
            int cur = -1;
            for (int i : tmp) {
                if (cur < l[i]) {
                    ans++;
                    cur = r[i];
                }
                test(i, v[i].id, l[i], r[i]);
                tans[v[i].id] = mp(v[i].a - cur, v[i].m - v[i].a + cur);
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; ++i) {
            cout << tans[i].X << ' ' << tans[i].Y << endl;
        }
    }
}