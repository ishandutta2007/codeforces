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
const int mod = 1e9 + 7, N = 1e5 + 87, logN = 20, K = 111, M = N * 20;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k == n - 1) {
            if (n == 4) {
                cout << -1 << endl;
            } else {
                vector <int> a(n >> 1), b(n >> 1);
                iota(all(a), 0), iota(all(b), n >> 1);
                reverse(all(b));
                swap(a[0], b[1]);
                swap(b[1], a[3]);
                for (int i = 0; i < n / 2; ++i)
                    cout << a[i] << ' ' << b[i] << endl;
            }
        } else {
            vector <int> a(n >> 1), b(n >> 1);
            iota(all(a), 0), iota(all(b), n >> 1);
            reverse(all(b));
            if (k < n / 2)
                swap(a[0], a[k]);
            else
                swap(a[0], b[n - k - 1]);
            for (int i = 0; i < n / 2; ++i)
                cout << a[i] << ' ' << b[i] << endl;
        }
        /*
         0 1 2 3
         7 6 5 4

         6 1 2 0
         7 3 5 4
         */
    }
}