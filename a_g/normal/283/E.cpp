#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// stores 0/1 values
// flip on segment, query number of flips on a prefix or suffix
class segtree {
  public:
    vector<int> lazy;
    vector<int> segsum;
    int n;
    segtree (int n): n(n) {
      lazy.resize(4*n, 0);
      segsum.resize(4*n, 0);
    }

    int realsum(int v, int tl, int tr) {
      if (lazy[v]) return (tr-tl+1)-segsum[v];
      else return segsum[v];
    }
    void push(int v, int tl, int tr) {
      if (!lazy[v]) return;
      segsum[v] = segsum[v] = (tr-tl+1) - segsum[v];
      lazy[2*v+1] ^= 1;
      lazy[2*v+2] ^= 1;
      lazy[v] = 0;
    }
    void flip(int l, int r) {
      flip(0, 0, n-1, l, r);
    }
    void flip(int v, int tl, int tr, int l, int r) {
      if (l == tl && r == tr) {
        lazy[v] ^= 1;
        return;
      }
      if (l > r) return;
      push(v, tl, tr); 
      int tm = (tl+tr)/2;
      flip(2*v+1, tl, tm, l, min(r, tm));
      flip(2*v+2, tm+1, tr, max(l, tm+1), r);
      segsum[v] = realsum(2*v+1, tl, tm) + realsum(2*v+2, tm+1, tr);
    }

    int query(int l, int r) {
      return query(0, 0, n-1, l, r);
    }
    int query(int v, int tl, int tr, int l, int r) {
      if (l == tl && r == tr) {
        return realsum(v, tl, tr);
      }
      if (l > r) return 0;
      push(v, tl, tr);
      int tm = (tl+tr)/2;
      return query(2*v+1, tl, tm, l, min(r, tm)) + query(2*v+2, tm+1, tr, max(l, tm+1), r);
    }

    void debug(int v, int tl, int tr) {
      cout << v << " " << tl << " " << tr << " " << lazy[v] << " " << segsum[v] << '\n';
      if (tl != tr) {
        int tm = (tl+tr)/2;
        debug(2*v+1, tl, tm);
        debug(2*v+2, tm+1, tr);
      }
    }
    void debug() {
      debug(0, 0, n-1);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  ll ans = (1LL * n * (n-1) * (n-2)) / 6;
  vector<int> skills(n);
  for (int i = 0; i < n; i++) {
    cin >> skills[i];
  }
  sort(skills.begin(), skills.end());
  vector<vector<pair<int, int>>> events(n);
  segtree s(n);

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    int l = lower_bound(skills.begin(), skills.end(), a) - skills.begin();
    int r = upper_bound(skills.begin(), skills.end(), b) - skills.begin()-1;
    if (r-l > 0) {
      events[l].push_back({l, r});
      if (r+1 < n) events[r+1].push_back({l, r});
    }
  }

  for (int i = 0; i < n; i++) {
    for (pair<int, int> p: events[i]) {
      s.flip(p.first, p.second);
    }
    int wins = (i - s.query(0, i-1)) + (s.query(i+1, n-1));
    ans -= (1LL * wins * (wins-1))/2;
  }

  cout << ans << endl;
}