#include <iostream>
#include <vector>

using namespace std;

int main () {
  int slimec;
  cin >> slimec;

  vector<int> ans (0);
  for (int i = 30; i >= 0; i--) {
    if (slimec & 1 << i) {
      ans.push_back(i + 1);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}