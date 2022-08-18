#include <iostream>

using namespace std;

int main () {
  int start, period, fav;
  cin >> start >> fav >> period;
  
  if (((fav < start) && (period > 0)) || ((fav > start) && (period < 0))) {
    cout << "NO" << endl;
  } else if (period == 0) {
      if (fav == start) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
  } else {
    if (period < 0) {
      start *= -1;
      period *= -1;
      fav *= -1;
    }

    if (((start % period) + period) % period == ((fav % period) + period) % period) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}