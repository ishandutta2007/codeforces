#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int K = 20;
const int N = 5050;
const int MASK = (1 << 15) + 5;

bitset <K> vis;
ll tot[K], one[K];
map <ll, int> pos;
bitset <MASK> good, dp;
vector <ll> tmp[K], a[K];
int k, take[MASK], two[K];
pair <int, ll> start[MASK];

int main() {
  cin >> k;
  ll sum = 0;
  for (int i = 0; i < k; ++i) {
    int sz, x; cin >> sz;
    while (sz--) {
      scanf("%d", &x);
      a[i].emplace_back(x);
      sum += x;
    }
  }
  if (sum % k) {
    cout << "No\n";
    return 0;
  }
  sum /= k; 
  // int tmp_k = 0;
  // for (int i = 0; i < k; ++i) {
  //   ll cur = 0;
  //   for (auto it : tmp[i]) cur += it;
  //   if (cur == sum) continue;
  //   a[tmp_k++] = tmp[i];
  // }
  int n = k;
  for (int i = 0; i < k; ++i) {
    for (auto it : a[i]) pos[it] = i, tot[i] += it;
  }
  // cout << "yo\n";
  for (int i = 0; i < k; ++i) {
    for (auto it : a[i]) {
      ll now = it;
      int mask = 1 << i, at = i, ok = 1;
      vis.reset(); vis[i] = 1;
      while (true) {
        // cout << at << " " << now << '\n';
        ll req = sum - (tot[at] - now); 
        if (pos.find(req) == pos.end()) {
          ok = 0; break;
        }
        int nxt = pos[req];
        mask |= 1 << nxt;
        if (vis[nxt]) {
          if (nxt != i) ok = 0; 
          if (req != it) ok = 0;
          break;
        }
        vis[nxt] = 1;
        at = nxt, now = req;
      }
      if (ok) good[mask] = 1, start[mask] = make_pair(i, it);
    }
  }
  // for (int i = 0; i < 1 << n; ++i) if (good[i]) cout << i << " "; cout << endl;
  // cout << "yo\n";
  dp[0] = 1;
  for (int mask = 1; mask < 1 << n; ++mask) {
    for (int sub = mask; sub; sub = (sub - 1) & mask) {
      if (good[sub] and dp[mask ^ sub]) {
        dp[mask] = 1;
        take[mask] = sub;
        break;
      }
    }
  }
  if (!dp[(1 << n) - 1]) {
    cout << "No\n";
    return 0;
  }
  for (int i = (1 << n) - 1; i; i ^= take[i]) {
    // cout << i << " ";
    // cout << take[i] << endl;    
    int mask = take[i];
    int at = start[mask].first;
    ll now = start[mask].second;
    // cout << at << " " << now << endl;
    while (true) {
      ll req = sum - (tot[at] - now); 
      int nxt = pos[req];
      // cout << nxt << " " << req << endl;
      one[nxt] = req, two[nxt] = at;
      if (nxt == start[mask].first) {
        one[start[mask].first] = req, two[start[mask].first] = at;
        break;
      }
      at = nxt, now = req;
    }
  }
  cout << "Yes\n";
  for (int i = 0; i < k; ++i) {
    cout << one[i] << " " << two[i] + 1 << '\n';
  }
  return 0;
}