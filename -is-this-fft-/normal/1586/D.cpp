#include <iostream>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> ans (n);
  ans[n - 1] = 0;
  for (int i = 2; i <= n; i++) {
    cout << "? ";
    for (int j = 0; j < n - 1; j++) {
      cout << i << " ";
    }
    cout << 1 << endl;

    int resp;
    cin >> resp;
    resp--;

    if (resp == -1) {
      continue;
    }
    ans[resp] = -i + 1;
  }

  for (int i = 2; i <= n; i++) {
    cout << "? ";
    for (int j = 0; j < n - 1; j++) {
      cout << 1 << " ";
    }
    cout << i << endl;

    int resp;
    cin >> resp;
    resp--;

    if (resp == -1) {
      continue;
    }
    ans[resp] = i - 1;
  }

  int mn = 0;
  for (int i = 0; i < n; i++) {
    mn = min(mn, ans[i]);
  }

  cout << "!";
  for (int i = 0; i < n; i++) {
    cout << " " << ans[i] - mn + 1;
  }
  cout << endl;
}