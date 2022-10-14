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
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1000007, x = 864197532, N = 100087;
const double eps = 1e-6, Pi = 3.1415926535;

struct trie {
  trie* ch[2];
  int size;
  trie () {
    ch[0] = ch[1] = NULL;
    size = 0;
  }
  void insert(int k, int d) {
    size++;
    if (d < 0) return;
    if (k & (1 << d)) {
      if (!ch[1]) ch[1] = new trie();
      ch[1]->insert(k, d - 1);
    } else {
      if (!ch[0]) ch[0] = new trie();
      ch[0]->insert(k, d - 1);
    }
  }
  int query (int k, int d) {
    size--;
    if (d < 0) return 0;
    if (k & (1 << d)) {
      if (ch[1] && ch[1]->size > 0) {
        return ch[1]->query(k, d - 1);
      } else {
        return (1 << d) + ch[0]->query(k, d - 1);
      }
    } else {
      if (ch[0] && ch[0]->size > 0) {
        return ch[0]->query(k, d - 1);
      } else {
        return (1 << d) + ch[1]->query(k, d - 1);
      }
    }
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tmp, v;
  cin >> n;
  vector <lli> ans(N, 0), cnt(N, 0), vis(N, -1);
  fop (i,0,n) {
    cin >> tmp;
    vector <int> tm;
    queue <int> q;
    vis[tmp] = 0;
    q.push(tmp);
    while (q.size()) {
      v = q.front(); q.pop();
      tm.pb(v);
      if ((v << 1) < N && vis[v << 1] == -1) {
        vis[v << 1] = vis[v] + 1;
        q.push(v << 1);
      }
      if ((v >> 1) > 0 && vis[v >> 1] == -1) {
        vis[v >> 1] = vis[v] + 1;
        q.push(v >> 1);
      }
    }
    for (int i : tm) {
      ans[i] += vis[i];
      vis[i] = -1;
      cnt[i]++;
    }
  }
  lli anss = 1ll << 60;
  fop (i,0,N) {
    if (cnt[i] == n) anss = min(anss, ans[i]);
  }
  cout << anss << endl;
}