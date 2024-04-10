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
const int mod = 998244353, N = 5001, logC = 30, logN = 19, K = 111, M = 4e6;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        vector <int> lose;
        int oth = 0;
        int now = 0;
        for (char c : s) {
            if (c == '.') now++;
            else if (now) {
                if ((b <= now && now < a) || now >= b * 2) lose.pb(now);
                else if (now >= b) oth ^= 1;
                now = 0;
            }
        }
        if (now) {
            if ((b <= now && now < a) || now >= b * 2) lose.pb(now);
            else if (now >= b) oth ^= 1;
        }
        if (lose.size() >= 2) {
            cout << "NO\n";
        } else if (lose.empty()) {
            cout << (oth ? "YES\n" : "NO\n");
        } else {
            int x = lose[0];
            bool is = false;
            if (x >= a) {
                for (int i = 0; i <= x - a; ++i) {
                    int j = x - a - i, ncur = oth;
                    if ((b <= i && i < a) || i >= b * 2 || (b <= j && j < a) || j >= b * 2) continue;
                    if (i >= b) ncur ^= 1;
                    if (j >= b) ncur ^= 1;
                    if (!ncur) is = true;
                }
            }
            cout << (is ? "YES\n" : "NO\n");
        }
    }
}