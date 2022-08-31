#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const int VZ = 1e7;

class Fenwick {
  int id;
  vector<int> tree;
  
public:
  Fenwick (int n, int _id) : id(_id), tree(n + 5, _id) {}
  
  void set (int pos, int val) {
    pos++;
    
    for (int i = pos; i < (int) tree.size(); i += i & -i) {
      tree[i] = max(tree[i], val);
    }
  }

  int get (ll pos) {
    pos++;
    
    int ans = id;
    for (ll i = pos; i > 0; i -= i & -i) {
      ans = max(ans, tree[i]);
    }
    return ans;
  }
};

const int MAX_N = 5e5 + 5;

ll arr [MAX_N];
ll pref [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + arr[i];
  }

  map<ll, int> compr;
  for (int i = 0; i <= n; i++) {
    compr[pref[i]] = 0;
  }

  {
    int cur = 0;
    for (auto it = compr.begin(); it != compr.end(); it++) {
      it->second = cur;
      cur++;
    }
  }

  for (int i = 0; i <= n; i++) {
    pref[i] = compr[pref[i]];
  }

  Fenwick pos (n, -VZ), neg (n, -VZ);
  map<ll, int> neu;
  
  int cur = 0;
  pos.set(pref[0], cur);
  neg.set(n - pref[0], cur);
  neu[pref[0]] = cur + VZ;
  
  for (int i = 1; i <= n; i++) {
    cur = max(i + pos.get(pref[i] - 1), -i + neg.get(n - pref[i] + 1));
    cur = max(cur, neu[pref[i]] - VZ);
    
    pos.set(pref[i], cur - i);
    neg.set(n - pref[i], cur + i);
    neu[pref[i]] = max(neu[pref[i]], cur + VZ);
  }

  cout << cur << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}