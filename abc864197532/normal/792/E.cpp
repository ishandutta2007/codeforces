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
const int mod = 998244353, N = 100005, logN = 20, M = 6e6;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mnn = *min_element(all(a));
    vector <int> poss; // x and x - 1
    int sq = sqrt(1000000087) + 5;
    for (int i = 2; i <= sq; ++i)
        poss.pb(i);
    for (int i = 1; i <= min(a[0] - 1, sq); ++i) {
        if (a[0] % i == 0)
            poss.pb(a[0] / i);
        poss.pb(a[0] / i + 1);
    }
    sort(all(poss)), poss.resize(unique(all(poss)) - poss.begin());
    lli ans = accumulate(all(a), 0ll);
    for (int x : poss) {
        lli tmp = 0;
        for (int c : a) {
            int res = (c + x - 1) / x;
            if ((x - 1) * res > c)
                tmp = 1ll << 60;
            tmp += res;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}