#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int length;
  cin >> length;
  
  long long ans = 0;
  int smallodd = 1023456789;
  for (int i = 0; i < length; i++) {
    int num;
    cin >> num;
    if (num % 2 == 1) {
      smallodd = min(num, smallodd);
    }
    ans += num;
  }

  if (ans % 2 == 1) {
    ans -= smallodd;
  }
 
  cout << ans << endl;
}