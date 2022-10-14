
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
const int mod = 998244353, N = 60, logN = 18, K = 1 << 9, G = 3;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector <int> rt(n, 0), ch(n, 0), dep(n, 0);
        vector <vector <int>> D(n);
        for (int i = 1; i < n; ++i) {
            rt[i] = i - 1 >> 1, dep[i] = dep[rt[i]] + 1, ch[rt[i]]++;
            D[dep[i]].pb(i);
            d -= dep[i];
        }
        if (d < 0) {
            cout << "NO\n";
            continue;
        }
        while (d) {
            bool is = false;
            for (int i = n - 1; i > 0; --i) {
                int from = 0, to = 0;
                for (int j : D[i]) {
                    if (!from && !ch[j])
                        from = j;
                    else if (ch[j] < 2) {
                        to = j;
                    }
                }
                if (from && to) {
                    ch[rt[from]]--, D[dep[from]].erase(find(all(D[dep[from]]), from));
                    is = true;
                    rt[from] = to, dep[from]++, ch[to]++, D[dep[from]].pb(from);
                    break;
                }
            }
            if (!is)
                break;
            d--;
        }
        if (d > 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i < n; ++i) cout << ++rt[i] << " \n"[i == n - 1];
        }
    }
}