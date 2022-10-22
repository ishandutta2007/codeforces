#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

vector<vector<int>> e;

void connect_one(int u, int v, int w) {
  if (v == -1) {
    return;
  }

  //cout << "connect_one: " << u << " " << v << " " << w << "\n";

  e[u].push_back((v << 1) + w);
}

void connect_perm(vector<int> p, int t, int tt) {
  auto cmp_less = [&](int x, int y) {
    if (t == 0) {
      return x < y;
    } else {
      return x > y;
    }
  };

  auto transform = [&](int v) {
    return tt == 0 ? v : p.size() - v - 1;
  };

  //cout << "\nprocess t=" << t << " perm: "; for (int x : p) cout << x << " "; cout << "\n";

  int n = p.size();

  vector<int> greater_stack;

  vector<int> lower_stack;

  for (int i = 0; i < n; ++i) {
    while (!greater_stack.empty() && cmp_less(p[greater_stack.back()], p[i])) {
      greater_stack.pop_back();
    }

    while (!lower_stack.empty() && cmp_less(p[i], p[lower_stack.back()])) {
      lower_stack.pop_back();
    }

    //cout << p[i] << " greater_stack: "; for (int x : greater_stack) cout << x << " "; cout << " lower_stack: "; for (int x : lower_stack) cout << x << " "; cout << "\n";

    if (!greater_stack.empty()) {
      int greater_stack_from = 0;

      if (!lower_stack.empty()) {
        // find first in greater stack > lower_stack.back()

        // low: bad, high: good
        int low = -1, high = greater_stack.size();
        while (low + 1 != high) {
          int m = (low + high) / 2;
          if (greater_stack[m] < lower_stack.back()) {
            low = m;
          } else {
            high = m;
          }
        }

        greater_stack_from = high;
        //cout << "greater_stack_from: " << greater_stack_from << "\n";
      }

      if (greater_stack_from != greater_stack.size()) {
        // high .. greater_stack.size() - 1 ok
        //greater_stack_tree.connect(greater_stack_from, greater_stack.size() - 1, transform(i));
        //greater_stack_tree.connect(greater_stack_from, greater_stack_from, transform(i));
        connect_one(transform(greater_stack[greater_stack_from]), transform(i), 1);

#if 0
        for (int x = greater_stack_from; x <= greater_stack.size() - 1; ++x) {
          cout << "connect: " << i << " => " << greater_stack[x] << "\n";
        }
#endif
      }
    }

    // todo: update S
    greater_stack.push_back(i);

    lower_stack.push_back(i);
  }
}

void solve(bool read) {
  int n;
  if (read) {
    cin >> n;
  } else {
    n = 2.5e5;
  }

  e.clear();
  e.resize(n);

  vector<int> p(n);
  if (read) {
    for (int& x : p) {
      cin >> x;
      --x;
    }
  } else {
    iota(all(p), 0);
  }

  for (int t = 0; t < 2; ++t) {
    connect_perm(p, 0, t);
    connect_perm(p, 1, t);
    reverse(all(p));
  }

  vector<int> d(e.size(), -1);
  d[0] = 0;

  deque<int> q;
  q.push_back(0);

  while (!q.empty()) {
    int v = q.front();
    q.pop_front();

    for (int p : e[v]) {
      int w = p % 2;
      int u = p >> 1;

      //cout << "edge: " << v << " => " << u << " weight: " << w << "\n";

      if (d[u] == -1) {
        d[u] = d[v] + w;
        if (w == 0) {
          q.push_front(u);
        } else {
          q.push_back(u);
        }
      }
    }
  }

  //cout << "num_nodes: " << e.size() << "\n";

  cout << d[n - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}