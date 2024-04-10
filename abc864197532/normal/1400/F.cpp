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
        ch.pb(vector <int>(9, 0));
        cnt.pb(0);
    }
    int next(int u, int v) {
        if (!ch[u][v]) {
            ch[u][v] = ch.size();
            extend();
        }
        return ch[u][v];
    }
    void insert(string &s) {
        int now = 0;
        for (char c : s) {
            now = next(now, c - '1');
        }
        cnt[now]++;
    }
    void build_fail() {
        f.assign(ch.size(), 0);
        queue <int> q;
        for (int i = 0; i < 9; ++i) if (ch[0][i]) q.push(ch[0][i]);
        while (q.size()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < 9; ++i) if (ch[v][i]) {
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
            while (k && !ch[k][c - '1']) k = f[k];
            if (ch[k][c - '1']) k = ch[k][c - '1'];
            ans += cnt[k];
        }
        return ans;
    }
} ac;

void run(string s, int now, int x) {
    if (now == 0) {
        bool is = true;
        int n = s.length();
        fop (i,0,n) fop (j,i + 1,n + 1) {
            int sum = 0;
            fop (k,i,j) sum += s[k] - '0';
            if (x != sum && x % sum == 0) is = false;
        }
        if (is) ac.insert(s);
        return;
    }
    for (int i = 1; i <= 9; ++i) if (now >= i) {
        s.pb('0' + i);
        run(s, now - i, x);
        s.pop_back();
    }
}

vector <vector <int>> pre;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int x;
    cin >> s >> x;
    run("", x, x);
    ac.build_fail();
    int n = s.length();
    vector <vector <int>> dp(n + 1, vector <int>(ac.ch.size(), 1 << 30));
    dp[0][0] = 0;
    pre.assign(ac.ch.size(), vector <int>(9, -1));
    fop (i,0,n) fop (j,0,ac.ch.size()) if (dp[i][j] < (1 << 30)) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        int k = pre[j][s[i] - '1'];
        if (!~k) {
            k = j;
            while (k && !ac.ch[k][s[i] - '1']) k = ac.f[k];
            if (ac.ch[k][s[i] - '1']) k = ac.ch[k][s[i] - '1'];
        }
        if (!ac.cnt[k]) dp[i + 1][k] = min(dp[i + 1][k], dp[i][j]);
        pre[j][s[i] - '1'] = k;
    }
    int ans = 1 << 30;
    fop (i,0,ac.ch.size()) ans = min(ans, dp[n][i]);
    cout << ans << endl;
}