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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 400001, logN = 20, K = 350;
const long long INF = 1ll << 61;

void add(lli &i, lli j) {
    i += j;
    if (i > INF) i = INF;
}

void mul(lli &i, lli j) {
    if (!j) i = 0;
    else {
        if (i > INF / j) i = INF;
        else i *= j;
    }
}

int main () {
    owo;
    vector <lli> a;
    int n;
    lli k;
    cin >> n >> k;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (a.empty() && !x) continue;
        a.pb(x);
        if (x >= k) {
            cout << 0 << endl;
            return 0;
        }
    }
    n = a.size();
    if (n > 3) {
        int cnt = 0;
        while (true) {
            cnt++;
            for (int i = 1; i < n; ++i) {
                add(a[i], a[i - 1]);
            }
            if (a.back() >= k) break;
        }
        cout << cnt << endl;
    } else if (n == 3) {
        /*
         * a b c
         * a a + b a + b + c
         * a 2a + b 3a + 2b + c
         * a 3a + b 6a + 3b + c
         * a 4a + b 10a + 4b + c
         * 0 0 1
         * 1 1 1
         * 3 2 1
         * 6 3 1
         * i times
         * C(i, 2) * a + ib + c
         */
        lli l = 0, r = 1518500251;
        while (r - l > 1) {
            lli mid = l + r >> 1;
            lli res = (mid + 1) * mid / 2;
            mul(res, a[0]);
            add(res, mid * a[1]);
            add(res, a[2]);
            if (res >= k) r = mid;
            else l = mid;
        }
        cout << r << endl;
    } else {
        /*
         * a b
         * a a + b
         * a 2a + b
         */
        lli l = 0, r = 1ll << 60;
        while (r - l > 1) {
            lli mid = l + r >> 1;
            lli res = mid;
            mul(res, a[0]);
            add(res, a[1]);
            if (res >= k) r = mid;
            else l = mid;
        }
        cout << r << endl;
    }
}