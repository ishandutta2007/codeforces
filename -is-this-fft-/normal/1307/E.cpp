#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () const {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) const {
    return val == other.val;
  }

  bool operator!= (Modint other) const {
    return val != other.val;
  }
};

Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_N = 5e3 + 5;

vector<int> sweetn [MAX_N];
vector<pair<int, int>> groups [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;

    sweetn[s].push_back(i);
  }

  for (int i = 0; i < m; i++) {
    int fav, hun;
    cin >> fav >> hun;

    if (hun <= (int) sweetn[fav].size()) {
      int l = sweetn[fav][hun - 1];
      int r = sweetn[fav][(int) sweetn[fav].size() - hun];
      groups[fav].push_back(make_pair(l, r));
    }
  }

  int maxs = 0;
  Modint ans (0);
  for (int i = 1; i <= n; i++) {
    for (auto pr : groups[i]) {
      int maxl = pr.first;

      // cerr << maxl << endl;
      
      Modint ways (1);
      int curs = 0;
      for (int j = 1; j <= n; j++) {
        int cl = 0;
        int cr = 0;
        int cew = 0;
        int csp = 0;
        for (auto cow : groups[j]) {
          if (cow == pr) {
            csp++;
          } else if (cow.first <= maxl && cow.second <= maxl) {
            cl++;
          } else if (cow.first > maxl && cow.second > maxl) {
            cr++;
          } else if (cow.first <= maxl && cow.second > maxl) {
            cew++;
          }
        }

        // cerr << cl << " " << cr << " " << cew << " " << csp << endl;

        if (csp) {
          if (cr + cew >= 1) {
            curs += 2;
            ways *= Modint(cr + cew);
          } else {
            curs++;
          }
        } else {
          if ((cl >= 1 && cr >= 1) || 
              (cl >= 1 && cew >= 1) ||
              (cew >= 1 && cr >= 1) ||
              (cew >= 2)) {
            curs += 2;
            ways *= Modint(cl * cr) + Modint(cl * cew) +
              Modint(cew * cr) + Modint(cew * (cew - 1));
          } else if (cl >= 1 || cr >= 1 || cew >= 1) {
            curs++;
            ways *= Modint(cl + cr + 2 * cew);
          }
        }
      }

      // cerr << " " << curs << " " << ways << endl;

      if (curs > maxs) {
        ans = ways;
        maxs = curs;
      } else if (curs == maxs) {
        ans += ways;
      }
    }
  }

  if (1) {
    pair<int, int> pr = make_pair(-1, -1);
    int maxl = pr.first;

    // cerr << maxl << endl;

    Modint ways (1);
    int curs = 0;
    for (int j = 1; j <= n; j++) {
      int cl = 0;
      int cr = 0;
      int cew = 0;
      int csp = 0;
      for (auto cow : groups[j]) {
        if (cow == pr) {
          csp++;
        } else if (cow.first <= maxl && cow.second <= maxl) {
          cl++;
        } else if (cow.first > maxl && cow.second > maxl) {
          cr++;
        } else if (cow.first <= maxl && cow.second > maxl) {
          cew++;
        }
      }

      // cerr << cl << " " << cr << " " << cew << " " << csp << endl;
      
      if (csp) {
        if (cr + cew >= 1) {
          curs += 2;
          ways *= Modint(cr + cew);
        } else {
          curs++;
        }
      } else {
        if ((cl >= 1 && cr >= 1) || 
            (cl >= 1 && cew >= 1) ||
            (cew >= 1 && cr >= 1) ||
            (cew >= 2)) {
          curs += 2;
          ways *= Modint(cl * cr) + Modint(cl * cew) +
            Modint(cew * cr) + Modint(cew * (cew - 1));
        } else if (cl >= 1 || cr >= 1 || cew >= 1) {
          curs++;
          ways *= Modint(cl + cr + 2 * cew);
        }
      }
    }

    // cerr << " " << curs << " " << ways << endl;
    
    if (curs > maxs) {
      ans = ways;
      maxs = curs;
    } else if (curs == maxs) {
      ans += ways;
    }
  }

  if (maxs == 0) ans = Modint(1);

  cout << maxs << " " << ans << endl;
}