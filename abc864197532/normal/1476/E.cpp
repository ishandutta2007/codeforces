#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 998244353, abc = 864197532, N = 500087, logN = 20, K = 333;

struct trie {
    vector <vector <int>> ch;
    vector <int> cnt;
    trie() {extend();}
    void extend() {
        ch.pb(vector <int>(128, 0));
        cnt.pb(0);
    }
    int getnxt(int u, int c) {
        if (ch[u][c]) return ch[u][c];
        extend();
        return ch[u][c] = ch.size() - 1;
    }
    void insert(string s, int id) {
        int now = 0;
        for (char &c : s) {
            now = getnxt(now, c);
        }
        cnt[now] = id;
    }
    int query(string s) {
        int now = 0;
        for (char &c : s) {
            if (ch[now][c]) now = ch[now][c];
            else return 0;
        }
        return cnt[now];
    }
} root;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> adj(n + 1);
    vector <int> d(n + 1, 0);
    vector <string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        root.insert(s[i], i);
    }
    string t;
    for (int i = 0, x; i < m; ++i) {
        cin >> t >> x;
        for (int j = 0; j < k; ++j) {
            if (s[x][j] != '_' && s[x][j] != t[j]) {
                cout << "NO\n";
                return 0;
            }
        }
        for (int s = 0; s < 1 << k; ++s) {
            string cur = t;
            for (int i = 0; i < k; ++i) {
                if (s >> i & 1) cur[i] = '_';
            }
            int id = root.query(cur);
            if (id && id != x) {
                adj[x].pb(id);
                d[id]++;
            }
        }
    }
    queue <int> q;
    vector <int> ans;
    for (int i = 1; i <= n; ++i) if (!d[i]) q.push(i);
    while (q.size()) {
        int v = q.front(); q.pop();
        ans.pb(v);
        for (int u : adj[v]) {
            d[u]--;
            if (!d[u]) q.push(u);
        }
    }
    if (ans.size() == n) {
        cout << "YES\n";
        printv(ans);
    } else {
        cout << "NO\n";
    }
}