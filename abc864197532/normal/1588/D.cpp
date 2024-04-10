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
const int mod = 998244353, N = 3001, logN = 20, K = 111, C = 7;

int chg(char c) {
    if ('a' <= c && c <= 'z')
        return c - 'a';
    return c - 'A' + 26;
}

char chgbck(int x) {
    if (x <= 25)
        return char(x + 'a');
    return char(x - 26 + 'A');
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vvv <int> pos(n, 52, 2, -1);
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            vector <bool> vis(52, false);
            for (int j = 0; j < s.length(); ++j) {
                int x = chg(s[j]);
                pos[i][x][vis[x]] = j;
                vis[x] = true;
            }
        }
        auto valid = [&](int c, int s) {
            for (int i = 0; i < n; ++i) {
                if (pos[i][c][s >> i & 1] == -1)
                    return false;
            }
            return true;
        };
        vv <int> dp(52, 1 << n, -1);
        vv <pii> rt(52, 1 << n, mp(-1, -1));
        function <void(int, int)> dfs = [&](int c, int s) {
            dp[c][s] = 0;
            for (int nxtc = 0; nxtc < 52; ++nxtc) {
                int t = 0;
                bool valid = true;
                for (int i = 0; i < n; ++i) {
                    int now = pos[i][c][s >> i & 1];
                    if (now < pos[i][nxtc][0])
                        continue;
                    else if (now < pos[i][nxtc][1])
                        t |= 1 << i;
                    else
                        valid = false;
                }
                if (valid) {
                    if (dp[nxtc][t] == -1)
                        dfs(nxtc, t);
                    if (dp[c][s] < dp[nxtc][t] + 1) {
                        dp[c][s] = dp[nxtc][t] + 1;
                        rt[c][s] = mp(nxtc, t);
                    }
                }
            }
        };
        int bestc = -1, bests = -1;
        for (int c = 0; c < 52; ++c) for (int s = 0; s < 1 << n; ++s) if (dp[c][s] == -1) {
            if (!valid(c, s))
                continue;
            dfs(c, s);
            if (bestc == -1 || dp[bestc][bests] < dp[c][s])
                bestc = c, bests = s;
        }
        if (bestc == -1 && bests == -1) {
            cout << 0 << "\n\n";
            continue;
        }
        cout << dp[bestc][bests] + 1 << '\n';
        while (bestc != -1 && bests != -1) {
            cout << chgbck(bestc);
            tie(bestc, bests) = rt[bestc][bests];
        }
        cout << '\n';
    }
}