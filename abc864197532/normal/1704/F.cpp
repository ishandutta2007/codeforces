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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 52, logN = 18, G = 3;

map <pair <string, int>, bool> m1;

bool solve(string t, int op) {
    char goal = op ? 'B' : 'R';
    for (int i = 0; i + 1 < t.length(); ++i) {
        if (t[i] == goal || t[i + 1] == goal) {
            string tt = t;
            tt[i] = tt[i + 1] = 'W';
            if (!solve(tt, op ^ 1)) {
                return m1[{t, op}] = true;
            }
        }
    }
    return m1[{t, op}] = false;
}

int main () {
    owo;
    vector <int> sg(300);
    for (int i = 2; i < 300; ++i) {
        set <int> S;
        for (int j = 0; j <= i - 2; ++j)
            S.insert(sg[j] ^ sg[i - 2 - j]);
        for (int j = 0;; ++j) if (!S.count(j)) {
            sg[i] = j;
            break;
        }
    }
    auto get = [&](int x) {
        if (x <= 200)
            return sg[x];
        return sg[200 + (x - 200) % 34];
    };
    int t;
    cin >> t;
    while (t--) {
        int n;
        string t;
        cin >> n >> t;
        int cntr = count(all(t), 'R'), cntb = count(all(t), 'B');
        if (cntr == cntb) {
            vector <int> split = {0};
            for (int i = 0; i + 1 < t.length(); ++i) {
                if (t[i] == t[i + 1])
                    split.pb(i + 1);
            }
            split.pb(t.length());
            int xorr = 0;
            for (int i = 0; i + 1 < split.size(); ++i) {
                int l = split[i], r = split[i + 1];
                xorr ^= get(r - l);
            }
            cout << (xorr ? "Alice\n" : "Bob\n");
        } else {
            cout << (cntr < cntb ? "Bob\n" : "Alice\n");
        }
    }
}