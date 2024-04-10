#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
int dif [MAX_N];

ll contrib (ll pos, ll n) {
  return dif[pos] * pos * (n - pos);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) {
      dif[i] = 1;
    }
  }

  ll ans = ((ll) n * (ll) (n + 1)) / 2;
  for (int i = 0; i < n; i++) {
    ans += contrib(i, n);
  }

  for (int i = 0; i < qc; i++) {
    int pos, val;
    cin >> pos >> val;
    pos--;

    arr[pos] = val;
    if (pos != 0) {
      ans -= contrib(pos, n);
      dif[pos] = arr[pos] != arr[pos - 1];
      ans += contrib(pos, n);
    }
    
    if (pos != n - 1) {
      ans -= contrib(pos + 1, n);
      dif[pos + 1] = arr[pos + 1] != arr[pos];
      ans += contrib(pos + 1, n);
    }

    cout << ans << '\n';
  }
}