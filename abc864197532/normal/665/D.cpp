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
const int mod = 998244353, N = 300001, logN = 20, K = 15;

bool prime[2000001];

int main () {
    owo;
    for (int i = 2; i <= 2000000; ++i) if (!prime[i]) {
        for (int j = i + i; j <= 2000000; j += i) {
            prime[j] = true;
        }
    }
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1)
            p.pb(i);
    }
    if (p.size() >= 2) {
        for (int i = 0; i < n; ++i) if (a[i] != 1 && !prime[1 + a[i]]) {
            cout << p.size() + 1 << endl;
            for (int i : p)
                cout << 1 << ' ';
            cout << a[i] << endl;
            return 0;
        }
        cout << p.size() << endl;
        for (int i : p)
            cout << 1 << ' ';
        cout << endl;
    } else {
        for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (!prime[a[i] + a[j]]) {
            cout << 2 << endl << a[i] << ' ' << a[j] << endl;
            return 0;
        }
        cout << 1 << endl << a[0] << endl;
    }
}