#include <iostream>
#include <deque>
#include <assert.h>

using namespace std;

typedef long long llong;

int main () {
  llong length;
  cin >> length;

  deque<llong> arr (length);
  llong mx = -1, mn = 200000;
  for (llong i = 0; i < length; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
    mn = min(mn, arr[i]);
  }
  deque<llong> iarr = arr;
  
  if (mx == mn) {
    if (mx == 0) {
      cout << "YES" << endl;
      for (llong i = 0; i < length; i++) {
        cout << 1 << " ";
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
        return 0;
  }

    llong cycc = 0;
    while (!(arr[length - 1] == mx && arr[length - 2] != mx)) {
      cycc++;
      llong pb = arr[0];
      arr.push_back(pb);
      arr.pop_front();
    }

    bool zeros = false;
    for (llong i = length - 2; i >= 0; i--) {
      if (arr[i] == 0 && !zeros) {
        arr[i] = arr[i + 1];
        zeros = true;
      }
      arr[i] += arr[i + 1];
    }


    for (llong i = 0; i < cycc; i++) {
      llong pb = arr.back();
      arr.push_front(pb);
      arr.pop_back();
    }
    
    cout << "YES" << endl;
    for (llong i = 0; i < length; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
}