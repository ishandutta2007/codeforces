#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 200005;

class Fenwick {
  vector<ll> tree;
  
public:
  Fenwick () : Fenwick(MAX_N) {}
  
  Fenwick (int _length) {
    tree = vector<ll> (_length);
  }
  
  void add (int idx, ll val) {
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  ll get (int idx) {
    ll sum = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

  ll range (int l, int r) {
    if (r < l) return 0;
    return get(r) - get(l - 1);
  }
};

int x [MAX_N];
int y [MAX_N];
vector<int> atY [MAX_N];
int xCnt [MAX_N];
Fenwick fenwick;

void addX (int x) {
  xCnt[x]++;
  if (xCnt[x] == 1) {
    fenwick.add(x, 1);
  }
}

void delX (int x) {
  xCnt[x]--;
  if (xCnt[x] == 0) {
    fenwick.add(x, -1);
  }
}

ll pairc (ll x) {
  return x * (x + 1) / 2;
}

int main () {
  int pointc;
  cin >> pointc;

  map<int, int> xCompr;
  map<int, int> yCompr;
  for (int i = 0; i < pointc; i++) {
    cin >> x[i] >> y[i];

    xCompr[x[i]] = 0;
    yCompr[y[i]] = 0;
  }

  int curX = 1;
  for (auto it = xCompr.begin(); it != xCompr.end(); it++) {
    it->second = curX;
    curX++;
  }

  int curY = 1;
  for (auto it = yCompr.begin(); it != yCompr.end(); it++) {
    it->second = curY;
    curY++;
  }

  for (int i = 0; i < pointc; i++) {
    x[i] = xCompr[x[i]];
    y[i] = yCompr[y[i]];
  }

  for (int i = 0; i < pointc; i++) {
    atY[y[i]].push_back(x[i]);
    addX(x[i]);
  }

  ll ans = pairc(fenwick.range(1, curX));

  // cout << ans << endl;
  for (int y = 1; y < curY; y++) {
    if (!atY[y].empty()) {
      sort(atY[y].begin(), atY[y].end());
      for (int x : atY[y]) {
        delX(x);
      }
      ans += pairc(fenwick.range(1, curX));
      // cout << " " << ans << " ";
      ans -= pairc(fenwick.range(1, atY[y][0] - 1));
      for (int i = 0; i < (int) atY[y].size() - 1; i++) {
        ans -= pairc(fenwick.range(atY[y][i] + 1, atY[y][i + 1] - 1));
        // cout << ans << " ";
      }
      ans -= pairc(fenwick.range(atY[y].back() + 1, curX));
      // cout << ans << endl;
    }
    // cout << y << " " << ans << endl;
  }
  cout << ans << endl;
}