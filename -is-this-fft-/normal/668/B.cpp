#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;

int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, qc;
  cin >> n >> qc;

  ll eadd = 0, oadd = 0;
  bool swp = false;

  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;

      eadd += x;
      oadd += x;

      if (x % 2 != 0) {
        swp = !swp;
      }
    } else {
      if (!swp) {
        eadd++;
        oadd--;
      } else {
        eadd--;
        oadd++;
      }
      
      swp = !swp;
    }
  }

  for (int i = 0; i < n; i++) {
    ll pos = i;
    if (i % 2 == 0) {
      pos += eadd;
    } else {
      pos += oadd;
    }

    pos %= n;
    pos += n;
    pos %= n;

    ans[pos] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
}