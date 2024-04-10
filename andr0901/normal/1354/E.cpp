#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <vector <int>> gr;
vector <int> used, cur_cnt;

void no() {
    cout << "NO";
    exit(0);
}

void dfs(int v, int turn = 0) {
    used[v] = turn;
    cur_cnt[turn]++;
    for (int u : gr[v]) {
        if (used[u] == turn)
            no();
        if (used[u] == -1)
            dfs(u, turn ^ 1);
    }
}

vector <int> ans, cnt;

void dfs2(int v, int parity, int turn = 0) {
    used[v] = turn;
    if (turn == parity) {
        ans[v] = 2;
    } else {
        if (cnt[0]) {
            ans[v] = 1;
            cnt[0]--;
        } else {
            ans[v] = 3;
        }
    }
    for (int u : gr[v])
        if (used[u] == -1)
            dfs2(u, parity, turn ^ 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    cnt.resize(3);
    cin >> cnt;
    gr.resize(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    used.resize(n, -1);
    vector <vector <int>> a;
    forn (i, 0, n) {
        if (used[i] == -1) {
            cur_cnt = vector <int> (2);
            dfs(i);
            a.pb(cur_cnt);
        }
    }
    vector <vector <int>> dp(sz(a) + 1, vector <int> (cnt[1] + 1, -1));
    dp[0][0] = -2;
    forn (i, 0, sz(a)) {
        //cout << a[i] << "\n";
        forn (j, 0, cnt[1] + 1)
            forn (k, 0, 2)
                if (dp[i][j] != -1 && j + a[i][k] < cnt[1] + 1 && dp[i + 1][j + a[i][k]] == -1)
                    dp[i + 1][j + a[i][k]] = k;
    }
    if (dp[sz(a)][cnt[1]] == -1)
        no();
    vector <int> restored(sz(a));
    int i = sz(a), j = cnt[1];
    while (i) {
        restored[i - 1] = dp[i][j];
        j -= a[i - 1][dp[i][j]];
        --i;
    }
    //cout << restored << "/n";
    used = vector <int> (n, -1);
    ans.resize(n);
    j = 0;
    forn (i, 0, n) {
        if (used[i] == -1) {
            dfs2(i, restored[j++]);
        }
    }
    cout << "YES\n";
    forn (i, 0, n)
        cout << ans[i];
    return 0;
}