#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 998244353;

unordered_map<string, bool> wins;

bool get_wins(string s, char cur) {
  auto p = s + cur;
  if (!wins.count(p)) {
    wins[p] = false;

    for (int i = 0; i + 1 < s.size(); ++i) {
      if (s[i] == cur || s[i + 1] == cur) {
        string xs = s;
        xs[i] = xs[i + 1] = '.';
        char other = (cur == 'B' ? 'R' : 'B');
        if (!get_wins(xs, other)) {
          wins[p] = true;
          break;
        }
      }
    }
  }
  return wins[p];
}

vector<int> xf;

int get_xf(int l) {
  if (l < 100) {
    return xf[l];
  } else {
    int D = (l - 100) / 34;
    l -= D * 34;
    return xf[l];
  }
}

void solve(bool read) {
  if (xf.empty()) {
    xf.resize(500);

    xf[0] = xf[1] = 0;
    for (int t = 2; t < xf.size(); ++t) {
      set<int> mex;

      for (int l = 0; l <= t - 2; ++l) {
        int a = l;
        int b = t - 2 - l;
        mex.insert(xf[a] ^ xf[b]);
      }

      for (int l = 0; l < mex.size() + 2; ++l) {
        if (!mex.count(l)) {
          xf[t] = l;
          break;
        }
      }
    }
  }

#if 0


  for (int t = 0; t < xf.size(); ++t) {
    assert(get_xf(t) == xf[t]);
  }


  int L = 14;

  map<vector<int>, bool> wins_by_a;

  for (int m = 0; m < (1 << L); ++m) {
    for (int m1 = m; m1 > 0; m1 = (m1 - 1) & m) {
      string s(L, '.');
      for (int i = 0; i < L; ++i) {
        if (m & (1 << i)) {
          if (m1 & (1 << i)) {
            s[i] = 'R';
          } else {
            s[i] = 'B';
          }
        }
      }
      if (count(all(s), 'R') != count(all(s), 'B')) {
        continue;
      }
      if (count(all(s), '.') != 0) {
        continue;
      }

      int cnt_rb = 0;
      for (int i = 0; i + 1 < L; ++i) {
        if ((s[i] == 'R' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'R')) {
          ++cnt_rb;
        }
      }

      auto diff = [&](int i) {
        return (s[i] == 'R' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'R');
      };

      vector<int> a;
      for (int i = 0; i < L;) {
        int r = i;
        while (r + 1 < L && diff(r)) {
          ++r;
        }

        if (r > i) {
          a.push_back(r - i + 1);
        }

        i = r + 1;
      }

      bool first_wins = get_wins(s, 'R');

      //  << " " << cnt_rb
      sort(all(a));
      cout << s << ": " << (first_wins ? "first" : "second") << " a: ";
      for (int x : a) cout << x << " ";
      cout << endl;

      if (!wins_by_a.count(a)) {
        wins_by_a[a] = first_wins;
      } else {
        assert(wins_by_a[a] == first_wins);
      }

      int res = 0;
      for (int x : a) {
        res ^= get_xf(x);
      }
      assert(first_wins == (res != 0));

      /*if (cnt_rb % 2 == 1) {
        assert(first_wins);
      } else {
        assert(!first_wins);
      }*/

      if (count(all(s), 'R') < count(all(s), 'B')) {
        assert(!first_wins);
      }
      if (count(all(s), 'R') > count(all(s), 'B')) {
        assert(first_wins);
      }
    }
  }

  for (int t = 0; t < 10; ++t) {
    cout << t << ": " << xf[t] << "\n";
  }

  cout << "FIRST:\n";
  for (auto it : wins_by_a) {
    if (it.second) {
      for (int x : it.first) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
  cout << "\n";

  cout << "SECOND:\n";
  for (auto it : wins_by_a) {
    if (!it.second) {
      for (int x : it.first) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
#endif

  int n;
  string s;
  cin >> n >> s;

  auto get_first_wins = [&]() {
    if (count(all(s), 'R') < count(all(s), 'B')) {
      return false;
    }
    if (count(all(s), 'R') > count(all(s), 'B')) {
      return true;
    }


    auto diff = [&](int i) {
      return (s[i] == 'R' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'R');
    };

    vector<int> a;
    for (int i = 0; i < s.size();) {
      int r = i;
      while (r + 1 < s.size() && diff(r)) {
        ++r;
      }

      if (r > i) {
        a.push_back(r - i + 1);
      }

      i = r + 1;
    }

    int res = 0;
    for (int x : a) {
      res ^= get_xf(x);
    }
    return (res != 0);
  };

  //char first_wins = get_wins(s, 'R');
  auto first_wins = get_first_wins();
  cout << (first_wins ? "Alice" : "Bob") << "\n";
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