#include <iostream>

using namespace std;

typedef long long ll;
 
const int MAX_N = 2e5 + 5;

ll a [MAX_N];
ll b [MAX_N];
ll x [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      x[i] = 0;
    } else {
      x[i] = max(x[i - 1], a[i - 1]);
    }

    a[i] = b[i] + x[i];
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}