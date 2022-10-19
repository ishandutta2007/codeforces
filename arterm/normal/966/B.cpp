#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 300300;

int n, x, y;
pair<int, int> c[M];
vector<int> ansx, ansy;

void read() {
  cin >> n >> x >> y;
  for (int i = 0; i < n; ++i) {
    cin >> c[i].first;
    c[i].second = i;
  }
}

int up(int x, int y) {
  return (x + y - 1) / y;
}

bool solve() {
  for (int i = n - 1; i >= 0; --i) {
    int sz = up(x, c[i].first);
    if (i + sz < n) {
      int szy = up(y, c[i + sz].first);
      if (i + sz + szy <= n) {
        for (int j = i; j < i + sz; ++j)
          ansx.push_back(c[j].second);
        for (int j = i + sz; j < i + sz + szy; ++j)
          ansy.push_back(c[j].second);
        return true;
      }
    }
  }
  return false;
}

void kill() {
  sort(c, c + n);
  if (solve()) {

  } else {
    swap(x, y);
    solve();
    swap(x, y);
    swap(ansx, ansy);
  }

  if (ansx.empty()) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
  cout << ansx.size() << " " << ansy.size() << "\n";
  for (int x : ansx)
    cout << x + 1 << " ";
  cout << endl;
  for (int y : ansy)
    cout << y + 1 << " ";
  cout << endl;
}


int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);
  read();
  kill();

}