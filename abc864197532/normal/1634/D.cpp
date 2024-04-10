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
const int mod = 998244353, N = 300005, logN = 20, K = 111;

int ask(int i, int j, int k) {
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    cin >> i;
    return i;
}

int main () {
    // owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> now(n);
        iota(all(now), 1);
        while (now.size() > 2) {
            if (now.size() == 3) {
                for (int i = 1; i <= n; ++i) if (!count(all(now), i)) {
                    now.pb(i);
                    break;
                }
            }
            int m = now.size();
            vector <int> rem;
            for (int i = 0; i < m; i += 4) {
                if (i + 4 <= m) {
                    int tmp[4];
                    tmp[0] = ask(now[i], now[i + 1], now[i + 2]);
                    tmp[1] = ask(now[i], now[i + 1], now[i + 3]);
                    tmp[2] = ask(now[i], now[i + 2], now[i + 3]);
                    tmp[3] = ask(now[i + 1], now[i + 2], now[i + 3]);
                    int mx = *max_element(tmp, tmp + 4);
                    int cnt = 0;
                    for (int i = 0; i < 4; ++i) {
                        tmp[i] = tmp[i] == mx ? 1 : 0;
                        cnt += tmp[i];
                    }
                    if (cnt == 2) {
                        if (tmp[0] && tmp[1])
                            rem.pb(now[i]), rem.pb(now[i + 1]);
                        if (tmp[0] && tmp[2]) 
                            rem.pb(now[i]), rem.pb(now[i + 2]);
                        if (tmp[0] && tmp[3])
                            rem.pb(now[i + 1]), rem.pb(now[i + 2]);
                        if (tmp[1] && tmp[2])
                            rem.pb(now[i]), rem.pb(now[i + 3]);
                        if (tmp[1] && tmp[3])
                            rem.pb(now[i + 1]), rem.pb(now[i + 3]);
                        if (tmp[2] && tmp[3])
                            rem.pb(now[i + 2]), rem.pb(now[i + 3]);
                    } else if (cnt == 3) {
                        for (int j = 0; j < 4; ++j) if (!tmp[j])
                            rem.pb(now[i + 3 - j]);
                    }
                } else {
                    while (i < m)
                        rem.pb(now[i++]);
                }
            }
            now = rem;
        }
        if (now.size() == 1)
            now.pb(now[0]);
        cout << "! " << now[0] << ' ' << now[1] << endl;
    }
}