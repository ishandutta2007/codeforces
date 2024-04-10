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
const int mod = 998244353, N = 51, logN = 20, K = 111, C = 7;

map <vector <int>, int> dp;

int solve(vector <int> a) {
    if (dp[a])
        return dp[a];
    int n = a.size();
    for (int s = 0; s < 1 << n; ++s) {
        if (__builtin_popcount(s) != n / 2)
            continue;
        for (int i = 0; i < n; ++i) if (s >> i & 1) {
            for (int j = i + 1; j < n; ++j) if (s >> j & 1) {
                if (a[i] && a[j]) {
                    for (int ii = 1; ii <= a[i]; ++ii) for (int jj = 1; jj <= a[j]; ++jj) {
                        vector <int> b = a;
                        b[i] -= ii, b[j] -= jj;
                        if (solve(b) == 2)
                            return dp[a] = 1;
                    }
                }
            }
        }
    }
    return dp[a] = 2;
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (count(all(a), *min_element(all(a))) > n / 2) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}