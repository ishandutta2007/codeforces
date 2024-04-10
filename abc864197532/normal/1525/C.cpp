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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
#define test(args...) info(), abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
const int mod = 998244353, N = 1000001 / 3, logN = 20, K = 111;

struct robot {
    int x, id;
    char c;
    bool operator < (const robot &o) {
        return x < o.x;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        char c;
        cin >> n >> m;
        vector <robot> a[2];
        vector <int> tmp(n);
        for (int i = 0; i < n; ++i) cin >> tmp[i];
        for (int i = 0; i < n; ++i) cin >> c, a[tmp[i] & 1].pb({tmp[i], i, c});
        vector <int> ans(n, 1 << 30);
        for (int t : {0, 1}) {
            sort(all(a[t]));
            vector <pii> right, left;
            for (auto &i : a[t]) {
                if (i.c == 'R') {
                    right.eb(i.x, i.id);
                } else if (!right.empty()) {
                    pii A = right.back(); right.pop_back();
                    ans[A.Y] = ans[i.id] = (i.x - A.X) / 2;
                } else {
                    left.eb(i.x, i.id);
                }
            }
            reverse(all(right));
            for (int i = 0; i + 1 < right.size(); i += 2) {
                ans[right[i].Y] = ans[right[i + 1].Y] = (m * 2 - right[i].X - right[i + 1].X) / 2;
            }
            for (int i = 0; i + 1 < left.size(); i += 2) {
                ans[left[i].Y] = ans[left[i + 1].Y] = (left[i].X + left[i + 1].X) / 2;
            }
            if (int(left.size()) & 1 && int(right.size()) & 1) {
                ans[right.back().Y] = ans[left.back().Y] = (m * 2 - (right.back().X - left.back().X)) / 2;
            }
        }
        for (int &i : ans) if (i == 1 << 30) i = -1;
        printv(all(ans));
    }
}