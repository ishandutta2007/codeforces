#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Peak {
  int pos;
  ll val;

  Peak () {
  }

  Peak (int _pos, ll _val) : pos(_pos), val(_val) {}

  ll eval (int x, ll c) {
    return val - c * (ll) abs(pos - x);
  }
};

bool operator< (Peak p, Peak q) {
  return p.pos < q.pos;
}

const int MAX_B = 18;

struct Piecewise {
  ll xi;
  vector<Peak> peaks;

  void add (Peak p) {
    while (!peaks.empty() && p.eval(peaks.back().pos, xi) > peaks.back().val) {
      peaks.pop_back();
    }

    if (peaks.empty() || peaks.back().eval(p.pos, xi) < p.val) {
      peaks.push_back(p);
    }
  }

  ll eval (int x) {
    // find the greatest i s.t. peaks[i].pos < x
    int ans = 0;
    for (int k = 1 << MAX_B; k != 0; k /= 2) {
      if (ans + k < (int) peaks.size() && peaks[ans + k].pos < x) {
        ans += k;
      }
    }

    ll val = peaks[ans].eval(x, xi);
    if (ans + 1 < (int) peaks.size()) {
      val = max(val, peaks[ans + 1].eval(x, xi));
    }
    return val;
  }
};

struct Ladder {
  int a, b, d, h;
};

const int MAX_N = 1e5 + 5;

vector<Ladder> ladders [MAX_N];
Piecewise fn [MAX_N];

void solve () {
  int n, m, K;
  cin >> n >> m >> K;

  for (int i = 1; i <= n; i++) {
    ladders[i].clear();
  }

  for (int i = 1; i <= n; i++) {
    cin >> fn[i].xi;
  }
  
  for (int i = 0; i < K; i++) {
    Ladder l;
    int c;
    cin >> l.a >> l.b >> c >> l.d >> l.h;
    ladders[c].push_back(l);
  }

  fn[1].peaks = vector<Peak> (1, Peak(1, 0));
  for (int i = 2; i <= n; i++) {
    vector<Peak> peaks;
    for (auto lad : ladders[i]) {
      if (fn[lad.a].peaks.empty()) continue;
      peaks.push_back(Peak(lad.d, fn[lad.a].eval(lad.b) + lad.h));
    }
    
    sort(peaks.begin(), peaks.end());

    fn[i].peaks.clear();
    for (auto peak : peaks) {
      fn[i].add(peak);
    }
  }
  
  if (fn[n].peaks.empty()) {
    cout << "NO ESCAPE" << '\n';
    return;
  }
  cout << -fn[n].eval(m) << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}