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
const int mod = 1e9 + 9, N = 2005, logN = 20, K = 111;

vector <int> a = {2, 1, 4, 3};

int query(int t, int i, int j, int x) {
    cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
    cin >> x;
    return x;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> p;
        for (int i = 0; i + 1 < n; i += 2) {
            p.pb(query(2, i, i + 1, 1));
        }
        int one_pos = -1;
        if (count(all(p), 1)) {
            int i = find(all(p), 1) - p.begin();
            one_pos = i * 2;
        } else {
            if (n % 2 == 1 && query(2, n - 1, 0, 1) == 1) {
                one_pos = n - 1;
            } else {
                vector <int> pos;
                for (int i = 0; i < p.size(); ++i) if (p[i] == 2) {
                    pos.pb(i);
                }
                if (pos.size() == 2) {
                    if (query(2, pos[0] * 2 + 1, pos[1] * 2 + 1, 1) == 1) {
                        one_pos = pos[0] * 2 + 1;
                    } else {
                        one_pos = pos[1] * 2 + 1;
                    }
                } else {
                    one_pos = pos[0] * 2 + 1;
                }
            }
        }
        vector <int> ans(n);
        ans[one_pos] = 1;
        for (int j = 0; j < n; ++j) if (j != one_pos) {
            ans[j] = query(1, one_pos, j, n - 1);
        }
        cout << "! ";
        for (int j = 0; j < n; ++j) cout << ans[j] << ' ';
        cout << endl;
    }
}