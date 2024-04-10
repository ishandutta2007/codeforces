#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [2][MAX_N];
int is_fk [MAX_N]; // <c, c + 1>

int cnt_fk;
void upd_ok (int k) {
  cnt_fk -= is_fk[k];

  is_fk[k] = 0;
  if (arr[0][k] && arr[1][k]) is_fk[k] = 1;
  if (arr[0][k] && arr[1][k + 1]) is_fk[k] = 1;
  if (arr[1][k] && arr[0][k + 1]) is_fk[k] = 1;
  if (arr[0][k] && arr[1][k + 1]) is_fk[k] = 1;

  cnt_fk += is_fk[k];
}

int main () {
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < q; i++) {
    int r, c;
    cin >> r >> c;
    r--;

    arr[r][c] = !arr[r][c];
    upd_ok(c);
    upd_ok(c - 1);

    cout << (cnt_fk == 0 ? "Yes" : "No") << '\n';
  }
}