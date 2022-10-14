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
const int mod = 998244353, N = 400005, logN = 20, K = 111;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        set <int> A, B;
        for (int i = 1; i < a; ++i)
            B.insert(i);
        A.insert(a);
        for (int i = b + 1; i <= n; ++i)
            A.insert(i);
        B.insert(b);
        bool is = true;
        if (A.size() > n / 2 || B.size() > n / 2) {
            is = false;
        }
        for (int i = 1; i <= n; ++i) if (A.count(i) && B.count(i)) {
            is = false;
        }
        if (!is) {
            cout << -1 << endl;
            continue;
        }
        for (int i = a + 1; i < b; ++i) {
            if (A.size() > B.size())
                B.insert(i);
            else
                A.insert(i);
        }
        for (int i : A)
            cout << i << ' ';
        for (int i : B)
            cout << i << ' ';
        cout << endl;
    }
}