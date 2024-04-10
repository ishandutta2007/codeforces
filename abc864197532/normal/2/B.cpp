#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

// AC automaton will help me get AC!
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
    void insert(string &s) {
        int now = 0;
        for (char c : s) {
            now = next(now, c - 'a');
        }
        cnt[now]++;
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
};

const int mod = 1e9 + 7, x = 864197532, N = 2000087, logN = 17;

string ans;

int solve(vector <vector <int>> a, bool is = false) {
    int n = a.size();
    vector <vector <int>> dp(n, vector <int> (n, 0)), back(n, vector <int>(n, -1));
    fop (i,0,n) fop (j,0,n) {
        if (i - 1 >= 0 && j - 1 >= 0) {
            if (dp[i - 1][j] > dp[i][j - 1]) dp[i][j] = dp[i][j - 1], back[i][j] = 1;
            else dp[i][j] = dp[i - 1][j], back[i][j] = 0;
        } else if (i - 1 >= 0) dp[i][j] = dp[i - 1][j], back[i][j] = 0;
        else if (j - 1 >= 0) dp[i][j] = dp[i][j - 1], back[i][j] = 1;
        dp[i][j] += a[i][j];
    }
    if (is) {
        int i = n - 1, j = n - 1;
        while (i || j) {
            if (back[i][j] == 0) ans.pb('D'), i--;
            else ans.pb('R'), j--;
            assert(i >= 0 && j >= 0);
        }
    }
    reverse(all(ans));
    return dp[n - 1][n - 1];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n, 0)), b(n, vector <int>(n, 0));
    pii pos = {-1, -1};
    fop (i,0,n) fop (j,0,n) {
        cin >> tmp;
        if (!tmp) {pos = {i, j}, a[i][j] = b[i][j] = 10000; continue;}
        while (tmp % 2 == 0) a[i][j]++, tmp /= 2;
        while (tmp % 5 == 0) b[i][j]++, tmp /= 5;
    }
    int A = solve(a), B = solve(b);
    if (A == 0) {
        solve(a, true);
        cout << 0 << endl;
    } else if (B == 0) {
        solve(b, true);
        cout << 0 << endl;
    } else {
        if (pos.X == -1) {
            if (A < B) solve(a, true);
            else solve(b, true);
            cout << min(A, B) << endl;
        } else {
            int i = 0, j = 0;
            while (i < pos.X) {
                ans.pb('D');
                i++;
            }
            while (j < pos.Y) {
                ans.pb('R');
                j++;
            }
            while (i < n - 1) {
                ans.pb('D');
                i++;
            }
            while (j < n - 1) {
                ans.pb('R');
                j++;
            }
            cout << 1 << endl;
        }
    }
    cout << ans << endl;
}