#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

class SetStructure {
  map<int, int> ends;
  
public:
  SetStructure (int len, int init) {
    ends[len] = init;
  }

  void add (int l, int r, int id) {
    if (!ends.count(l)) {
      ends[l] = get(l);
    }

    // delete all elements from the map that are in (l...r]
    ends.erase(ends.upper_bound(l), ends.upper_bound(r));
    ends[r] = id;
  }

  int get (int x) {
    return ends.upper_bound(x)->second;
  }
};

const int MAX_N = 1e5 + 5;

ll L [MAX_N];
ll cuml [MAX_N];

ll to_end [MAX_N];
// time to end if you start at the beginning of the green light at the i-th

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, G, R;
  cin >> n >> G >> R;

  for (int i = 0; i <= n; i++) {
    cin >> L[i];
  }

  cuml[0] = L[0];
  for (int i = 1; i <= n; i++) {
    cuml[i] = cuml[i - 1] + L[i];
  }

  int M = G + R;
  SetStructure doms (M, n);
  for (int i = n - 1; i >= 0; i--) {
    ll s = (G - cuml[i]) % M;
    if (s < 0) s += M;

    ll f = (-cuml[i]) % M;
    if (f < 0) f += M;
    
    int dom = doms.get(f);
    to_end[i] = cuml[dom] - cuml[i];
    if (dom != n) {
      ll add = (-to_end[i]) % M;
      if (add < 0) add += M;
      to_end[i] += add;
      to_end[i] += to_end[dom];
    }

    if (s < f) {
      doms.add(s, f, i);
    } else {
      doms.add(s, M, i);
      doms.add(0, f, i);
    }
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int x;
    cin >> x;

    int dom = doms.get(x % M);
    ll ans = x + cuml[dom];
    if (dom != n) {
      ll add = (-ans) % M;
      if (add < 0) add += M;
      ans += add;
      ans += to_end[dom];
    }

    cout << ans << '\n';
  }
}