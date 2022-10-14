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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 100001, logN = 20, K = 1500;

int ask(vector <int> a, vector <int> b) {
    cout << "? " << a.size() << ' ' << b.size() << endl;
    for (int &i : a)
        cout << ++i << ' ';
    cout << endl;
    for (int &i : b)
        cout << ++i << ' ';
    cout << endl;
    string s;
    cin >> s;
    assert(s != "WASTE");
    if (s == "FIRST")
        return -1;
    if (s == "SECOND")
        return 1;
    return 0;
}

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool is_val = false;
        for (int t = 0; t < 25; ++t) {
            int x = uniform_int_distribution<int>(1, n - 1)(rng);
            if (ask({0}, {x}) == 1) {
                is_val = true;
                break;
            }
        }
        if (is_val) {
            cout << "! " << 1 << endl;
        } else {
            int len = 1;
            while (len * 2 <= n) {
                vector <int> a, b;
                for (int i = 0; i < len; ++i) {
                    a.pb(i);
                }
                for (int i = len; i < len * 2; ++i) {
                    b.pb(i);
                }
                if (!ask(a, b) == 0) {
                    break;
                }
                len <<= 1;
            }
            // from len to min(len * 2, n)
            int l = len, r = min(len * 2, n);
            while (r - l > 1) {
                int mid = l + r >> 1;
                vector <int> a, b;
                for (int i = 0; i < mid - len; ++i) {
                    a.pb(i);
                }
                for (int i = len; i < mid; ++i) {
                    b.pb(i);
                }
                if (ask(a, b) == 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cout << "! " << l + 1 << endl;
        }
    }
}