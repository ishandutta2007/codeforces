#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1005;

int a [maxn], x [maxn];

int main () {
  int length;
  cin >> length;

  for (int i = 1; i <= length; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= length; i++) {
    x[i] = a[i] - a[i - 1];
  }

  vector<int> ans;
  for (int k = 1; k <= length; k++) {
    bool flag = true;
    for (int i = 1; i + k <= length; i++) {
      if (x[i] != x[i + k]) {
        flag = false;
      }
    }
    if (flag) {
      ans.push_back(k);
    }
  }

  cout << (int) ans.size() << '\n';

  for (int v : ans) {
    cout << v << " ";
  }
  cout << '\n';
}