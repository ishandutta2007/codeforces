#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

const int maxN = 1e5 + 100;

const int INF = 2e9 + 100;

int first_zero(bitset<maxN>& b, uint32_t i, uint32_t n) {
  while (i < n && b[i] == 1 && i % 32 != 0) {
    ++i;
  }

  if (i < n && b[i] == 0) {
    return i;
  }

  while (i + 32 < n && (*(reinterpret_cast<const uint32_t*>(&b) + (i / 32)) == 0xFFFFFFFFULL)) {
    i += 32;
  }

  while (i < n && b[i] == 1) {
    ++i;
  }

  if (i < n) {
    assert(b[i] == 0);
  }

  return i;
}

void solve(bool read) {
  int n, m;
  if (read) {
    cin >> n >> m;
  } else {
    //n = 1e5;
    n = rand() % 100 + 1;
    m = rand() % 5 + 1;
  }

  vector<pair<vector<int>, li>> a(n);
  for (int i = 0; i < n; ++i) {
    a[i].first.resize(m);
    for (int& x : a[i].first) {
      if (read) {
        cin >> x;
      } else {
        x = rand() % 10;
      }
    }
    if (read) {
      cin >> a[i].second;
    } else {
      a[i].second = rand() % 10;
      /*if (i + 1 < n) {
        a[i].first[0] = 1;
      }*/
    }
  }

  sort(all(a), [](const auto& lhs, const auto& rhs) {
    return lhs.second < rhs.second;
  });


  map<int, vector<int>> cnt;
  for (int i = 0; i < n; ++i) {
    for (int x : a[i].first) {
      cnt[x].push_back(i);
    }
  }

#if 0
  for (auto it : a) {
    for (auto x : it.first) {
      cout << x << " ";
    }
    cout << " => " << it.second;
    cout << "\n";
  }
  cout << "\n";
#endif

  map<int, bitset<maxN>> b_by_num;

  const int K = 700;

  for (int i = 0; i < n; ++i) {
    for (int& x : a[i].first) {
      if (cnt[x].size() > K && !b_by_num.count(x)) {
        auto& b = b_by_num[x];
        for (int j : cnt[x]) {
          b[j] = 1;
        }
      }
    }
  }

  li ans = INF;

  for (int i = 0; i < n; ++i) {
    bitset<maxN> banned{};

    for (int& x : a[i].first) {
      //cout << "num " << x << "\n";
      auto it = b_by_num.find(x);

      if (it != b_by_num.end()) {
        auto& b = it->second;
        banned |= b;
      } else {
        for (int j : cnt[x]) {
          //cout << "ban " << j << "\n";
          banned[j] = 1;
        }
      }
    }

    int j = first_zero(banned, i + 1, n);
    if (j < n) {
      //cout << "pair " << a[i].second << " " << a[j].second << "\n";

      //cout << "can: " << a[i].second + a[j].second << " with " << i << " " << j << "\n";
      ans = min<li>(ans, a[i].second + a[j].second);
    }
  }

  if (ans == INF) {
    ans = -1;
  }

  cout << ans << "\n";

#if 0
  if (!read) {
    li exp = INF;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        auto s1 = set<int>(all(a[i].first));
        auto s2 = set<int>(all(a[j].first));

        bool bad = false;
        for (int x : s1) {
          if (s2.count(x)) {
            bad = true;
            break;
          }
        }

        if (!bad) {
          if (a[i].second + a[j].second < exp) {
            cout << "exp can: " << a[i].second + a[j].second << " with " << i << " " << j << "\n";
          }
          exp = min(exp, a[i].second + a[j].second);
        }
      }
    }

    if (exp == INF) {
      exp = -1;
    }

    cout << "ans: " << ans << " exp: " << exp << endl;
    assert(ans == exp);
  }
#endif
}

int hack_b(bitset<maxN>& b, int i) {
  uint32_t w = *(reinterpret_cast<const uint32_t*>(&b) + (i / 32));
  return (w >> (i % 32)) & 1;
}

int main() {
#if 0
  bitset<maxN> b{};
  for (int i = 0; i < 1000; ++i) {
    b[i] = rand() % 2;
  }

  for (int i = 0; i < 128; ++i) {
    cout << b[i];
  }
  cout << "\n";
  for (int i = 0; i < 128; ++i) {
    cout << hack_b(b, i);
  }
  cout << "\n";
  for (int i = 0; i < 128; ++i) {
    assert(b[i] == hack_b(b, i));
  }
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  /*while (true) {
    solve(false);
  }*/

  return 0;
}