#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, qc;
  cin >> n >> qc;

  map<int, ll> special;
  ll specsum = 0, glob = 0;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;

    special[i] = x;
    specsum += x;
  }

  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int pos;
      ll val;
      cin >> pos >> val;

      if (special.count(pos)) {
        specsum -= special[pos];
      }
      special[pos] = val;
      specsum += val;
    } else {
      ll val;
      cin >> val;

      special.clear();
      specsum = 0;
      glob = val;
    }

    cout << specsum + (ll) (n - special.size()) * glob << '\n';
  }
}