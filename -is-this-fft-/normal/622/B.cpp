#include <iostream>
#include <string>

using namespace std;

int main () {
  string cltime;
  cin >> cltime;
  
  int hours = 0, minutes = 0;
  hours = 10 * (cltime[0] - '0') + cltime[1] - '0';
  minutes = 10 * (cltime[3] - '0') + cltime[4] - '0';

  int incr;
  cin >> incr;

  minutes += incr;
  hours += minutes / 60;
  minutes %= 60;
  hours %= 24;

  string ans = "";
  ans += hours / 10 + '0';
  ans += hours % 10 + '0';
  ans += ':';
  ans += minutes / 10 + '0';
  ans += minutes % 10 + '0';

  cout << ans << endl;
}