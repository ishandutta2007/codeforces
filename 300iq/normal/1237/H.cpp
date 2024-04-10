#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ts;
  cin >> ts;
  while (ts--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    map <string, int> cnt;
    for (int i = 0; i < n; i += 2) {
      string cur = "";
      cur += s[i];
      cur += s[i + 1];
      sort(cur.begin(), cur.end());
      cnt[cur]++;
    }
    for (int i = 0; i < n; i += 2) {
      string cur = "";
      cur += t[i];
      cur += t[i + 1];
      sort(cur.begin(), cur.end());
      cnt[cur]--;
    }
    bool bad = false;
    for (auto c : cnt) {
      if (c.second != 0) {
        bad = true;
      }
    }
    if (bad) {
      cout << -1 << '\n';
      continue;
    }
    while (true) {
      int start = rnd() % (n / 2 + 1);
      vector <int> ord;
      if (start != 0) {
        ord.push_back(start - 1);
      }
      string cur = s, me = t;
      reverse(cur.begin(), cur.begin() + 2 * start);
      int its = 0;
      bool bad = false;
      while (cur.size() > 0) {
        int ind = (int) me.size() - 2;
        vector <int> sh;
        for (int i = (int) cur.size() - 2; i >= 0; i -= 2) {
          sh.push_back(i);
        }
        shuffle(sh.begin() + 1, sh.end(), rnd);
        bool mda = false;
        for (int i : sh) {
          if (cur[i] == me[ind] && cur[i + 1] == me[ind + 1]) {
            if (i + 2 != (int) cur.size()) {
              ord.push_back(i / 2);
              reverse(cur.begin(), cur.begin() + i + 2);
              ord.push_back(ind / 2);
              reverse(cur.begin(), cur.end());
            }
            mda = true;
            break;
          }
        }
        if (!mda) {
          vector <int> sh;
          for (int i = 0; i < (int) cur.size(); i += 2) {
            sh.push_back(i);
          }
          shuffle(sh.begin(), sh.end(), rnd);
          for (int i : sh) {
            if (cur[i] == me[ind + 1] && cur[i + 1] == me[ind]) {
              ord.push_back(i / 2);
              reverse(cur.begin(), cur.begin() + i + 2);
              ord.push_back(0);
              reverse(cur.begin(), cur.begin() + 2);
              ord.push_back(ind / 2);
              reverse(cur.begin(), cur.end());
              break;
            }
          }
        }
        if (ord.size() > n + 1) {
          bad = true;
          break;
        }
        for (int it = 0; it < 2; it++) {
          cur.pop_back(), me.pop_back();
        }
      }
      if (bad) {
        continue;
      } else {
        cout << ord.size() << '\n';
        string f = s, g = t;
        for (int a : ord) {
          cout << 2 * (a + 1) << ' ';
        }
        cout << '\n';
        break;
      }
    }
  }
  /*
  while (true) {
    int n = 4000;
    string s = "";
    for (int i = 0; i < n; i++) {
      s += (rnd() % 2 + '0');
    }
    string t = s;
    for (int i = 0; i < n; i += 2) {
      if (rnd() % 2) {
        swap(s[i], s[i + 1]);
      }
    }
    for (int i = 0; i < n; i += 2) {
      int j = rnd() % (i / 2 + 1);
      swap(s[i], s[2 * j]);
      swap(s[i + 1], s[2 * j + 1]);
    }
    bool good = false;
    for (int start = 0; start <= n; start += 2) {
      string cur = s;
      reverse(cur.begin(), cur.begin() + start);
      string me = t;
      
      if (its <= (int) s.size() + 1) {
        good = true;
        break;
      }
    }
    if (!good) {
      cout << s << ' ' << t << endl;
      assert(0);
    }
    cout << s << ' ' << t << endl;
  }
  */
  /*
  for (int n = 2; n <= 10; n += 2) {
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
    set <vector <int> > q;
    map <vector <int>, int> dist;
    dist[p] = 0;
    q.insert(p);
    for (int it = 0; it < n + 10; it++) {
      auto nq = q;
      for (auto c : q) {
        for (int len = 2; len <= n; len += 2) {
          auto t = c;
          reverse(t.begin(), t.begin() + len);
          if (!dist.count(t)) {
            dist[t] = dist[c] + 1;
          }
          nq.insert(t);
        }
      }
      q = nq;
    }
    int mx = 0;
    for (auto p : dist) mx = max(mx, p.second);
    cout << n << ' ' << q.size() << ' ' << mx << endl;
  }
  */
}