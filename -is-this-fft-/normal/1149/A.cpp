#include <iostream>

using namespace std;

int main () {
  int tilec;
  cin >> tilec;

  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < tilec; i++) {
    int x;
    cin >> x;
    if (x == 1) cnt1++;
    else cnt2++;
  }

  if (cnt1 >= 1 && cnt2 >= 1) {
    cout << 2 << " ";
    cnt2--;
    cout << 1 << " ";
    cnt1--;
  }

  while (cnt2 > 0) {
    cout << 2 << " ";
    cnt2--;
  }

  while (cnt1 > 0) {
    cout << 1 << " ";
    cnt1--;
  }
  cout << endl;
}