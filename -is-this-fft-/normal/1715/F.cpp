#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ld;

ld ask (vector<pair<ld, ld>> polygon) {
  cout << "? " << (int) polygon.size() << '\n';
  for (auto p : polygon) {
    cout << fixed << setprecision(14) << p.first << " " << p.second << '\n';
  }
  cout.flush();

  ld ans;
  cin >> ans;
  return ans;
}

const ld EPS = 1e-10;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<pair<ld, ld>> H;
  for (int i = 0; i < m; i++) {
    H.push_back({0, i});
    if (i != 0) {
      H.back().first += EPS;
    }

    H.push_back({n, i});
  }
  H.push_back({0, m});

  ld hA = ask(H);
  hA *= 2 * n;
  hA += 1;
  hA /= 2;
  hA = n - hA;

  vector<pair<ld, ld>> V;
  for (int i = 0; i < n; i++) {
    V.push_back({i, 0});
    if (i != 0) {
      V.back().first += EPS;
    }

    V.push_back({i, m});
  }
  V.push_back({n, 0});

  ld vA = ask(V);
  vA *= 2 * m;
  vA += 1;
  vA /= 2;
  vA = m - vA;

  cout << "! " << fixed << setprecision(12) << hA << " " << vA << endl;
}