#include <iostream>
#include <vector>

const int MAX_CITY = 1005;

using namespace std;


int main () {
  int cityc, roadc;
  cin >> cityc >> roadc;

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  vector<int> others;
  for (int i = 1; i <= cityc; i++) {
    if (i != a && i != b && i != c && i != d) {
      others.push_back(i);
    }
  }

  if (roadc <= cityc) {
    cout << -1 << endl;
  } else if (cityc == 4) {
    cout << -1 << endl;
  } else if (cityc == 5) {
    cout << a << " " << c << " " << others[0] << " " << d << " " << b << endl;
    cout << c << " " << a << " " << others[0] << " " << b << " " << d << endl;
  } else {
    cout << a << " ";
    for (int i = 2; i < (int) others.size(); i++) {
      cout << others[i] << " ";
    }
    cout << others[0] << " " 
         << c << " " 
         << others[1] << " "
         << d << " "
         << b << endl;

    cout << c << " ";
    cout << others[0] << " ";
    for (int i = (int) others.size() - 1; i >= 2; i--) {
      cout << others[i] << " ";
    }
    cout << a << " "
         << others[1] << " "
         << b << " "
         << d << endl;
  }
}