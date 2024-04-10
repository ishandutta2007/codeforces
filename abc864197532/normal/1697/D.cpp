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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 101, logN = 18, B = 1 << 8, M = 1 << 21;

char query1(int p) {
    cout << "? 1 " << p + 1 << endl;
    char c;
    cin >> c;
    return c;
}

int query2(int l, int r) {
    cout << "? 2 " << l + 1 << ' ' << r << endl;
    cin >> l;
    return l;
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> pos(26, -1);
    string ans;
    for (int i = 0; i < n; ++i) {
        vector <int> p;
        for (int i = 0; i < 26; ++i) if (pos[i] != -1)
            p.pb(i);
        sort(all(p), [&](int i, int j) {
            return pos[i] < pos[j];
        });
        if (query2(0, i + 1) > p.size()) {
            ans.pb(query1(i));
        } else {
            int l = 0, r = p.size();
            while (r - l > 1) {
                int m = l + r >> 1;
                if (query2(pos[p[m]], i + 1) == p.size() - m)
                    l = m;
                else
                    r = m;
            }
            ans.pb(p[l] + 'a');
        }
        pos[ans.back() - 'a'] = i;
    }
    cout << "! " << ans << endl;
}