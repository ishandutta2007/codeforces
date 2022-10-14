#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1001, logN = 18, K = 500, C = 1e9;

struct AC {
    vector <vector <int>> ch;
    vector <int> cnt, f;
    AC () {extend();}
    void extend() {
        ch.pb(vector <int>(26, 0));
        cnt.pb(0);
    }
    int next(int u, int v) {
        if (!ch[u][v]) {
            ch[u][v] = ch.size();
            extend();
        }
        return ch[u][v];
    }
    void insert(string &s, int v) {
        int now = 0;
        for (char c : s) {
            now = next(now, c - 'a');
        }
        cnt[now] += v;
    }
    void build_fail() {
        f.assign(ch.size(), 0);
        queue <int> q;
        for (int i = 0; i < 26; ++i) if (ch[0][i]) q.push(ch[0][i]);
        while (q.size()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < 26; ++i) if (ch[v][i]) {
                    int k = f[v];
                    while (k && !ch[k][i]) k = f[k];
                    if (ch[k][i]) k = ch[k][i];
                    f[ch[v][i]] = k;
                    cnt[ch[v][i]] += cnt[k];
                    q.push(ch[v][i]);
                }
        }
    }
    int match(string &s) {
        int k = 0, ans = 0;
        for (char c : s) {
            while (k && !ch[k][c - 'a']) k = f[k];
            if (ch[k][c - 'a']) k = ch[k][c - 'a'];
            ans += cnt[k];
        }
        return ans;
    }
} ac;

int solve(string s, int m, int k) {
    int n = s.length();
    int N = ac.ch.size();
    int dp[n + 1][N][k + 1][2][2]; // no 0, < 1, now 0 -> 0
    fop (i,0,n + 1) fop (j,0,N) fop (ii,0,k + 1) fop (f,0,2) fop (z,0,2) dp[i][j][ii][f][z] = 0;
    dp[0][0][0][0][0] = 1;
    fop (i,0,n) fop (j,0,N) fop (ii,0,k + 1) fop (f,0,2) fop (z,0,2) if (dp[i][j][ii][f][z]) {
        if (z) {
            char d;
            if (f) d = 'a' + m - 1;
            else d = s[i];
            for (char c = 'a'; c <= d; ++c) {
                int nj = j;
                while (nj && !ac.ch[nj][c - 'a']) nj = ac.f[nj];
                if (ac.ch[nj][c - 'a']) nj = ac.ch[nj][c - 'a'];
                int nii = ii + ac.cnt[nj], nf = 1;
                if (!f && c == d) nf = 0;
                if (nii <= k) dp[i + 1][nj][nii][nf][z] = (dp[i + 1][nj][nii][nf][z] + dp[i][j][ii][f][z]) % mod;
            }
        } else {
            char d;
            if (f) d = 'a' + m - 1;
            else d = s[i];
            for (char c = 'a'; c <= d; ++c) {
                int nj = j, nf = 1, nz = 1;
                if (!f && c == d) nf = 0;
                if (c == 'a') nz = 0;
                if (nz) {
                    if (ac.ch[nj][c - 'a']) nj = ac.ch[nj][c - 'a'];
                }
                int nii = ii + ac.cnt[nj];
                if (nii <= k) dp[i + 1][nj][nii][nf][nz] = (dp[i + 1][nj][nii][nf][nz] + dp[i][j][ii][f][z]) % mod;
            }
        }
    }
    int ans = 0;
    fop (i,0,N) fop (j,0,k + 1) fop (z,0,2) ans = (ans + dp[n][i][j][1][z]) % mod;
    return ans;
}

int ok(string s, int m, int k) {
    return ac.match(s) <= k;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, len, x;
    cin >> n >> m >> k;
    string l, r;
    cin >> len;
    fop (i,0,len) cin >> x, l.pb('a' + x);
    cin >> len;
    fop (i,0,len) cin >> x, r.pb('a' + x);
    fop (i,0,n) {
        cin >> len;
        string s;
        fop (i,0,len) cin >> x, s.pb('a' + x);
        cin >> x;
        ac.insert(s, x);
    }
    ac.build_fail();
    cout << (solve(r, m, k) - solve(l, m, k) + ok(r, m, k) + mod) % mod << endl;
}