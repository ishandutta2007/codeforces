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
const int mod = 998244353, N = 1 << 18, logN = 19, K = 1 << 9, G = 3;

int main () {
    owo;
    int n, d, k;
    cin >> n >> d >> k;
    if (n == 2) {
        cout << (d == 1 ? "YES\n1 2\n" : "NO\n");
    } else if (n == 1 || d >= n || k == 1 || d == 1) {
        cout << "NO\n";
    } else {
        queue <pair <pii, int>> q;
        vector <pii> edge;
        for (int i = 0; i + 1 <= d; ++i) {
            edge.eb(i, i + 1);
            if (i != 0 && k > 2)
                q.emplace(mp(min(i, d - i), k - 2), i);
        }
        int m = d + 1;
        while (m < n && !q.empty()) {
            int a, b, c;
            tie(a, b) = q.front().X, c = q.front().Y, q.pop();
            while (b && m < n) {
                edge.eb(c, m);
                if (a > 1)
                    q.emplace(mp(a - 1, k - 1), m);
                ++m, --b;
            }
        }
        if (m < n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (pii A : edge) {
                cout << A.X + 1 << ' ' << A.Y + 1 << endl;
            }
        }
    }
}