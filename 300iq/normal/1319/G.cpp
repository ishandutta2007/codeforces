#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> ms = {(int) (1e9 + 7), (int) (1e9 + 9), (int) (998244353)};
vector <int> bs;

struct hash_str {
  vector <int> h[3], p[3];
  hash_str(vector <pair <int, int> > e) {
    if (!e.empty()) {
      for (int i = 0; i < 3; i++) {
        h[i].resize(e.size());
        p[i].resize(e.size());
        h[i][0] = e[0].second + 1;
        p[i][0] = 1;
        for (int j = 1; j < (int) e.size(); j++) {
          h[i][j] = (h[i][j - 1] * (ll) bs[i] + e[j].second + 1) % ms[i];
          p[i][j] = (p[i][j - 1] * (ll) bs[i]) % ms[i];
        }
      }
    }
  }
  string get(int l, int r) {
    string s = "";
    for (int i = 0; i < 3; i++) {
      int hsh = 0;
      if (!l) {
        hsh = h[i][r];
      } else {
        hsh = h[i][r] - (h[i][l - 1] * (ll) p[i][r - l + 1]) %  ms[i];
        if (hsh < 0) hsh += ms[i];
      }
      s += to_string(hsh);
    }
    return s;
  }
};

int main() {
#ifdef iq
	freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rnd(time(0));
  string s = "asdasdasdfafdsfahfdashfdashfdashdahfkljdhsfkljdhasfhdsshfjdashfhyruyqrweyruoqewyryqew";
  for (int i = 0; i < (int) s.size(); i++) rnd();
  for (int i = 0; i < 3; i++) {
    if (i == 0) {
      string s = "asdasdasfdasfdasfhdasjhfvhfhfdlashfdashvkljdashfdashfjdhaskljfhfhhfshfkljashfkljdashhfdaslfhdasyhfryupwyerupqhqwurqewyewpuirhfasjfkldhsfkljdhsjflashduyfuqew  ory        \n        21321321  ";
      int x = rnd() % 256;
      for (auto c : s) {
        x += c;
      }
      x %= 256;
      bs.push_back(x + 200);
    } else {
      bs.push_back((bs.back() * 12345 + rnd() % 23) % 256 + 200);
    }
  }//yes I forgot how to write a good random
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector <pair <int, int> > a, b;
  int chet = 0;
  vector <int> p(n);
  for (int i = 0; i < (int) t.size(); i++) {
    if (t[i] == '1') chet ^= 1;
    p[i] = chet;
    if (t[i] == '0') {
      a.push_back({i, chet});
      b.push_back({i, chet ^ 1});
    }
  }
  hash_str x(a);
  hash_str y(b);
  int q;
  cin >> q;
  auto f_a = [&] (int l, int r) {
    return x.get(l, r);
  };
  auto f_b = [&] (int l, int r) {
    return y.get(l, r);
  };
  auto get = [&] (int l, int r, int chet) {
    int x = -1, y = -1;
    {
      int vl = -1, vr = (int) a.size();
      while (vl < vr - 1) {
        int vm = (vl + vr) / 2;
        if (a[vm].first < l) {
          vl = vm;
        } else {
          vr = vm;
        }
      }
      x = vl + 1;
    }
    {
      int vl = -1, vr = (int) a.size();
      while (vl < vr - 1) {
        int vm = (vl + vr) / 2;
        if (a[vm].first <= r) {
          vl = vm;
        } else {
          vr = vm;
        }
      }
      y = vl;
    }
    if (x > y) {
      string s = "";
      return make_pair(0, s);
    } else {
      if (!chet)
        return make_pair(y - x + 1, f_a(x, y));
      else
        return make_pair(y - x + 1, f_b(x, y));
    }
  };
  auto f = [&] (int l, int r) {
    if (l && p[l - 1]) return get(l, r, 1);
    else return get(l, r, 0);
  };
  while (q--) {
    int l1, l2, len;
    cin >> l1 >> l2 >> len;
    l1--, l2--;
    if (f(l1, l1 + len - 1) != f(l2, l2 + len - 1)) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}