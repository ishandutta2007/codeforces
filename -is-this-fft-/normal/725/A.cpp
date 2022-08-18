#include <iostream>
#include <string>

using namespace std;

int main () {
  int length;
  cin >> length;

  string arr;
  cin >> arr;

  int ans = 0;
  for (int i = 0; i < (int) arr.size(); i++) {
    if (arr[i] == '<') {
      ans++;
    } else {
      break;
    }
  }

  for (int i = (int) arr.size() - 1; i >= 0; i--) {
    if (arr[i] == '>') {
      ans++;
    } else {
      break;
    }
  }

  cout << ans << endl;
}