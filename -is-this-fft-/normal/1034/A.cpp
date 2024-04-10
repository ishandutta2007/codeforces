#include <iostream>

using namespace std;

const int MAX_N = 3e5 + 5;
const int MAX_P = 1e7 + 5e6 + 10;

int factor [MAX_P];
int vis [MAX_P];

void proc (int x) {
  while (x != 1) {
    int p = factor[x];
    int pp = 1;
    while (x % p == 0) {
      pp *= p;
      vis[pp]++;
      x /= p;
    }
  }
}

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  for (int i = 2; i < MAX_P; i++) {
    if (factor[i] == 0) {
      for (int j = i; j < MAX_P; j += i) {
        factor[j] = i;
      }
    }
  }
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    proc(arr[i]);
  }

  int ans = n;
  for (int i = 2; i < MAX_P; i++) {
    if (vis[i] != n) {
      ans = min(ans, n - vis[i]);
    }
  }

  if (ans == n) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}