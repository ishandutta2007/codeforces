#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

struct Query {
  int type, l, r, x;
};

const int MAX_N = 5e3 + 5;
const int MAX_V = 1000'000'000;

int arr [MAX_N];
int add [MAX_N];
Query qs [MAX_N];

int chk [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    arr[i] = MAX_V;
  }

  for (int i = 0; i < m; i++) {
    cin >> qs[i].type >> qs[i].l >> qs[i].r >> qs[i].x;

    if (qs[i].type == 1) {
      for (int j = qs[i].l; j <= qs[i].r; j++) {
        add[j] += qs[i].x;
      }
    } else {
      for (int j = qs[i].l; j <= qs[i].r; j++) {
        arr[j] = min(arr[j], qs[i].x - add[j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    chk[i] = arr[i];
  }

  for (int i = 0; i < m; i++) {
    if (qs[i].type == 1) {
      for (int j = qs[i].l; j <= qs[i].r; j++) {
        chk[j] += qs[i].x;
      }
    } else {
      int mx = -MAX_V;
      for (int j = qs[i].l; j <= qs[i].r; j++) {
        mx = max(mx, chk[j]);
      }
      if (mx != qs[i].x) {
        failure();
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}