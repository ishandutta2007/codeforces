#include <iostream>
#include <map>

using namespace std;

int main () {
  map<int, int> cnt;

  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    int num;
    cin >> num;

    if (cnt.find(num) == cnt.end()) {
      cnt[num] = 1;
    } else {
      cnt[num]++;
    }
  }

  int ans = length;
  ans -= cnt.begin()->second;
  ans -= cnt.rbegin()->second;
  cout << max(ans, 0) << endl;
}