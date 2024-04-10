#include <iostream>
#include <vector>

using namespace std;

struct Group {
  vector<int> a, b;

  Group () : a(0), b(0) {
  }
  
  bool can_split (int bit) const {
    int cnt = 0;
    
    for (int u : a) {
      if (u & 1 << bit) {
        cnt++;
      }
    }

    for (int v : b) {
      if (!(v & 1 << bit)) {
        cnt--;
      }
    }

    return cnt == 0;
  }

  pair<Group, Group> split (int bit) const {
    Group G, H;

    for (int u : a) {
      if (u & 1 << bit) {
        G.a.push_back(u);
      } else {
        H.a.push_back(u);
      }
    }

    for (int v : b) {
      if (v & 1 << bit) {
        H.b.push_back(v);
      } else {
        G.b.push_back(v);
      }
    }

    return make_pair(G, H);
  }
};

void solve () {
  int n;
  cin >> n;

  vector<int> a (n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b (n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  vector<Group> grps (1);
  grps[0].a = a;
  grps[0].b = b;

  int ans = 0;
  for (int k = 29; k >= 0; k--) {
    bool can = true;
    for (const auto &g : grps) {
      if (!g.can_split(k)) {
        can = false;
        break;
      }
    }

    if (can) {
      ans += 1 << k;
      vector<Group> nxt;
      for (const auto &g : grps) {
        auto pr = g.split(k);
        if (!pr.first.a.empty())
          nxt.push_back(pr.first);
        if (!pr.second.a.empty())
          nxt.push_back(pr.second);
      }

      grps = nxt;
    }
  }

  cout << ans << '\n';
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