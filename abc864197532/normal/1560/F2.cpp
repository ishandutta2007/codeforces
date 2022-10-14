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
const int N = 100001, logN = 18, K = 1000, bound = (1 << 30) - 1;

int chk(string s) {
    vector <bool> is(10, false);
    for (char c : s) is[c - '0'] = true;
    return accumulate(all(is), 0);
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        if (chk(s) <= k) {
            cout << s << endl;
            continue;
        }
        int n = s.length();
        for (int i = n - 1; ~i; --i) {
            vector <bool> now(10, false);
            string ans = s.substr(0, i);
            for (int j = 0; j < i; ++j) now[s[j] - '0'] = true;
            int cnt = accumulate(all(now), 0);
            if (cnt > k || s[i] == '9') continue;
            for (int j = s[i] - '0' + 1; j < 10; ++j) {
                if (cnt == k && !now[j]) continue;
                ans.pb('0' + j);
                if (!now[j]) cnt++;
                now[j] = true;
                break;
            }
            if (ans.size() == i) continue;
            for (int j = i + 1; j < n; ++j) {
                for (int c = 0; c < 10; ++c) {
                    if (cnt == k && !now[c]) continue;
                    ans.pb('0' + c);
                    if (!now[c]) cnt++;
                    now[c] = true;
                    break;
                }
            }
            cout << ans << endl;
            break;
        }
    }
}