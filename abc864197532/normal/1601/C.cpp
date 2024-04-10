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
const int mod = 998244353, N = 2000087, logN = 19, K = 1 << 9;

struct BIT {
    long long bit[N];
    int n;
    BIT (int _n) : n(_n) {
        for (int i = 0; i < n; ++i) bit[i] = 0;
    }
    void add (int p, long long a) {
        for (int i = p; i < n; i += (i & -i)) bit[i] += a;
    }
    long long query (int p) {
        long long all = 0;
        for (int i = p; i > 0; i -= (i & -i)) all += bit[i];
        return all;
    }
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

lli solve(vector <int> a) {
    int mx = *max_element(all(a));
    BIT bit(mx + 1);
    lli ans = 0;
    for (int i : a) {
        ans += bit.query(i + 1, mx);
        bit.add(i, 1);
    }
    return ans;
}


int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> a(n), b(m);
        vector <int> v;
        for (int i = 0; i < n; ++i)
            cin >> a[i], v.pb(a[i]);
        for (int i = 0; i < m; ++i)
            cin >> b[i], v.pb(b[i]);
        sort(all(b));
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        for (int &i : a)
            i = lower_bound(all(v), i) - v.begin() + 1;
        for (int &i : b)
            i = lower_bound(all(v), i) - v.begin() + 1;
        vector <pii> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.eb(i, a[i]);
        }
        function<void(int, int, int, int)> dc = [&](int l, int r, int tl, int tr) {
            if (l >= r) 
                return;
            int cur = 0, mn = 1 << 30, p = -1, m = l + r >> 1;
            for (int i = tl; i < tr; ++i) {
                if (cur < mn) {
                    cur = mn;
                    p = i;
                }
                if (i >= n)
                    continue;
                if (a[i] > b[m])
                    cur++;
                else if (a[i] < b[m])
                    cur--;
            }
            tmp.eb(p, b[m]);
            dc(l, m, tl, p + 1), dc(m + 1, r, p, tr);
            return;
        };
        dc(0, m, 0, n + 1);
        sort(all(tmp));
        vector <int> c;
        for (auto i : tmp)
            c.pb(i.Y);
        lli ans = solve(c);
        cout << ans << endl;
    }
}