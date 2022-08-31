#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main () {
  int length;
  cin >> length;

  vector<int> arr;
  set<int> used;
  for (int i = 0; i < length; i++) {
    int x;
    cin >> x;
    if (used.count(x) == 0) {
      used.insert(x);
      arr.push_back(x);
    }
  }

  int ans = 0;
  for (int i = 0; i < (int) arr.size(); i++) {
    bool base = true;
    for (int j = 0; j < (int) arr.size(); j++) {
      if (arr[j] < arr[i]) {
        if (arr[i] % arr[j] == 0) {
          base = false;
        }
      }
    }
    if (base) ans++;
  }

  cout << ans << endl;
}