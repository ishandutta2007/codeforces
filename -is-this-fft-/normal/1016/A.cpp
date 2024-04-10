#include <iostream>

using namespace std;

typedef long long llong;

llong height;
pair<llong, llong> dc (llong num) {
  return make_pair(num / height, num % height);
}

int main () {
  llong dayc;
  cin >> dayc >> height;

  llong last = 0;
  for (int i = 0; i < dayc; i++) {
    llong today;
    cin >> today;
    
    llong cur = last + today;

    cout << dc(cur).first - dc(last).first << " ";
    last = cur;
  }
  cout << endl;
}