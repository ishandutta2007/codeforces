#include <bits/stdc++.h>

using namespace std;

using li = long long;

#define all(v) (v).begin(), (v).end()

void solve(bool read) {
  int n;

  if (read) {
    cin >> n;
  } else {
    n = rand() % 10 + 1;
    //n = 11;
  }

  vector<int> p(n), q(n), z(n);

  if (read) {
    for (int& x : p) {
      cin >> x;
      --x;
    }
    for (int& x : q) {
      cin >> x;
      --x;
    }
    for (int i = 0; i < n; ++i) {
      z[p[i]] = q[i];
    }
  } else {
    iota(all(z), 0);
    random_shuffle(all(z));
  }

  int mx = n, mn = 1;

  int odd = 0;
  int mid_0 = (n + 1) / 2;
  int mid_1 = (n + 1) / 2 + 1;

  vector<bool> used(n);
  vector<int> loops;

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;

    vector<int> loop;

    int x = i;
    while (!used[x]) {
      used[x] = true;
      x = z[x];
      loop.push_back(x);
    }
    loops.push_back(loop.size());
  }

  sort(all(loops));
  //reverse(all(loops));

  li ans = 0;
  for (int l : loops) {
    if (l == 1) continue;

    vector<int> place;
    for (int t = 0; t < l; ++t) {
      if (t == l - 1 && l % 2 == 1) {
        if (odd % 2 == 0) {
          place.push_back(mid_0);
          --mid_0;
        } else {
          place.push_back(mid_1);
          ++mid_1;
        }
        ++odd;
        continue;
      }

      if (t % 2 == 0) {
        place.push_back(mx);
        --mx;
      } else {
        place.push_back(mn);
        ++mn;
      }
    }

    for (int i = 0; i < place.size(); ++i) {
      ans += abs(place[i] - place[(i + 1) % place.size()]);
    }
  }

  cout << ans << "\n";

  if (!read) {
    int exp = 0;
    vector<int> exp_v;

    vector<int> v(n);
    iota(all(v), 0);

    do {
      int s = 0;
      for (int i = 0; i < n; ++i) {
        s += abs(v[i] - v[z[i]]);
      }

      if (s > exp) {
        exp = s;
        exp_v = v;
      }
    }
    while (next_permutation(all(v)));

    cout << "loops: ";
    for (int l : loops) {
      cout << l << " ";
    }
    cout << endl;

    cout << "expected: " << exp << endl;
    assert(ans == exp);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //while (true) solve(false);

  return 0;
}