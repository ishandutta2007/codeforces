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
const int mod = 998244353, N = 1000001, logN = 20, K = 111;

vector <int> build_fail(string &s) {  
    vector <int> f(s.length() + 1, 0);
    int k = 0;
    for (int i = 1; i < s.length(); ++i) {
        while (k && s[k] != s[i]) k = f[k];
        if (s[k] == s[i]) k++;
        f[i + 1] = k;
    }
    return f;
}

int main () {
    owo;
    string s;
    cin >> s;
    if (s.length() == 1) {
        if (s == "X" || s == "_" || s == "0")
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    int n = s.length(), ans = 0;
    for (int i = 1; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k <= 5; k += 5)
                for (int l = 0; l < 10; ++l) {
                    if (s[0] != '0' + i && s[0] != '_' && (s[0] != 'X' || l != i))
                        continue;
                    if (s[n - 2] != '0' + j && s[n - 2] != '_' && (s[n - 2] != 'X' || l != j))
                        continue;
                    if (s[n - 1] != '0' + k && s[n - 1] != '_' && (s[n - 1] != 'X' || l != k))
                        continue;
                    if (s.length() == 2 && i != j)
                        continue;
                    if ((j * 10 + k) % 25 != 0)
                        continue;
                    bool tmp = false;
                    int cnt = 0;
                    for (int _i = 1; _i < n - 2; ++_i)
                        if (s[_i] == 'X')
                            tmp = true;
                        else if (s[_i] == '_')
                            ++cnt;
                    bool tmp2 = true;
                    if (s[0] == 'X' || s[n - 2] == 'X' || s[n - 1] == 'X')
                        tmp2 = false;
                    if (!tmp && tmp2 && l)
                        continue;
                    //cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
                    ans += pow(10, cnt);

                }
    cout << ans;
}