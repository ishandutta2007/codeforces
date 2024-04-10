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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 500;

int bit[N]{};

void add(int p, int v) {
  for (int i = p; i < N; i += i & (-i)) bit[i] += v;
}

int query(int p) {
  int ans = 0;
  for (int i = p; i > 0; i -= i & (-i)) ans += bit[i];
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tmp;
  cin >> n;
  int a[n];
  fop (i,0,n) cin >> tmp, a[--tmp] = i;
  lli ans_inv = 0;
  lli pre1 = 0, pre2 = 0;
  priority_queue <int> pq1;
  priority_queue <int, vector <int>, greater<int>> pq2;
  fop (i,0,n) {
    int v = a[i];
    if (i & 1) {
      if (pq1.size() && pq1.top() > v) {
        pq2.push(pq1.top());
        pre1 -= pq1.top();
        pre2 += pq1.top();
        pq1.pop();
        pq1.push(v);
        pre1 += v;
      } else {
        pq2.push(v);
        pre2 += v;
      }
    } else {
      if (pq2.size() && pq2.top() < v) {
        pq1.push(pq2.top());
        pre2 -= pq2.top();
        pre1 += pq2.top();
        pq2.pop();
        pq2.push(v);
        pre2 += v;
      } else {
        pq1.push(v);
        pre1 += v;
      }
    }
    ans_inv += query(200086) - query(v + 1);
    add(v + 1, 1);
    lli mid = pq1.top();
    cout << ans_inv + pre2 - pre1 + (i & 1 ^ 1) * mid - 1ll * (i / 2) * (i / 2 + 1) / 2 - 1ll * ((i + 1) / 2) * (((i + 1) / 2) + 1) / 2 << ' ';
  }
}