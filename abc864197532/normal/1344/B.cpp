#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
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
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, y = 111222333, N = 500;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
  int n, m, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
  cin >> n >> m;
  string in[n];
  fop (i,0,n) cin >> in[i];
  vector <int> n_a(n, -1), n_b(n, x), m_a(m, -1), m_b(m, x), count1(n, 0), count2(m, 0);
  fop (i,0,n) fop (j,0,m) {
    count1[i] += (in[i][j] == '#');
    count2[j] += (in[i][j] == '#');
    if (in[i][j] == '#') {
      n_a[i] = max(n_a[i], j);
      n_b[i] = min(n_b[i], j);
      m_a[j] = max(m_a[j], i);
      m_b[j] = min(m_b[j], i);
    }
  }
  bool is = true, is1 = false, is2 = false;
  fop (i,0,n) is &= (!count1[i] or (count1[i] == n_a[i] - n_b[i] + 1)), is1 |= !count1[i];
  fop (i,0,m) is &= (!count2[i] or (count2[i] == m_a[i] - m_b[i] + 1)), is2 |= !count2[i];
  if (!is or (is1 + is2 == 1)) {
    cout << -1 << endl;
  } else {
    bool vis[n][m];
    fop (i,0,n) fop (j,0,m) vis[i][j] = (in[i][j] == '.');
    int ans = 0, x, y;
    fop (i,0,n) fop (j,0,m) {
      if (!vis[i][j]) {
        queue <pii> q;
        q.push({i, j});
        vis[i][j] = true;
        while (q.size()) {
          tie(x, y) = q.front(); q.pop();
          fop (k,0,4) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 or nx >= n or ny < 0 or ny >=m) continue;
            if (!vis[nx][ny]) {
              q.push({nx, ny});
              vis[nx][ny] = true;
            }
          }
        }
        ans++;
      }
    }
    cout << ans << endl;
  }
}