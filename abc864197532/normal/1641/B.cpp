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
const int mod = 1e9 + 7, N = 200005, logN = 18, K = 1 << 8, G = 3;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        map <int, int> cnt;
        for (int i = 0; i < n; ++i) 
            cin >> a[i], cnt[a[i]] ^= 1;
        bool fail = false;
        for (pii A : cnt)
            fail |= A.Y > 0;
        if (fail) {
            cout << -1 << endl;
            continue;
        }
        vector <pii> op;
        vector <int> len;
        int now = 0;
        while (!a.empty()) {
            int x = a[0];
            int p = -1;
            for (int i = 1; i < a.size(); ++i) if (a[i] == x) {
                p = i;
                break;
            }
            assert(p != -1);
            for (int j = 1; j < p; ++j) {
                op.eb(now + p + j, a[j]);
            }
            reverse(a.begin() + 1, a.begin() + p + 1);
            a.erase(a.begin());
            a.erase(a.begin());
            now += p * 2;
            len.pb(p * 2);
        }
        cout << op.size() << '\n';
        for (pii A : op)
            cout << A.X << ' ' << A.Y << '\n';
        cout << len.size() << '\n';
        printv(all(len));
    }
}