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
const int mod = 1e9 + 7, N = 202, logN = 20, K = 31;

int main () {
    owo;
    int n;
    cin >> n;
    vector <string> s(3);
    for (int i = 0; i < 3; ++i)
        cin >> s[i];
    vector <int> w(n + 1), edge(n + 1);
    for (int i = 0; i < n; ++i) {
        w[i + 1] = w[i] + (s[0][i] == '0') + (s[1][i] == '0') + (s[2][i] == '0');
        edge[i + 1] = edge[i] + (s[0][i] == '0' || s[1][i] == '0') + (s[1][i] == '0' || s[2][i] == '0');
    }
    vector <int> edge2(n);
    for (int i = 1; i < n; ++i) {
        edge2[i] = edge2[i - 1];
        for (int j : {0, 1, 2})
            edge2[i] += s[j][i - 1] == '0' || s[j][i] == '0';
    }
    vector <pii> pt;
    for (int j = 1; j < n; ++j) for (int i : {1, 2}) {
        if (s[i - 1][j - 1] == '0' || s[i - 1][j] == '0' || s[i][j - 1] == '0' || s[i][j] == '0')
            pt.emplace_back(j, i);
    }
    vector <int> cc(n);
    vector <bool> vis(n, false);
    vector <int> split;
    vector <pii> range;
    for (int i = 0; i < n; ++i) {
        if (s[0][i] == '1' && s[1][i] == '1' && s[2][i] == '1') {
            split.pb(i);
        }
    }
    for (int i = 0; i + 1 < split.size(); ++i) {
        int l = split[i], r = split[i + 1];
        bool is = true;
        for (int k = l + 1; k < r; ++k)
            is &= s[0][k] == '1' && s[1][k] == '0' && s[2][k] == '1';
        if (is && r - l >= 2)
            range.eb(l + 1, r - 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r, --l;
        int V = lower_bound(all(pt), mp(r, -1)) - lower_bound(all(pt), mp(l + 1, -1)) + 8 + (r - l - 1) * 2;
        int E = edge[r] - edge[l] + edge2[r - 1] - edge2[l] + 6 + (r - l) * 2;
        auto it1 = lower_bound(all(range), mp(l + 1, -1));
        auto it2 = lower_bound(all(range), mp(r - 1, -1));
        if (it2 != range.begin() && prev(it2)->Y >= r - 1)
            it2--;
        int C = r - l >= 3 ? max(it2 - it1, 0) + 1 : 1;
        test(C);
        cout << C + E - V - (w[r] - w[l]) << '\n';
    }
}