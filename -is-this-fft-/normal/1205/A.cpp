#include <iostream>
#include <vector>

using namespace std;

int other (int x) {
  if (x % 2 == 0) {
    return x - 1;
  } else {
    return x + 1;
  }
}

int main () {
  int length;
  cin >> length;

  if (length % 2 == 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;

    vector<int> ans (0);
    for (int i = 3; i <= 2 * length; i += 4) {
      ans.push_back(i);
      ans.push_back(i + 3);
    }
    ans.push_back(1);

    for (int u : ans) {
      cout << u << " ";
    }
    for (int u : ans) {
      cout << other(u) << " ";
    }
    cout << endl;
  }
}