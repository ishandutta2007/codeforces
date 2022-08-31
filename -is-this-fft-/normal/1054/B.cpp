#include <iostream>
#include <set>

using namespace std;

int main () {
  set<int> vis;
  vis.insert(-1);

  int length;
  cin >> length;

  for (int i = 1; i <= length; i++) {
    int x;
    cin >> x;

    if (vis.count(x - 1) == 0) {
      cout << i << endl;
      return 0;
    }
    vis.insert(x);
  }

  cout << -1 << endl;
}