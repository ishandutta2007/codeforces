#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int a[200000];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  vector <int> ind(n, -1);
  vector <pair <int, int> > e;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      ind[p] = i;
      a[p] = x;
    } else {
      int x;
      cin >> x;
      e.push_back({i, x});
    }
  }
  for (int i = (int) e.size() - 2; i >= 0; i--) {
    e[i].second = max(e[i].second, e[i + 1].second);
  }
  for (int i = 0; i < n; i++) {
    int id = lower_bound(e.begin(), e.end(), make_pair(ind[i], -1)) - e.begin();
    if (id < (int) e.size()) {
      a[i] = max(a[i], e[id].second);
    }
    cout << a[i] << ' ';
  }
  cout << endl;
}