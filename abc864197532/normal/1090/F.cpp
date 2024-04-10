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

vector <lli> ans;

int ask(int i, int j, int k) {
  cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
  cin >> i;
  return i;
}

bool check(int i, int j, int k, lli r) {
  return min({ans[i], ans[j], ans[k]}) + max({ans[i], ans[j], ans[k]}) == r;
}

void solve(int f) {
  vector <lli> num;
  fop (i,f,f+5) fop (j,i+1,f+5) fop (k,j+1,f+5) {
    num.pb(ask(i, j, k));
  }
  vector <lli> result = num, c(5);
  sort(all(num));
  c[2] = (num[0] + num[9] - num[4]) / 2;
  c[0] = num[0] - c[2];
  c[4] = num[9] - c[2];
  c[1] = num[8] - c[4];
  c[3] = num[1] - c[0];
  sort(all(c));
  do {
    fop (i,f,f+5) ans[i] = c[i - f];
    bool is = true;
    int cnt = 0;
    fop (i,f,f+5) fop (j,i+1,f+5) fop (k,j+1,f+5) {
      is &= check(i, j, k, result[cnt++]);
    }
    if (is) return;
  } while (next_permutation(all(c)));
  assert(false);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ans.resize(n);
  for (int i = 0; i < n; i += 5) solve(min(i, n - 5));
  cout << "! ";
  printv(ans);
}