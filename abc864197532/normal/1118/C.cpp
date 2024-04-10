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
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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

const int mod = 998244353, x = 864197532, N = 200087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    vector <int> cnt(1001, 0);
    fop (i,0,n * n) cin >> tmp, cnt[tmp]++;
    if (n & 1) {
        vector <int> one, two, four;
        fop (i,0,1001) {
            if (cnt[i] & 1) one.pb(i), cnt[i]--;
            while (cnt[i] >= 4) {
                four.pb(i);
                cnt[i] -= 4;
            }
            if (cnt[i] == 2) {
                two.pb(i);
            }
        }
        if (one.size() > 1 || four.size() < (n / 2) * (n / 2)) cout << "NO\n";
        else {
            cout << "YES\n";
            int ans[n / 2][n / 2];
            int i = 0, j = 0;
            while (i < n / 2) {
                ans[i][j] = four.back(); four.pop_back();
                j++;
                if (j == n / 2) i++, j = 0;
            }
            while (four.size()) {
                two.pb(four.back());
                two.pb(four.back());
                four.pop_back();
            }
            fop (i,0,n) fop (j,0,n) {
                int a = i, b = j;
                a = min(a, n - a - 1);
                b = min(b, n - b - 1);
                if (a == n / 2 && b == n / 2) cout << one[0];
                else if (a == n / 2) cout << two[b];
                else if (b == n / 2) cout << two[n / 2 + a];
                else cout << ans[a][b];
                cout << " \n"[j == n - 1];
            }
        }
    } else {
        bool is = true;
        fop (i,0,1001) is &= cnt[i] % 4 == 0;
        if (is) {
            cout << "YES\n";
            int a[n / 2][n / 2];
            int i = 0, j = 0;
            fop (k,0,1001) {
                while (cnt[k]) {
                    a[i][j] = k;
                    cnt[k] -= 4;
                    j++;
                    if (j == n / 2) i++, j = 0;
                }
            }
            fop (i,0,n) fop (j,0,n) {
                int aa = i, b = j;
                aa = min(aa, n - aa - 1);
                b = min(b, n - b - 1);
                cout << a[aa][b] << " \n"[j == n - 1];
            }
        } else {
            cout << "NO\n";
        }
    }
}