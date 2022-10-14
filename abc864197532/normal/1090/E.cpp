#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 64, logN = 17, K = 90002;

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

vector <int> adj[N];
bool now_pos[N] = {};
vector <pii> ans;

int get(int i, int j) {
    return i * 8 + j;
}

void bfs(int v) {
    vector <int> dis(N, -1);
    vector <int> back(N, -1);
    queue <int> q;
    q.push(v);
    dis[v] = 0;
    while (q.size()) {
        int k = q.front(); q.pop();
        for (int u : adj[k]) if (u >= v && !~dis[u]) {
            dis[u] = dis[k] + 1;
            back[u] = k;
            q.push(u);
            if (now_pos[u]) {
                int now = u;
                vector <pii> tmp;
                while (now != v) {
                    tmp.eb(now, back[now]);
                    now = back[now];
                }
                for (pii &A : tmp) ans.pb(A);
                now_pos[u] = false;
                now_pos[v] = true;
                return;
            }
        }
    }
}

void bfs2(int v) {
    vector <int> dis(N, -1);
    vector <int> back(N, -1);
    queue <int> q;
    q.push(v);
    dis[v] = 0;
    while (q.size()) {
        int k = q.front(); q.pop();
        for (int u : adj[k]) if (u <= v && !~dis[u]) {
            dis[u] = dis[k] + 1;
            back[u] = k;
            q.push(u);
            if (now_pos[u]) {
                int now = u;
                vector <pii> tmp;
                while (now != v) {
                    tmp.eb(now, back[now]);
                    now = back[now];
                }
                for (pii &A : tmp) ans.pb(A);
                now_pos[u] = false;
                now_pos[v] = true;
                return;
            }
        }
    }
}

string to_name(int v) {
    string ans;
    ans += 'a' + v % 8;
    ans += '1' + v / 8;
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,8) fop (j,0,8) {
        int a = get(i, j);
        fop (k,0,8) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < 8 && y >= 0 && y < 8) {
                adj[a].pb(get(x, y));
            }
        }
    }
    int n;
    cin >> n;
    //n = 63;
    string s;
    bool is = false;
    fop (i,0,n) {
        cin >> s;
        now_pos[(s[0] - 'a') + (s[1] - '1') * 8] = true;
        //now_pos[i + 1] = true;
    }
    if (n >= 32) {
        n = 64 - n;
        fop (i,0,N) {
            if (now_pos[i]) now_pos[i] = false;
            else now_pos[i] = true;
        }
        is = true;
    }
    int p = 0;
    if (is) {
        FOP (i,N,N - n) if (!now_pos[i]) {
            bfs2(i);
        }
        for (pii &A : ans) swap(A.X, A.Y);
    } else {
        fop (i,0,n) if (!now_pos[i]) {
            bfs(i);
        }
    }
    cout << ans.size() << endl;
    assert(ans.size() <= 1500);
    for (pii &A : ans) {
        cout << to_name(A.X) << '-' << to_name(A.Y) << endl;
    }
}