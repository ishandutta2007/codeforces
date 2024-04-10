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
const int mod = 998244353, N = 4e6 + 1, logN = 18, K = 1 << 9, G = 3;

int main () {
    owo;
    int n;
    string s;
    cin >> n >> s;
    vector <int> pre(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i)
            pre[i] = pre[i - 1];
        pre[i] += (s[i] == '(' ? 1 : -1);
    }
    if (pre[n - 1] != 0) {
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    int mn = *min_element(all(pre));
    int l = n, r = -1, ord = 0, ans = 0, ansl = 0, ansr = 0;
    for (int i = 0; i < n; ++i) if (pre[i] == mn) {
        l = min(l, i), r = max(r, i);
        ord++;
    }
    ans = ord;
    r++;
    if (0 <= l && r < n) {
        for (int k = l; k < r; ++k) 
            pre[k] += 2;
        int tans = count(all(pre), *min_element(all(pre)));
        for (int k = l; k < r; ++k) 
            pre[k] -= 2;
        if (ans < tans) {
            ans = tans, ansl = l, ansr = r;
        }
    }
    l = n, r = -1;
    for (int i = 0; i < n; ++i) if (pre[i] <= mn + 1) {
        l = min(l, i), r = max(r, i);
    }
    r++;
    if (0 <= l && r < n) {
        for (int k = l; k < r; ++k) 
            pre[k] += 2;
        int tans = count(all(pre), *min_element(all(pre)));
        for (int k = l; k < r; ++k) 
            pre[k] -= 2;
        if (ans < tans) {
            ans = tans, ansl = l, ansr = r;
        }
    }
    for (int i = 0, j = 0; i < n; i = j) {
        if (pre[i] != mn + 2) {
            j++;
            continue;
        }
        int cnt = 1, ll = i, rr = i + 1;
        while (j < n && pre[j] > mn + 1) {
            j++;
            if (pre[j] == mn + 2) {
                rr = j + 1;
                cnt++;
            }
        }
        if (ans < ord + cnt) {
            ans = ord + cnt;
            ansl = ll, ansr = rr;
        }
    }
    for (int i = 0, j = 0; i < n; i = j) {
        if (pre[i] != mn + 1) {
            j++;
            continue;
        }
        int cnt = 1, ll = i, rr = i + 1;
        while (j < n && pre[j] > mn) {
            j++;
            if (pre[j] == mn + 1) {
                rr = j + 1;
                cnt++;
            }
        }
        if (ans < cnt) {
            ans = cnt;
            ansl = ll, ansr = rr;
        }
    }
    cout << ans << endl;
    cout << ++ansl << ' ' << ++ansr << endl;
}