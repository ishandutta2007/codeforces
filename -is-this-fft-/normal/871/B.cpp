#include <iostream>
#include <vector>

using namespace std;

int query (int i, int j) {
  cout << "? " << i << " " << j << endl;

  int resp;
  cin >> resp;

  if (resp == -1) exit(0);
  return resp;
}

bool check (int n, const vector<int> &px, const vector<int> &qx, int x) {
  for (int pi : px) {
    if ((pi ^ x) >= n) return false;
  }

  for (int qi : qx) {
    if ((qi ^ x) >= n) return false;
  }

  for (int i = 0; i < n; i++) {
    if ((px[qx[i] ^ x] ^ x) != i) {
      return false;
    }
  }

  return true;
}

int main () {
  int n;
  cin >> n;

  int i0;
  vector<int> qx (n);
  for (int i = 0; i < n; i++) {
    qx[i] = query(0, i);
    if (qx[i] == 0) {
      i0 = i;
    }
  }

  vector<int> px (n);
  for (int i = 0; i < n; i++) {
    px[i] = query(i, i0);
  }

  int ans = 0, ansx;
  for (int x = 0; x < 1 << 13; x++) {
    if (check(n, px, qx, x)) {
      ans++;
      ansx = x;
    }
  }

  cout << "!" << endl;
  cout << ans << endl;
  for (int u : px) {
    cout << (ansx ^ u) << " ";
  }
  cout << endl;
}